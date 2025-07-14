def bellman_ford(graph, V, start, end):
    dist = [float('inf')] * V
    parent = [None] * V
    dist[start] = 0

    for _ in range(V - 1):
        for u in graph:
            for v, w in graph[u]:
                if dist[u] != float('inf') and dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w
                    parent[v] = u

    # Verifica ciclo negativo
    for u in graph:
        for v, w in graph[u]:
            if dist[u] != float('inf') and dist[u] + w < dist[v]:
                raise Exception("Ciclo negativo detectado")

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

# Grafo com 9 vértices (0 a 8)
graph = {
    2: [(3, 5), (4, -4)],
    3: [(5, 4)],
    4: [(6, 7)],
    5: [(7, -2)],
    6: [(7, 1)],
    7: [(8, 6)],
    8: [],
    0: [],
    1: [],
}

bellman_ford(graph, 9, 2, 8)
