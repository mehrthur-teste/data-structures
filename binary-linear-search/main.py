def binary_search(arr, target):
    left = 0
    right = len(arr) - 1

    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid  # posição encontrada
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return -1  # não encontrado

# Exemplo de uso
nums = [1, 3, 5, 7, 9, 11, 13]
print(binary_search(nums, 13))  # Saída: 3
