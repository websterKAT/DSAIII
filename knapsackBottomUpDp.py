def knapsack(W,wt,val,n):
	k = [[0 for x in range(W+1)] for y in range(n+1)]

	for i in range(n+1):
		for w in range(W+1):
			if i == 0 or w == 0:
				k[i][w] = 0
			elif wt[i-1] <= w:
				k[i][w] = max(val[i-1] + k[i-1][w-wt[i-1]], k[i-1][w])
			else:
				k[i][w] = k[i-1][w]

	print(k[n][W])
	row = n
	column = W
	while(row != 1 and column != 1):
		if k[row][column] != k[row-1][column]:
			print("item:"+str(row)),
			print("weight: "+str(wt[row-1])),
			print(" Value: " +str(val[row-1]))
			row -= 1
			column -= wt[row-1]
		else:
			row -= 1



val = [1,4,5,7] #should be enter in increasing order
wt = [1,3,4,5]
W = 7
n = len(val)

knapsack(W,wt,val,n)
