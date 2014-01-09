def recFibo(n):
	if n == 0:
		return 0
	elif n == 1:
		return 1
	elif n > 1:
		return recFibo(n-1) + recFibo(n-2)

def iterFibo(n):
	if n == 0:
		return 0
	a = 1
	b = 1
	for i in range(3, n+1):
		c = a + b
		a, b = b, c
	return b

def main():
	for i in range(0, 20):
		print recFibo(i), 
	print 
	for i in range(0, 20):
		print iterFibo(i), 

if __name__ == '__main__':
	main()