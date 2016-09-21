class Dish:
    def __init__(self,p,d):
        self.p = p
        self.d = d
    def __cmp__(self,other):
        i = self.p - other.d
        j = other.p - self.d
        if i < j:
            return 1
        elif i >= j:
            return -1
        return 0
        
if __name__ == "__main__":
    n,k = map(int,raw_input().strip().split())
    dishes = []
    for i in xrange(n):
        p,d = map(int,raw_input().strip().split())
        dishes.append(Dish(p,d))
    dishes.sort()
    res = 0
    if k>=n:
        for i in xrange(n):
            res += dishes[i].p
    else:
        for i in xrange(k):        
            res += dishes[i].p
        for i in xrange(k,n):
            res -= dishes[i].d
    print (0 if res < 0 else res)
    