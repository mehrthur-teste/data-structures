class Node:
    def __init__(self, valor):
        self.valor = valor
        self.proximo = None

class ListaEncadeada:
    def __init__(self):
        self.cabeca = None

    def adicionar(self, valor):
        novo = Node(valor)
        if not self.cabeca:
            self.cabeca = novo
        else:
            atual = self.cabeca
            while atual.proximo:
                atual = atual.proximo
            atual.proximo = novo

    def imprimir(self):
        atual = self.cabeca
        while atual:
            print(f"{atual.valor} -> ", end="")
            atual = atual.proximo
        print("None")

# Teste
lista = ListaEncadeada()
lista.adicionar(10)
lista.adicionar(20)
lista.adicionar(30)
lista.imprimir()  # Saída: 10 -> 20 -> 30 -> None
