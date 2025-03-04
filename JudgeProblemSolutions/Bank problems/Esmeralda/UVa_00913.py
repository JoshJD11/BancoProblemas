try:
    while(1):
        n = int(input())
        r = ((1 + (n - 1)//2) * (n+1)//2)
        r = 2*r - 1
        r+=(r-2) + (r-4)
        print(r)
except EOFError:
    pass  



