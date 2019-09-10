T = int(input())
dict = {'int':4,'bool':1,'char':1,'long long':8,'__int128':16,'long double':16,'float':4,'double':8}
while(T > 0):
    n = int(input())
    while(n > 0):
        n = n - 1;
        s = input().split(' ')
        for i in s:
            print(i)
