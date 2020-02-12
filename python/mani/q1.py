a = states[:]
b = []
daycount = 1
dayscount = days
while days > 0:
	count = 0
	for i in a:
		if count == 0:
			b.append(a[count+1] ^ 0)
		elif count == len(a) - 1:
			b.append(a[count-1] ^ 0)
		else:
			b.append(a[count-1] ^ a[count+1])
		count += 1
	
	if daycount != dayscount:
		a = b[:]
		b = []
		daycount += 1
	
	days -= 1
print b
