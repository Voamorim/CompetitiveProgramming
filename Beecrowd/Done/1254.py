
tag = str()
troca = str()
msg = str()


tag = input()
troca = input()
msg = input()

abriu = False
init = 0

print(tag)
print(troca)
print(msg)

for i, c in enumerate(msg, 0):
    if c == '<':
        abriu = True
        init = i

    if c == '>':
        if abriu:
            
            if tag in msg[init:i]:
                print('lskjdçlkwjdlfjaslkdjf')
            fatia = msg[init:i]
            fatia.replace(tag, troca)
            print(fatia)

        abriu = False

        
print(msg)

