N,T = map(int, input().split()) #wrong answer


def quicksort(lista):
    if(lista == []): return lista
    pivote = lista[0]
    menores = []
    mayores = []
    for persona in lista[1:]:
        if(persona[1] < pivote[1] or (persona[1] == pivote[1] and persona[0] >= pivote[0])): mayores.append(persona)
        else: menores.append(persona)
    menores = quicksort(menores)
    mayores = quicksort(mayores)
    return mayores + [pivote] + menores



def bankQueue(lista, T):
    minutes = 0
    res = 0
    for persona in lista:
        if(T - minutes <= 0): break #recordar esta modificacion
        if not(persona[1] - minutes < 0):
            res += persona[0]
            minutes += 1
    return res


lista = []


while(N):
    plata,espera = map(int,input().split())
    lista.append([plata,espera])
    N-=1


listaOrdenada = quicksort(lista)

print(bankQueue(listaOrdenada,T))
