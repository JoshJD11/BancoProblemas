n,t = map(int, input().split()) #No salió

v = []
epsilon = 0.0000001


for _ in range(n):
    d,s = map(int, input().split())
    L = []
    L.append(d)
    L.append(s)
    v.append(L)


def calculateResult(v,c):
    ans = 0
    for i in range(len(v)):
        ans+=((v[i][0])/(v[i][1] + c))
    return ans



def positiveBS(v,target,epsilon):
    low = 0.0000001
    high = 1000000
    while(high-low > epsilon):       
        middle = (low + high)/2
        ans = calculateResult(v,middle)
        if (abs(ans - target) <= epsilon): return middle
        elif (ans > target): low = middle + epsilon
        else: high = middle - epsilon
    return 0


def negativeBS(v,target,epsilon):  #nop
    low = 0.0000001
    high = 1000000
    while(high-low > epsilon):       
        middle = (low + high)/2
        ans = calculateResult(v,-middle)
        if (abs(ans - target) <= epsilon): return -middle
        elif (ans < target): low = middle + epsilon
        else: high = middle - epsilon
    return 0



print(f"{negativeBS(v, t, epsilon):.9f}")
