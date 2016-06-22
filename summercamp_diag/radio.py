if __name__ == "__main__":	
	RADIOSTATIONS = [540,580,980,1190,1250,1420,1520]
	freq = input()
	if freq < RADIOSTATIONS[0] or freq > RADIOSTATIONS[len(RADIOSTATIONS)-1]:
		print "error"
	else:
		for i in xrange(len(RADIOSTATIONS)-1):
			if freq == RADIOSTATIONS[i] and i != 0 and i != len(RADIOSTATIONS) - 1:
				print "atras 0"
			elif (freq > RADIOSTATIONS[i] and freq <= RADIOSTATIONS[i+1]) and RADIOSTATIONS[i+1] == RADIOSTATIONS[len(RADIOSTATIONS)-1]:
				print "atras " + str(freq - RADIOSTATIONS[i]) 
			elif (freq >= RADIOSTATIONS[i] and freq < RADIOSTATIONS[i+1]) and RADIOSTATIONS[i] == RADIOSTATIONS[0]:
				print "adelante " + str(RADIOSTATIONS[i+1] - freq)
			elif freq > RADIOSTATIONS[i] and freq < RADIOSTATIONS[i+1]:				
				midpoint = ((RADIOSTATIONS[i+1] - RADIOSTATIONS[i])/2) + RADIOSTATIONS[i]
				if freq >= midpoint:
					print "adelante " + str(RADIOSTATIONS[i+1] - freq)				
				elif freq < midpoint:
					print "atras " + str(freq - RADIOSTATIONS[i])