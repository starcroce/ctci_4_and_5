# generate the initialized grid
def genGrid(row, col):
	line = []
	# generate the 1st number of each row
	line.append(1)
	for i in range(col-1):
		line.append(0)
	grid = [line for i in range(row)]
	# replace the 1st row
	newLine = []
	for i in range(col):
		newLine.append(1)
	grid[0] = newLine
	return grid

def getNumOfPath(m, n):
	# generate the grid
	grid = genGrid(100, 100)
	if(m == 1 or n == 1):
		numOfPath = 1
	elif(m > 100 or n > 100):
		numOfPath = -1
	else:
		numOfPath = getNumOfPath(m-1, n)+getNumOfPath(m, n-1)
	return numOfPath

print getNumOfPath(5, 5)