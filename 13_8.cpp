// The smart pointer class needs pointers to both the object itself and to the ref count. 
// These must be pointers, rather than the actual object or ref count value, since the goal of a smart pointer is that the reference count is tracked across multiple smart pointers to one object. 
template <class T>
class SmartPointer {
public:
	SmartPointer(T *ptr) {
		ref = ptr;
		refCount = (int *)malloc(sizeof(int));
		*refCount = 1;
	}

	// this constructor creates a new pointer pointing to an existing point
	SmartPointer(SmartPointer<T> &sptr) {
		ref = sptr.ref;
		refCount = sptr.refCount;
		(*refCount)++;
	}

	// if ref count is 0, free the memory created by the int and destory the object
	~SmartPointer(SmartPointer<T> &sptr) {
		removeRef();
	}

	// override the = operator, when set one smart pointer equal to another old smart pointer
	// the old sptr's ref count decremented and the new sptr's ref count incremented
	SmartPointer<T> & opertaor= (SmartPointer<T> &ptr) {
		if(this == &sptr) {
			return *this;
		}
		if(*refCount > 0) {
			removeRef();
		}
		ref = sptr.ref;
		refCount = sptr.refCount;
		(*refCount)++;
		return *this;
	}

	T getVale() {
		return *ref;
	}

private:
	void removeRef() {
		(*refCount)--;
		if(*refCount == 0) {
			delete ref;
			free(refCount);
			ref = NULL;
			refCount = NULL;
		}
	}

	T *ref;
	int *refCount;
};