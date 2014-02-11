// similar to leetcode climbing stairs
int climbStairs(int n) {
    vector<int> res(n, 1);
    res[1] = 2;
    res[2] = 4
    for(int i = 2; i < n; i++) {
        res[i] = res[i-1] + res[i-2] + res[i-3];
    }
    return res[n-1];
}