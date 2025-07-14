# Grafo direcionado (dicionário de listas)
grafo = {
    0: [1, 2],  # 0 → 1, 0 → 2
    1: [2],     # 1 → 2
    2: []       # 2 → ninguém
}

# Exibindo conexões
for vertice in grafo:
    print(f"Vértice {vertice} aponta para: {grafo[vertice]}")
