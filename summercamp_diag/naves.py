if __name__ == "__main__":
	n,k = map(int,raw_input().split())
	coords = {}
	for i in xrange(n):
		coordx,coordy = raw_input().split()		
		coords[coordx+coordy] = 0
	for i in xrange(k):
		newcoordx,newcoordy = raw_input().split()
		if (newcoordx+newcoordy) in coords:
			print 0
		else:
			print 1