import copy
def getpatterntocheck(message,pos):	
	temp = ''	
	isprntss = (True if message[pos] == '(' else False)
	if isprntss: pos += 1		
	for i in xrange(pos,len(message)):		
		if message[i] == ')':			
			return i,temp,isprntss
		elif message[i] == '(':			
			return i-1,temp,isprntss
		else:
			temp += message[i]		
	return i,temp,isprntss

def checkwords(copywords,d,pattern,isprntss):
	foundmatch = 0
	if isprntss:				
		for j in xrange(d):
			if copywords[j]['flag']:
				found = 0				
				for i in xrange(len(pattern)):
					if (len(copywords[j]['value']) > 0):
						if (pattern[i] == copywords[j]['value'][0]) and copywords[j]['flag']:
							copywords[j]['value'] = copywords[j]['value'][1:]												
							found = 1
							foundmatch = 1
							break
				if not found:
					copywords[j]['flag'] = 0

	else:
		for i in xrange(d):
			if copywords[i]['flag']:			
				if (copywords[i]['value'][:len(pattern)] == pattern) and copywords[i]['flag']:
					copywords[i]['value'] = copywords[i]['value'][len(pattern):]				
					foundmatch = 1
				else:
					copywords[i]['flag'] = 0			

	return foundmatch

if __name__ == "__main__":
	l,d,n = map(int,raw_input().split())	
	copywords, words = [None]*d,[None]*d
	count = 0
	for i in xrange(d):
		w = {'value':str(raw_input()),'flag':1}		
		words[i] = w

	while(count<n):
		message = raw_input()		
		pos = 0
		wordsfound = 0
		for i in xrange(d):
			copywords[i] = copy.deepcopy(words[i])		
		while(True):
			pos, pattern, isprntss = getpatterntocheck(message,pos)							
			foundmatch = checkwords(copywords,d,pattern,isprntss)			
			if pos == len(message)-1 or foundmatch == 0: break			
			else: pos += 1
		for i in xrange(d):			
			if len(copywords[i]['value']) == 0:
				wordsfound += 1
		print "Case #{}: {}".format(count+1,wordsfound)				
		count += 1