import sys

alfabeto = 'abcdefghijklmnopqrstuvwxyz\''
alphabet_rank = {}
def ordena():
	for i in xrange(len(alfabeto)):
		alphabet_rank[alfabeto[i]] = i	
def string_cmp(word1,word2):
	shortest_word = (len(word1) if(len(word1) <= len(word2)) else len(word2))		
	for i in xrange(shortest_word):
		if(alphabet_rank[word1[i]] > alphabet_rank[word2[i]]):
			return 1
		elif(alphabet_rank[word1[i]] < alphabet_rank[word2[i]]):
			return -1			
	return 0

def like(list_of_adj, other):
	for adj in list_of_adj:
		for elem in other:
			if adj == elem:
				return False
	return True

if __name__ == "__main__":
	xortholians = {}
	originals = {}
	names = []
	i = 0
	for line in sys.stdin:
		if i == 0:
			name = line
			originals[name.lower().strip()] = name.strip()
			name = name.lower()
			xortholians[name] = {}
			names.append(name)
		elif i == 1:
			hats = line.split()
			xortholians[name]['hats'] = hats
		elif i == 2:
			distasteful = line.split()
			xortholians[name]['distasteful'] = distasteful			
		i = (i + 1) % 3	
	result = {}
	taken = {}
	for elem in names:		
		for elem2 in names:
			if elem2 != elem:
				if like(xortholians[elem]['distasteful'],xortholians[elem2]['hats']):
					if elem not in result and elem2 not in taken:
						result[elem] = elem2
						taken[elem2] = True
	keys = result.keys()
	ordena()
	keys.sort(cmp=string_cmp)
	for k in keys:
		print '{} {}'.format(originals[k.strip()],originals[result[k].strip()])