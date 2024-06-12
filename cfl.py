import math
log_max = 0
binary_forms = []
def binary_form(m):
    b = [0]*log_max
    for i in range(log_max):
        if (m & (1 << i)):
            b[i] = 1
    return b

def suitable(a, k):
    first = [0]*log_max
    for i in range(k):
        b = binary_forms[i]
        first = [first[j] + b[j] for j in range(log_max)]
    for i in range(1, len(a)-k+1):
        b = binary_forms[i-1]
        c = binary_forms[i+k-1]
        for j in range(log_max):
            if first[j] == 0 and first[j]-b[j]+c[j]>0:    
                return False
            if first[j] == 0:
                continue
            if first[j]-b[j]+c[j] == 0:
                return False
            first[j] = first[j]-b[j]+c[j]
    return True


def binary_search(a, low, high):
    if low >= high:
        return low
    mid = int((low + high)/2)
    if suitable(a, mid):
        return binary_search(a, low, mid)
    return binary_search(a, mid+1, high)

t = int(input())
for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    max_num = 0
    for i in range(len(a)):
        max_num = max(a[i], max_num)
    if max_num == 0:
        print(1)
        continue
    log_max = int(math.log(max_num, 2))+1
    for i in range(len(a)):
        binary_forms.append(binary_form(a[i]))
    print(binary_search(a, 1, len(a)))
    log_max = 0
    binary_forms = []