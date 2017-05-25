def selective(s,f):
	n = len(s)
	A = [1]
	j = 0
	for i in xrange(1,n):
		if s[i] >= f[j]:
			A.append(s[i])
			j = i
	return A

s = [1,2,1,3]
f = [2,3,3,4]

print(selective(s,f))