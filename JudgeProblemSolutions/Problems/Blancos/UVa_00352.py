import sys
def dfs(matriz,visitados,i,j,n):
    direcciones=[(-1,-1),(0,-1),(1,-1),
                 (-1,0),        (1,0),
                 (-1,1), (0,1), (1,1)]
    stack=[(i,j)]
    
    while stack:
        x,y=stack.pop()
        for dirX,dirY in direcciones:
            nuevaX,nuevaY=x+dirX,y+dirY
            if 0<=nuevaX<n and 0<=nuevaY<n and matriz[nuevaX][nuevaY]=='1' and visitados[nuevaX][nuevaY]!=1:
                visitados[nuevaX][nuevaY]=1
                stack.append((nuevaX,nuevaY))
    return visitados

def contarWarEagles(matriz,n):
    visitados=[[0 for _ in range(n)]for _ in range(n)]
    warEagles=0
    for fila in range(n):
        for columna in range(n):
            if matriz[fila][columna]=='1' and visitados[fila][columna]==0:
                visitados[fila][columna]=1
                visitados=dfs(matriz,visitados,fila,columna,n)
                warEagles+=1

    return warEagles

imagen_num = 1
for linea in sys.stdin:
    n = int(linea.strip())
    matriz = [list(input().strip()) for _ in range(n)]
    war_eagles = contarWarEagles(matriz, n)
    print(f'Image number {imagen_num} contains {war_eagles} war eagles.')
    imagen_num += 1
#GG