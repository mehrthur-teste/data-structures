def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        menor = i
        for j in range(i+1, n):
            if arr[j] < arr[menor]:
                menor = j
        arr[i], arr[menor] = arr[menor], arr[i]

# Exemplo
nums = [29, 10, 14, 37, 13]
selection_sort(nums)
print(nums)  # [10, 13, 14, 29, 37]
