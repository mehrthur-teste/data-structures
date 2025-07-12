
def sum_of_multiples(number_one, number_two, number_below):
    """
    This function returns the multiples of two numbers.
    :param number_one: First number
    :param number_two: Second number
    :return: List of multiples of both numbers
    """
    sum = 0
    multiples_list = []
    for i in range(1, number_below):
        if i % number_one == 0 or i % number_two == 0:
            sum += i
            multiples_list.append(i)
    print(f"Multiples of {number_one} or {number_two} below {number_below}: {multiples_list}")
    print(f"Sum of multiples: {sum}")
    return sum 


if __name__ == "__main__":
    number_one = 3
    number_two = 5
    number_below = 1000
    sum_of_multiples(number_one, number_two, number_below)