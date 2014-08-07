#include <iostream>
#include <vector>
using namespace std;

// similar to leetcode climbing stairs
int climbStairs_1(int n) {
    vector<int> res(n, 1);
    res[1] = 2;
    res[2] = 4;
    for(int i = 3; i < n; i++) {
        res[i] = res[i-1] + res[i-2] + res[i-3];
    }
    return res[n-1];
}

int climbStairs_2(int n) {
	int tmp1 = 1, tmp2 = 2, tmp3 = 4;
	int tmp4;
	for(int i = 4; i <= n; i++) {
		tmp4 = tmp1 + tmp2 + tmp3;
		tmp1 = tmp2;
		tmp2 = tmp3;
		tmp3 = tmp4;
	}
	return tmp4;
}

int main(int argc, char const *argv[])
{
	int n = 8;
	cout<<climbStairs_1(n)<<" "<<climbStairs_2(n)<<endl;
	return 0;
}