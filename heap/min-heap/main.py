import heapq

nums = [20, 5, 15, 30, 10]
heapq.heapify(nums)  # transforma a lista em um min-heap

while nums:
    print(heapq.heappop(nums), end=" ")  # imprime em ordem crescente
