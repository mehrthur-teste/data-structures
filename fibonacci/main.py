def soma_pares_fibonacci(limite):
    a, b = 1, 2
    soma = 0

    while a <= limite:
        if a % 2 == 0:
            soma += a
        a, b = b, a + b  # Próximo termo

    return soma

if __name__ == "__main__":
    limite = 4000000  # Defina o limite desejado
    resultado = soma_pares_fibonacci(limite)
    print(f"A soma dos termos pares da sequência de Fibonacci até {limite} é: {resultado}")