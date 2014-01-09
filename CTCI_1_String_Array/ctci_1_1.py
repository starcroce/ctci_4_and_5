def isUnique(s):
	s_list = list(s)
	s_set = set(s_list)
	len_list = len(s_list)
	len_set = len(s_set)
	return len_list == len_set

def main():
	s1 = 'i have a dream'
	s2 = 'qwertyuiop'
	print isUnique(s1), isUnique(s2)

if __name__ == '__main__':
	main()