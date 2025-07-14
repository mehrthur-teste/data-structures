import heapq

def dijkstra(graph, start, end):
    dist = {node: float('inf') for node in graph}
    parent = {node: None for node in graph}
    dist[start] = 0
    pq = [(0, start)]

    while pq:
        d, u = heapq.heappop(pq)
        if d > dist[u]:
            continue
        for v, w in graph[u]:
            if dist[v] > dist[u] + w:
                dist[v] = dist[u] + w
                parent[v] = u
                heapq.heappush(pq, (dist[v], v))

    if dist[end] == float('inf'):
        print(f"Sem caminho de {start} até {end}")
        return

    # Reconstruir caminho
    path = []
    v = end
    while v is not None:
        path.append(v)
        v = parent[v]
    path.reverse()

    print(f"Caminho mínimo de {start} até {end}: {' -> '.join(map(str, path))}")
    print(f"Distância total: {dist[end]}")

# Grafo com pesos
graph = {
    2: [(3, 5), (4, 2)],
    3: [(5, 4)],
    4: [(6, 7)],
    5: [(7, 3)],
    6: [(7, 1)],
    7: [(8, 6)],
    8: [],
}

dijkstra(graph, 2, 8)
