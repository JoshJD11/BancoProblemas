T = int(input())

for _ in range(T):
    n,m = map(int, input().split())
    print(n*m - n*(n+1)//2)