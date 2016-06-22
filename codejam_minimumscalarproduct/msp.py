def scalar(v1,v2,n):
	scalar = 0
	for i in xrange(n):
		scalar += v1[i] * v2[n-(i+1)]
	return scalar
if __name__ == "__main__":
	t = input()	
	count = 1
	while(count<=t):
		result = 9999999999999999
		n = input()
		v1 = map(int,raw_input().split())
		v2 = map(int,raw_input().split())						
		v1.sort()
		v2.sort()
		result = scalar(v1,v2,n)
		print "Case #{}: {}".format(count,result)
		count += 1