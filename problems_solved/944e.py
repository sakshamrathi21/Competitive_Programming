def bin_search(a, m, low, high):
    if (low >= high):
        return low
    if high-low==1:
        return low
    mid = int((low+high)/2)
    if a[mid] == m:
        return mid
    if a[mid] < m:
        return bin_search(a, m, mid, high)
    return bin_search(a, m, low, mid-1)

t = int(input())
for i in range(t):
    n, k, q = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    
    a.insert(0, 0)
    b.insert(0, 0)
    # print(a, b)
    out = []
    for j in range(q):
        m = int(input())
        ind = bin_search(a, m, 0, len(a)-1)
        # print("hello", m, ind)
        if a[ind] == m:
            out.append(b[ind])
            # print(b[ind])
            continue
        
        tim = (m-a[ind])*(b[ind+1]-b[ind])/(a[ind+1]-a[ind])+b[ind]
        # print("hello", tim)
        out.append(int(tim))
    print(*out)
    