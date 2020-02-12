out = []

n = int(raw_input())
a = 0
b = 1
out.append (0)
out.append (1)
for i in range(n):
    c = a + b
    out.append (c)
    a = b
    b = c
print (map (lambda x:x**3, out))
