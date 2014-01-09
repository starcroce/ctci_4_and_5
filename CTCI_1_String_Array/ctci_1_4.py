def isAnagram(s1, s2):
	if len(s1) != len(s2):
		return False
	# sorted convert a str into a sorted list
	new_s1 = ''.join(sorted(s1))
	new_s2 = ''.join(sorted(s2))
	return new_s1 == new_s2

def main():
	s1 = 'aabb'
	s2 = 'abab'
	s3 = 'aaab'
	print isAnagram(s1, s2), isAnagram(s1, s3)

if __name__ == '__main__':
	main()