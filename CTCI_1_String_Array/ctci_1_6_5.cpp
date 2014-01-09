#include <iostream>
using namespace std;

void rotate(int a[][4], int n) {
    for (int layer = 0; layer < n / 2; layer++) {
        // get edge of each layer
        int first = layer, last = n - 1 - layer;
        for (int i = first; i < last; i++) {
            int offset = i - first;
            // save top
            int top = a[first][i];
            // left -> top
            a[first][i] = a[last - offset][first];
            // bottom -> left
            a[last - offset][first] = a[last][last - offset];
            // right -> bottom
            a[last][last - offset] = a[i][last];
            // top -> right
            a[i][last] = top;
        }
    }
}

int main() {
    int a[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 0, 1, 2},
        {3, 4, 5, 6}
    };
    rotate(a, 4);
    for(int i=0; i<4; i++){
    	for(int j=0; j<4; j++){
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
    }
    return 0;
}