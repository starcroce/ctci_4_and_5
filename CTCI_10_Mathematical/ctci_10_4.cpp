#include <iostream>
using namespace std;

int ERROR = ~(1<<31);

int newNegate(int a){
	int d = a<0? 1:-1;
	int ng = 0;
	while(a != 0){
		a += d;
		ng += d;
	}
	return ng;
}

int newMinus(int a, int b){
	return a+newNegate(b);
}

int newAbs(int a){
	if(a < 0)
		a = newNegate(a);
	return a;
}

int newTimes(int a, int b){
	int aa = newAbs(a), ab = newAbs(b);
	if(aa < ab)
		return newTimes(b, a);
	int res = 0;
	for(int i=0; i<ab; i++)
		res += a;
	if(b < 0)
		res = newNegate(res);
	return res;
}

bool diffSign(int a, int b){
	return (a>0 && b<0) || (a<0 && b>0);
}

int newDivide(int a, int b){
	if(b == 0)
		return ERROR;
	int aa = newAbs(a), ab = newAbs(b);
	int res = 0;
	for(; (aa -= ab)>=0; res++);
	if(diffSign(a, b))
		res = newNegate(res);
	return res;
}

int main(){
	int a[] = {8, 0, -8, -5, 9};
	int b[] = {3, 5, 3, 0, -3};
	for(int i=0; i<5; i++){
		cout<<newMinus(a[i], b[i])<<" "<<newTimes(a[i], b[i])<<" "<<newDivide(a[i], b[i])<<endl;
	}
	return 0;
}