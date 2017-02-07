def selective(s,f):
	n = len(s)
	A = [1]
	j = 0
	for i in xrange(1,n):
		if s[i] >= f[j]:
			A.append(s[i])
			j = i
	return A

s = [1,3,4,5,3,7,10,8,8,2,13]
f = [4,5,6,7,8,9,11,12,13,14,15]

print(selective(s,f))