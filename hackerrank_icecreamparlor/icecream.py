# Enter your code here. Read input from STDIN. Print output to STDOUT
def bsearch(arr,lower,upper,first_element,m):
    if lower <= upper:        
        midpoint = (lower + upper)/2                
        sum_ = arr[midpoint]['cost'] + first_element['cost']    
        if sum_ == m and first_element['id'] != arr[midpoint]['id']:
            return arr[midpoint]['id']
        elif sum_ > m:
            return bsearch(arr,lower,midpoint - 1,first_element,m)
        elif sum_ < m:
            return bsearch(arr,midpoint + 1,upper,first_element,m)
    return -1
    
if __name__ == "__main__":
    t = input()
    while t > 0:
        m = input()
        n = input()
        ice_creams = [{'id': i, 'cost': int(x)} for i,x in enumerate(raw_input().strip().split())]        
        ice_creams.sort()     
        sunny = {'id':-1,'cost':-1}
        for elem in ice_creams:
            johnny = bsearch(ice_creams,0,n - 1,elem,m)
            if johnny != -1:
                sunny = elem                
                break
                
        if johnny <= sunny['id']:
            first = johnny
            second = sunny['id']
        else:
            first = sunny['id']
            second = johnny
        print '{} {}'.format(first + 1,second + 1)
        t -= 1