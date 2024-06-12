def is_sorted(arr):
    """ Helper function to check if an array is sorted in non-decreasing order. """
    return all(arr[i] <= arr[i + 1] for i in range(len(arr) - 1))

def can_be_sorted_by_swapping_prefix_suffix(t, test_cases):
    results = []
    for i in range(t):
        n = test_cases[i][0]
        a = test_cases[i][1]
        
        can_be_sorted = False
        
        for shift in range(n):
            rotated_array = a[shift:] + a[:shift]
            if is_sorted(rotated_array):
                can_be_sorted = True
                break
        
        if can_be_sorted:
            results.append("Yes")
        else:
            results.append("No")
    
    return results

# Reading input
t = int(input())
test_cases = []
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    test_cases.append((n, a))

# Solving each test case
results = can_be_sorted_by_swapping_prefix_suffix(t, test_cases)

# Output the results
for result in results:
    print(result)
