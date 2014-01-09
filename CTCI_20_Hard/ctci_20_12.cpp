#include <iostream>
#include <cstdio>
using namespace std;

// A C  x1, x2
// B D  y1, y2
// val_D = area((0, 0)->(x2, y2)), val_C = area((0, 0)->(x2, y1)),
// val_B = area((0, 0)->(x1, y2)), val_A = area((0, 0)->(x1, y1))
// area(D) = val_D - area(A & C) - area(A & B) + area(A)
//         = val_D - val_B - val_C + val_A
// value(x, y) = sum((0, 0)->(x, y)), so value(x, y) = value(x-1, y) + value(y-1, x) - value(x-1, y-1)

int area[100][100], pre[100][100];

void preCompute(int n){
	for(int i=0; i<=n; i++){
		pre[0][i] = pre[i][0] = 0;
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			pre[i][j] = pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+area[i][j];
		}
	}
}

int maxSum(int n){
	int max = 1<<31;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			int current = 0;
			for(int k=1; k<=n; k++){
				int value = pre[j][k]-pre[j][k-1]-pre[i-1][k]+pre[i-1][k-1];
				if(current <= 0)
					current = value;
				else
					current += value;
				if(current > max)
					max = current;
			}
		}
	}
	return max;
}

int main(){
	freopen("20_12.in", "r", stdin);
	int n = 4;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin>>area[i][j];
		}
	}
	preCompute(n);
	cout<<maxSum(n)<<endl;
	fclose(stdin);
	return 0;
}