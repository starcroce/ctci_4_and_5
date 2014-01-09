import itertools
# itertools.permutations('abc', 3) --> abc, acb, bac, bca, cab, cba

def main():
	s = 'abcd'
	for each in itertools.permutations(s, 4):
		print ''.join(each)

if __name__ == '__main__':
	main()