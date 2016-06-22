import sys
if __name__ == "__main__":
	n = input()
	count = 1
	while(count<=n):
		words = raw_input().split()
		sys.stdout.write("Case #{}: ".format(count))
		for i in xrange(len(words)):			
			sys.stdout.write(words[len(words) - (i+1)])
			if i != len(words)-1:
				sys.stdout.write(" ")
		sys.stdout.write("\n")
		count += 1