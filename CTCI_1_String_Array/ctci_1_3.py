def removeDuplicate(s):
	ans = []
	for i in s:
		if i not in ans:
			ans.append(i)
	return ''.join(ans)

def main():
	s1 = 'qwerty'
	s2 = 'qqqqqq'
	s3 = ''
	s4 = 'qweqwt'
	print removeDuplicate(s1)
	print removeDuplicate(s2)
	print removeDuplicate(s3)
	print removeDuplicate(s4)

if __name__ == '__main__':
	main()