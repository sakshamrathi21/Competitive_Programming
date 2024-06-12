t = int(input())
for i in range(t):
    s = input()
    # m = s
    possible = False
    for i in range(0, len(s)-1):
        if s[i] != s[i+1]:
            m = list(s)
            m[i], m[i+1] = m[i+1], m[i]
            # m[i+1] = s[i]
            m = ''.join(m)
            print("YES")
            print(m)
            possible = True
            break
    if not possible:
        print("NO")