T = int(input())

def f(p,u):
    return (1 + (u-p)) * (u+p)/2

for i in range(T):
    N,K,X = map(int, input().split())
    print("Case " + str(i+1) + ": " + str((int)(f(1,N) - f(X,X+K-1))))