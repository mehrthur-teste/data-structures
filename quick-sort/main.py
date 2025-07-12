def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivo = arr[len(arr) // 2]
    menores = [x for x in arr if x < pivo]
    iguais = [x for x in arr if x == pivo]
    maiores = [x for x in arr if x > pivo]
    return quick_sort(menores) + iguais + quick_sort(maiores)

# Exemplo
nums = [3, 6, 8, 10, 1, 2, 1]
print(quick_sort(nums))
