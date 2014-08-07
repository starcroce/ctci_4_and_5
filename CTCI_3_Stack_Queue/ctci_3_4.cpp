#include <iostream>
#include <stack>
using namespace std;

// plate from begin to end on src, need to move to end, can use bridge
struct op {
	int begin, end;
	char src, bri, dst;
	op() {}
	op(int pbegin, int pend, int psrc, int pbri, int pdst): begin(pbegin), end(pend), src(psrc), bri(pbri), dst(pdst) {}
};

void hanoi(int n, char src, char bri, char dst) {
	stack<op> s;
	op tmp;
	s.push(op(1, n, src, bri, dst));
	while(!s.empty()) {
		tmp = s.top();
		s.pop();
		if(tmp.begin != tmp.end) {
			s.push(op(tmp.begin, tmp.end-1, tmp.bri, tmp.src, tmp.dst));
			s.push(op(tmp.end, tmp.end, tmp.src, tmp.bri, tmp.dst));
			s.push(op(tmp.begin, tmp.end-1, tmp.src, tmp.dst, tmp.bri));
		} else {
            cout<<"Move disk "<<tmp.begin<<" from "<<tmp.src<<" to "<<tmp.dst<<endl;
        }
	}
}

// move n plates from src to dst, can use bridge
// (1~n, 0, 0) => (n, 1~n-1, 0) => (0, 1~n-1, n) => (0, 0, 1~n)
void hanoi_recursive(int n, char src, char bri, char dst) {
	if(n == 1) {
		cout<<"Move disk "<<n<<" from "<<src<<" to "<<dst<<endl;
	}
	else {
		// based on the above 3 steps
		hanoi_recursive(n-1, src, dst, bri);
		cout<<"Move disk "<<n<<" from "<<src<<" to "<<dst<<endl;
		hanoi_recursive(n-1, bri, src, dst);
	}
}

int main() {
    int n = 3;
    hanoi(n, 'A', 'B', 'C');
    cout<<endl;
    hanoi_recursive(n, 'A', 'B', 'C');
    return 0;
}