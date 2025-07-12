def is_palindrome(n):
    return str(n) == str(n)[::-1]

def maior_palindromo():
    maior = 0
    for i in range(100, 1000):
        for j in range(i, 1000):  # evita duplicar
            produto = i * j
            if is_palindrome(produto) and produto > maior:
                maior = produto
    return maior

if __name__ == "__main__":
    print(maior_palindromo())  # Saída: 906609