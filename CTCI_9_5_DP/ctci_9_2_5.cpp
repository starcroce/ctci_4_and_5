int pathNum(vector<vector<int> > &grid) {
	if(grid.size() == 0) {
		return 0;
	}
	int row = grid.size();
	int col = grid[0].size();
	int path[row][col];
	for(int i = 0; i < col; i++) {
		path[0][i] = 0;
	}
	for(int i = 1; i < row; i++) {
		path[i][0] = 0;
	}
	for(int i = 1; i < row; i++) {
		for(int j = 1; j < col; j++) {
			path[i][j] = path[i-1][j] + path[i][j-1];
		}
	}
	return path[row-1][col-1];
}