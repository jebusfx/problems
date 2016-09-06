# Enter your code here. Read input from STDIN. Print output to STDOUT
import sys

def print_solution(distances,n,root):
    for i in xrange(1,n+1):
        if i != root:                        
            sys.stdout.write(str(distances[i]))
            if i != n:
                sys.stdout.write(' ')
    sys.stdout.write('\n')

def bfs(root,nodes,distances):
    queue = []
    queue.append(root)    
    distances[root] = 0
    while(len(queue) > 0):
        current = queue.pop(0)         
        for adj_node in nodes[current]:
            if distances[adj_node] == -1:
                distances[adj_node] = distances[current] + 6
                queue.append(adj_node)
    return distances
            
if __name__ == "__main__":
    q = input()    
    while q > 0:        
        nodes = {}
        distances = {}
        n,m = map(int,raw_input().strip().split())
        for i in xrange(n+1):
            nodes[i] = []
            distances[i] = -1
        while m > 0:
            u,v = map(int,raw_input().strip().split())
            nodes[u].append(v)
            nodes[v].append(u)
            m -= 1
        root = input()
        distances = bfs(root,nodes,distances)    
        print_solution(distances,n,root)    
        q -= 1