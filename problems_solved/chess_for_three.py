def max_draws(p1, p2, p3):
    # print("hello")
    if (p1+p2+p3)%2 != 0:
        return -1
    if p1 < 0 or p2 < 0 or p3 < 0:
        return -1
    if (p1+p2+p3) == 0:
        return 0
    if (p1,p2,p3) in dict_dp:
        return dict_dp[(p1,p2,p3)]
    max_drs = max(max_draws(p1-2,p2,p3), max_draws(p1,p2-2,p3), max_draws(p1,p2,p3-2), 1+max_draws(p1-1,p2-1,p3), 1+max_draws(p1-1,p2,p3-1), 1+max_draws(p1,p2-1,p3-1))
    dict_dp[(p1,p2,p3)] = max_drs
    return max_drs


dict_dp = {}
t = int(input())
# input(t)
for i in range(t):
    p1 = 0
    p2 = 0
    p3 = 0
    p1, p2, p3 = map(int, input().split())
    print(max_draws(p1, p2, p3))
