n = int(input())

def collatz(n):
    if(n<=1): return 1
    if(n%2==0): return n + collatz(n//2)
    return n + collatz(3*n+1)

print(collatz(n))
