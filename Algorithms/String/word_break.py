

def findsol(l,p):
    d = dict()
    for ele in l:
        if ele not in d:
            d[ele] = 1
        else:
            d[ele]+=1
    st = ''
    final_string = ''
    for i in range(len(p)):
        st+=p[i]
        if st in d:
            final_string+=st
            st = ''
            
    if p == final_string:
        return 1
    return 0

t = int(input())
for i in range(t):
    n = input()
    l = map(str,input().strip().split())
    pat = input()
    print (findsol(l,pat))
