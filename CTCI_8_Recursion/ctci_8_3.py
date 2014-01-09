from itertools import chain, combinations
# combination('abc', 2) --> ab, ac, bc
# chain._fromiterable('ab', 'cd') -> a, b, c, d

def powerset(iterable):
	s = list(iterable)
	return chain.from_iterable(combinations(s, r) for r in range(len(s) + 1))

def main():
	a_list = [1, 2, 3, 4]
	print map(list, powerset(a_list))

if __name__ == '__main__':
	main()