def myKnapSack(W,v,w,n):
	if n == 0 or W == 0:
		return 0
	if w[n-1] > W:
		return myKnapSack(W,v,w,n-1)
	else:
		return max(v[n-1] + myKnapSack(W-w[n-1],v,w,n-1) , myKnapSack(W,v,w,n-1))


values = [60,100,120]
weights = [10,20,30]
W = 50
n = len(values)	
print(myKnapSack(W,values,weights,n))
