visited = {}
grid = []

def valid_movement(x,y,n,m):
	if (x > -1 and x < n) and (y > -1 and y < m):
		if grid[x][y] == 1 and visited[(x,y)] == False:
			return True
	return False

def next_movement(i,j,direction):	
	if direction == 0: # up		
		return i-1,j
	elif direction == 1: # down
		return i + 1, j
	elif direction == 2: # left
		return i, j - 1
	elif direction == 3: # right
		return i, j + 1
	elif direction == 4: # up left
		return i - 1, j - 1
	elif direction == 5: # up right
		return i - 1, j + 1
	elif direction == 6: # down left
		return i + 1, j - 1
	elif direction == 7: # down right
		return i + 1, j + 1

def floodfill(i,j,n,m):
	region_size = -1
	if visited[(i,j)] == False and grid[i][j] == 1:
		region_size = 0
		q = []
		q.append((i,j))
		while len(q) > 0:
			current_x,current_y = q.pop(0)				
			grid[current_x][current_y] = -1			
			region_size += 1	
			for direction in xrange(8): # 8 possible movements
				temp_x,temp_y = next_movement(current_x,current_y,direction)
				if valid_movement(temp_x,temp_y,n,m):	
					visited[(temp_x,temp_y)] = True
					q.append((temp_x,temp_y))
	return region_size

if __name__ == "__main__":
	n = input()
	m = input()

	for i in xrange(n):		
		grid.append(map(int,raw_input().strip().split()))
		for j in xrange(m):			
			visited[(i,j)] = False

	max_region = 0
	for i in xrange(n):
		for j in xrange(m):
			max_region = max(floodfill(i,j,n,m),max_region)
	print max_region