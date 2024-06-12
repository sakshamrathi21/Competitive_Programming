def count_substrings_with_ones(binary_string):
    n = len(binary_string)
    result = [0] * (n + 1)
    ones_count = 0
    total_substrings = 0

    for i in range(n):
        if binary_string[i] == '1':
            ones_count += 1
        total_substrings += ones_count

    for i in range(ones_count, 0, -1):
        result[i] = total_substrings
        total_substrings -= ones_count - i

    for count in result:
        print(count, end=" ")

# Example usage
binary_string = input().strip()
count_substrings_with_ones(binary_string)
