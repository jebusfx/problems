from heapq import heappush,nsmallest

alphabet_rank = {}

class Alien:
	def __init__(self,word):
		self.word = word

	def __cmp__(self,other):				
		shortest_word = (len(self.word) if(len(self.word) <= len(other.word)) else len(other.word))		
		for i in xrange(shortest_word):
			if(alphabet_rank[self.word[i]] > alphabet_rank[other.word[i]]):
				return 1
			elif(alphabet_rank[self.word[i]] < alphabet_rank[other.word[i]]):
				return -1			
		return 0

	def __repr__(self):
		return self.word

def ordenar_extraterrestre(desordenadas, orden_alfabeto):
	ordenada = []
	for i in xrange(len(orden_alfabeto)):
		alphabet_rank[orden_alfabeto[i]] = i	

	for i in xrange(len(desordenadas)):
		heappush(ordenada,Alien(desordenadas[i]))

	return nsmallest(len(ordenada),ordenada)

if __name__ == "__main__":

	# lista = ['miel', 'extraterrestre','creaoque', 'al', 'automovil','beale','parecebien', 'auto', 'revestir','bealo']	
	lista = ['zy','zx','zl','za','zz']
	alfabeto = 'zyxwvltsrqponaukjihgfedcbm'

	# lista = ['miel', 'extraterrestre', 'al', 'automovil', 'auto', 'revestir']
	# alfabeto = 'zyxwvutsrqponmlkjihgfedcba'

	print ordenar_extraterrestre(lista,alfabeto)
