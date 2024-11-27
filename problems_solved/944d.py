t = int(input())
for i in range(t):
    s = input()
    num_cuts = 0
    mid_cut = False
    for i in range(len(s)-1):
        if s[i] == '1' and s[i+1] == '0':
            num_cuts+=1
        if s[i] == '0' and s[i+1] == '1':
            if mid_cut:
                num_cuts+=1
            else:
                mid_cut = True
    print(num_cuts+1)