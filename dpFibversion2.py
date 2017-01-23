fib = {}
n = int(raw_input("Enter a number to calculate the fibonacci No:"))
for k in range(1,n+1):
	if k <= 2:
		f = 1
	else:
		f = fib[k-1] + fib[k-2]
	fib[k] = f
print(fib[k])

