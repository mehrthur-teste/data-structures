from itertools import combinations
from sympy import isprime

def concat_prime(p1, p2):
    return isprime(int(str(p1) + str(p2))) and isprime(int(str(p2) + str(p1)))

def is_valid_set(prime_set):
    return all(concat_prime(p1, p2) for p1, p2 in combinations(prime_set, 2))

def solve():
    from sympy import primerange
    primes = list(primerange(2, 10000))
    sets = []

    for i, p1 in enumerate(primes):
        for j in range(i + 1, len(primes)):
            p2 = primes[j]
            if not concat_prime(p1, p2): continue
            for k in range(j + 1, len(primes)):
                p3 = primes[k]
                if not all(concat_prime(x, p3) for x in [p1, p2]): continue
                for l in range(k + 1, len(primes)):
                    p4 = primes[l]
                    if not all(concat_prime(x, p4) for x in [p1, p2, p3]): continue
                    for m in range(l + 1, len(primes)):
                        p5 = primes[m]
                        if all(concat_prime(x, p5) for x in [p1, p2, p3, p4]):
                            return [p1, p2, p3, p4, p5], p1 + p2 + p3 + p4 + p5

result, total = solve()
print("Primes:", result)
print("Sum:", total)
