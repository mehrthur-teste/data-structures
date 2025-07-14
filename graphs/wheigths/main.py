# Grafo como dicionário: chave = vértice, valor = lista de (destino, peso)
grafo = {
    0: [(1, 5), (2, 3)],  # 0 → 1 (5), 0 → 2 (3)
    1: [(2, 2)],          # 1 → 2 (2)
    2: []                 # 2 → ninguém
}

# Exibindo conexões com peso
for vertice in grafo:
    print(f"Vértice {vertice} aponta para:")
    for destino, peso in grafo[vertice]:
        print(f"  → {destino} (peso {peso})")
