

def linear_matrix(matriz, target):
    for i in range(len(matriz)):
        for j in range(len(matriz)):
            if matriz[i][j] == target:
                return (i, j)
    return (-1, -1)


# Criando uma matriz 3x3
matriz = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]

target = 6

resultado = linear_matrix(matriz, target)
print("Índice encontrado:", resultado)  # Saída: (1, 1)


    
