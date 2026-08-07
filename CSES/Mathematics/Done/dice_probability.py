n, a, b = map(int, input('').split())

dp = [[0 for _ in range(6*n+10)] for _ in range(n+1)]

dp[0][0] = 1

for i in range(1, n + 1):
    for val in range(1, 6*n+10):
        for d in range(1, 7):
            if(val - d < 0): continue
                
            dp[i][val] += dp[i-1][val-d]

sum = 0
interval = 0

for i in range(a, b + 1):
    interval += dp[n][i]

if interval == 0:
    print(0.000000)
    exit(0)

for i in range(1, 6*n+1):
    sum += dp[n][i] / interval

sum = 1.0 / sum

print(f'{sum:.6f}')
