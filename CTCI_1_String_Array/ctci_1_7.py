def setZero(matrix):
	m = len(matrix)
	n = len(matrix[0])
	row = []
	column = []
	for i in range(0, m):
		row.append(False)
	for i in range(0, n):
		column.append(False)
	for i in range(0, m):
		for j in range(0, n):
			if matrix[i][j] == 0:
				row[i] = True
				column[j] = True
	for i in range(0, m):
		for j in range(0, n):
			if row[i] or column[j]:
				matrix[i][j] = 0
	return matrix

def main():
	# 1 0 2
	# 0 1 1
	# 1 1 1
	matrix = [[1, 0, 2], [0, 1, 1], [1, 1, 1]]
	matrix = setZero(matrix)
	for each in matrix:
		print each

if __name__ == '__main__':
	main()