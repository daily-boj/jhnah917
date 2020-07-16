n = int(input())
c0, c1 = 0, 1
t0, t1 = 0, 0
for i in range(0, n-1):
    if i % 2:
        t0 = c0 + c1 - 1
    else:
        t0 = c0 + c1
        t1 = c0 + c1
        c0 = t0
        c1 = t1
print(c0)