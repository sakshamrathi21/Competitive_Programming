t = int(input())
for i in range(t):
    a, b, c, d = map(int, input().split())
    x = (a+1)%12
    if x==0: x = 12
    one_passed = False
    possible = True
    while (x != a):
        # print(x)
        if x == b and not one_passed:
            print("NO")
            possible = False
            break
        elif x == b and one_passed:
            print("YES")
            possible = False
            break
        elif x == c and not one_passed:
            one_passed = True
        elif x == d and not one_passed:
            one_passed = True
        elif x == c and one_passed:
            print("NO")
            possible = False
            break
        elif x == d and one_passed:
            print("NO")
            possible = False
            break
        x = (x+1)%12
        if x==0: x = 12
    if possible:
        print("YES")