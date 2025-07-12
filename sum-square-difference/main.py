def sum_square_difference(n):
    sum_n = n * (n + 1) // 2
    square_of_sum = sum_n ** 2

    sum_squares = n * (n + 1) * (2 * n + 1) // 6

    return square_of_sum - sum_squares

if __name__ == "__main__":
   # Testando a função com n = 100
   # A saída esperada é 25164150
  print(sum_square_difference(100))  # Saída: 25164150
