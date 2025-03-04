#T = int(input())


def isValid(perm, P, R):
    cantP = 0
    cantR = 0
    maxP = -15
    maxR = -15
    for i in range(len(perm)):
        actualP = perm[i]
        actualR = perm[len(perm)-i-1]
        if(actualP > maxP):
            cantP+=1
            maxP = actualP
        if(actualR > maxR):
            cantR+=1
            maxR = actualR
    return cantP == P and cantR == R



def queue(N,P,R):
    res = 0
    pila = [[[0],N-1]]
    while(pila):
        actual, restantes = pila.pop()
        if not(restantes):
            if(isValid(actual,P,R)):
                res+=1
        else: 
            pila.append([actual + [actual[len(actual)-1] + 1], restantes - 1])
            pila.append([actual + [actual[len(actual)-1]], restantes - 1])
            pila.append([actual + [actual[len(actual)-1] - 1], restantes -1])
    return res



# while(T):
#     N,P,R = map(int, input().split())
#     print(queue(N,P,R))
#     T-=1


print(queue(10,4,4))