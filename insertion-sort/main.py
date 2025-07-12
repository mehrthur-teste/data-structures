def insertion_sort(arr):
    for i in range(1, len(arr)):
        chave = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > chave:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = chave

# Exemplo
nums = [5, 2, 9, 1, 5, 6]
insertion_sort(nums)
print(nums)
