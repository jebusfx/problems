if __name__ == "__main__":
	t = input()
	while(t > 0):
		n = input()
		positive_numbers = False
		max_cont = -100001	
		max_non_cont = -100001		
		non_contiguous = 0
		contiguous = [0 for i in xrange(n + 1)]
		for i,x in enumerate(raw_input().strip().split()):			
			x = int(x)
			i += 1			
			if x > 0:
				non_contiguous += x
				positive_numbers = True		
			contiguous[i] = max(contiguous[i - 1] + x,x)
			max_cont = max(max_cont, contiguous[i])
			max_non_cont = max(max_non_cont,x)

		if not positive_numbers:
			print '{0} {1}'.format(max_cont,max_non_cont)
		else:
			print '{0} {1}'.format(max_cont,non_contiguous)
		t -= 1