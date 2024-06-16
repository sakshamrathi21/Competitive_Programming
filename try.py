def manhattan_permutations(t, test_cases):
    results = []
    for n, k in test_cases:
        max_manhattan = n * (n - 1) // 2  # Maximum Manhattan value for n
        if k > max_manhattan:
            results.append("No")
            continue
        
        results.append("Yes")
        permutation = list(range(1, n + 1))
        remaining_k = k
        
        for i in range(n - 1, -1, -1):
            if remaining_k == 0:
                break
            max_possible_addition = min(remaining_k, n - 1 - i)
            remaining_k -= max_possible_addition
            permutation[i], permutation[i - max_possible_addition] = permutation[i - max_possible_addition], permutation[i]
        
        results.append(" ".join(map(str, permutation)))
    
    return results

# Reading input and preparing the output
def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    t = int(data[0])
    index = 1
    test_cases = []
    for _ in range(t):
        n = int(data[index])
        k = int(data[index + 1])
        test_cases.append((n, k))
        index += 2
    
    results = manhattan_permutations(t, test_cases)
    for result in results:
        print(result)

if __name__ == "__main__":
    main()
