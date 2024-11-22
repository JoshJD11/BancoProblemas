from math import sqrt

def calcularMaximoProducto():
    T = int(input())
    resultados = []
    for _ in range(T):
        X, Y = map(int, input().split())
        a = 12
        b = (-4) * (X + Y)
        c = X * Y
        discriminante = b * b - 4 * a * c
        res1 = ((X-(2*((-b + sqrt(b*b-4*a*c))/(2*a))))*(Y-(2*((-b + sqrt(b*b-4*a*c))/(2*a))))*((-b + sqrt(b*b-4*a*c))/(2*a)))
        res2 = ((X-(2*((-b - sqrt(b*b-4*a*c))/(2*a))))*(Y-(2*((-b - sqrt(b*b-4*a*c))/(2*a))))*((-b - sqrt(b*b-4*a*c))/(2*a)))
        resultados.append(max(res1, res2))
    return resultados


resultados = calcularMaximoProducto()


for resultado in resultados:
    print(f"{resultado:.7f}")
