# Criando um grafo como dicionário de listas
grafo = {
    0: [1, 2],
    1: [0, 2],
    2: [0, 1]
}

# Exibindo conexões
for vertice in grafo:
    print(f"Vértice {vertice} está conectado com: {grafo[vertice]}")
