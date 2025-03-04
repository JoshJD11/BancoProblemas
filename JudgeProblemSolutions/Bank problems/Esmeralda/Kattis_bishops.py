try: #Basura de juez que daba error por nada
    while True:
        n = int(input())
        if n == 1:
            print(1)
        else:
            print(n + (n - 2))
except EOFError:
    pass  
