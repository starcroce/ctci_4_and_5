def strcmp(s1, s2):
	l1 = list(s1)
	l1.sort()
	s1 = ''.join(l1)
	l2 = list(s2)
	l2.sort()
	s2 = ''.join(l2)
	return s1 < s2


def main():
	l = ['axyz', 'abc', 'yzax', 'bac', 'zyxa', 'fg', 'gf']
	l.sort()
	print l

if __name__ == '__main__':
	main()