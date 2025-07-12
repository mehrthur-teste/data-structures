import math

def lcm(a, b):
    return a * b // math.gcd(a, b)

def smallest_multiple(n):
    result = 1
    for i in range(2, n + 1):
        result = lcm(result, i)
    return result

print(smallest_multiple(20))  # Saída: 232792560
