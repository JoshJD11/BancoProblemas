m, n = map(int, input().split())

matriz = []
for _ in range(m):
    fila = input()
    nfila=[]
    for elemento in fila:
        nfila.append(elemento)
    matriz.append(nfila) 



def dfs(matriz, visitados, i, j, m, n):
    direcciones = [(-1,-1), (0,-1), (1,-1),
                   (-1,0 ),         (1,0 ),
                   (-1,1 ), (0,1 ), (1,1 )]
    stack = [(i,j)]
    while stack:
        fil, col = stack.pop()
        for x, y in direcciones:
            nuevX, nuevY = fil + x, col + y
            if 0 <= nuevX < m and 0 <= nuevY < n and matriz[nuevX][nuevY] == '#' and visitados[nuevX][nuevY] == 0:
                stack.append((nuevX, nuevY))
                visitados[nuevX][nuevY] = 1
    return visitados

def amoebas(matriz, m, n):
    amebas = 0
    visitados = [[0 for _ in range(n)] for _ in range(m)]  
    for fila in range(m):
        for columna in range(n):
            if matriz[fila][columna] == '#' and visitados[fila][columna] == 0:
                amebas += 1
                visitados[fila][columna] = 1
                visitados = dfs(matriz, visitados, fila, columna, m, n)
    return amebas


print(amoebas(matriz, m, n))