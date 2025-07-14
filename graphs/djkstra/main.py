import heapq

def dijkstra(graph, start):
    dist = {node: float('inf') for node in graph}
    dist[start] = 0
    pq = [(0, start)]  # (distância, nó)

    while pq:
        d, u = heapq.heappop(pq)
        if d > dist[u]:
            continue
        for v, w in graph[u]:
            if dist[v] > dist[u] + w:
                dist[v] = dist[u] + w
                heapq.heappush(pq, (dist[v], v))

    # Exibir resultados
    for node in graph:
        print(f"Distância de {start} até {node}: {dist[node]}")

# Grafo: 0 → 1 (5), 0 → 2 (3), 1 → 2 (2), 2 → 3 (4)
graph = {
    0: [(1, 5), (2, 3)],
    1: [(2, 2)],
    2: [(3, 4)],
    3: []
}

dijkstra(graph, 5)
