def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1

# Exemplo de uso
lista = [4, 2, 7, 1, 9]
alvo = 7
resultado = linear_search(lista, alvo)
print("Índice encontrado:", resultado)  # Saída: 2
