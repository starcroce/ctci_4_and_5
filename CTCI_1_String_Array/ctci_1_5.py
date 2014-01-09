def replace(s):
	ans = s.replace(' ', '%20')
	return ans

def main():
	s = 'i have a dream'
	ans = replace(s)
	print ans

if __name__ == '__main__':
	main()