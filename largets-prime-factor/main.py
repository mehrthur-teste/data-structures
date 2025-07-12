def maior_fator_primo(n):
    fator = 2
    while fator * fator <= n:
        if n % fator == 0:
            n //= fator
        else:
            fator += 1
    return n  # n agora é o maior fator primo

if __name__ == "__main__":
    numero = 600851475143
    print("Maior fator primo:", maior_fator_primo(numero))
