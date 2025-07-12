def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

def find_nth_prime(n):
    count = 0
    num = 1
    while count < n:
        num += 1
        if is_prime(num):
            count += 1
    return num


if __name__ == "__main__":
    nth_prime = 10001  # Defina o n-ésimo primo desejado
    resultado = find_nth_prime(nth_prime)
    print(f"O {nth_prime}º primo é: {resultado}")