def count_t_non_a_substrings(t, test_cases):
    results = []
    
    for s in test_cases:
        n = len(s)
        total_t_count = 0
        
        i = 0
        while i < n:
            if s[i] != 'a':
                start = i
                while i < n and s[i] != 'a':
                    i += 1
                length = i - start
                total_t_count += (length * (length + 1)) // 2
            else:
                i += 1
                
        results.append(total_t_count)
    
    return results

# Reading input
import sys
input = sys.stdin.read
data = input().split()
t = int(data[0])
test_cases = data[1:t+1]

# Calculating results
results = count_t_non_a_substrings(t, test_cases)

# Printing results
for result in results:
    print(result)
