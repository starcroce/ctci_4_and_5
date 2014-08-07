def rotate_anti_clock(matrix):
	n = len(matrix)
	# 1 5 9  13
	# 2 6 10 14
	# 3 7 11 15
	# 4 8 12 16
	for i in range(0, n):
		for j in range(i+1, n):
			matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
	# reverse the rotated matrix for counter clock
	matrix = matrix[::-1]
	return matrix

def rotate_clock(matrix):
	n = len(matrix)
	for i in range(0, n):
		for j in range(0, n-i):
			matrix[i][j], matrix[n-1-j][n-1-i] = matrix[n-1-j][n-1-i], matrix[i][j]
	matrix = matrix[::-1]
	return matrix

def main():
	# 1 2 3 4
	# 5 6 7 8
	# 9 10 11 12
	# 13 14 15 16
	matrix = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]]
	matrix = rotate_clock(matrix)
	for each in matrix:
		print each

if __name__ == '__main__':
	main()