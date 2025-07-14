import heapq

nums = [20, 5, 15, 30, 10]
max_heap = [-x for x in nums]
heapq.heapify(max_heap)

while max_heap:
    print(-heapq.heappop(max_heap), end=" ")  # imprime em ordem decrescente
