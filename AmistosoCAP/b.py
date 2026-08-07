palavras = ['UAI', 'TREM', 'SO']
idx = 0
val = 10

n = int(input(''))

if n == 1:
    print(1)
    exit(0)

if n == 2:
    print(f'1 1')
    exit(0)

print(f'1 1', end='')

n -= 2

i = 1
j = 1
for _ in range(0, n):
    k = i + j

    j = i
    i = k
    if len(str(i)) > len(str(j)):
        print(f' {palavras[idx]}', end='')
        idx = (idx + 1) % 3
        i = val
        val *= 10
    else:
        print(f' {i}', end ='')

print()

