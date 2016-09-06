#!/bin/python

def print_array(ar,n):
	import sys
	for j in xrange(n):
		sys.stdout.write(str(ar[j]))
		if j != n - 1:
			sys.stdout.write(' ')
	sys.stdout.write('\n')

def insertionSort(ar,n):    	
	e = ar[n - 1]
	finished = False
	i = n - 2   
	while not finished:   
		if i == -1: #reached the end of the array
			ar[0] = e			
			finished = True 
		else:
			if e > ar[i]:
				ar[i + 1] = e
				finished = True
			else: 
				ar[i + 1] = ar[i] 
		print_array(ar,n)       
		i -= 1

m = input()
ar = [int(i) for i in raw_input().strip().split()]
insertionSort(ar,m)
