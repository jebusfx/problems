rank = {}

class Alien:
	def __init__(self,word):
		self.word = word
	def __cmp__(self,other):				
		shortest_word = (len(self.word) if len(self.word) <= len(other.word) else len(other.word))		
		for i in xrange(shortest_word):
			if(rank[self.word[i]] > rank[other.word[i]]):
				return 1
			elif(rank[self.word[i]] < rank[other.word[i]]):
				return -1			
		return -1 if len(self.word) <= len(other.word) else 1
		return 0	

def ordenar_extraterrestre(desordenadas, orden_alfabeto):
	global rank
	rank = dict((x.lower(),i) for i,x in enumerate(orden_alfabeto))
	ordenadas = [Alien(word) for word in desordenadas]
	return [w.word for w in sorted(ordenadas)]	

lista = ['miel', 'extraterrestre', 'al', 'automovil', 'auto', 'revestir']
alfabeto = 'zyxwvutsrqponmlkjihgfedcba'
print ordenar_extraterrestre(lista,alfabeto)