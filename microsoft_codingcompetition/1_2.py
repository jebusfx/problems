import sys
if __name__ == "__main__":
	line = raw_input().split()
	d = {}	
	for elem in line:
		if elem not in d:
			d[elem[0].upper()] = elem[2].upper()
	d[' '] = ' '
	d['.'] = '.'
	d[','] = ','
	d['!'] = '!'
	d['?'] = '?'
	d['\''] = '\''
	message = raw_input()
	for c in message:
		if c.isupper():
			sys.stdout.write(d[c.upper()].upper())
		else:
			sys.stdout.write(d[c.upper()].lower())
	sys.stdout.write('\n')
