class Node:
	def __init__(self,n,weight):
		self.data = n
		self.weight = weight
		self.next = None

class linklist:
	def __init__(self):
		self.current = None
	
	def add(self,data,weight):
		tmp = Node(data,weight)
		tmp.next = self.current
		self.current = tmp

class graph:
	def __init__(self):
		self.dic = {}
		self.d = {}
		self.pi = {}
		
	def add(self,v1,v2,distance):
		if v1 not in self.dic:
			self.dic[v1] = linklist()
		if v2 not in self.dic:
			self.dic[v2] = linklist()
		self.dic[v1].add(v2,distance)
		


	def bellmanFord(self,start):
		infinity = 10000
		for i in self.dic:
			self.d[i] = infinity #In the begining all the distences are set to infinity 
			self.pi[i] = None
		self.d[start] = 0
		for j in xrange(len(self.dic) - 1):
			for k in self.d:
				if self.d[k] != infinity:
					tmp = self.dic[k]
					p = tmp.current
					while p != None:
						if self.d[p.data] > self.d[k] + p.weight:
							self.d[p.data] = self.d[k] + p.weight
							self.pi[p.data] = k
						p = p.next
		print self.d
		flag = False
		for a in self.dic:
			tmp = self.dic[a]
			p = tmp.current
			while p!= None:  
				if self.d[p.data] > self.d[a] + p.weight:
					flag = True
					break
				p = p.next
			if flag == True:
				break
			
		return flag


		
g1 = graph()  #A graph with a negatie weight cycle
g1.add("0","1",1)
g1.add("1","2",3)
g1.add("2","3",2)
g1.add("3","1",-6)
print(g1.bellmanFord("0"))


						



g2 = graph() #A graph without a negative weight cycle 
g2.add("s","t",6)
g2.add("s","y",7)
g2.add("t","y",8)
g2.add("t","z",-4)
g2.add("t","x",5)
g2.add("y","z",9)
g2.add("y","x",-3)
g2.add("x","t",-2)
g2.add("z","s",2)
g2.add("z","x",7)
print(g2.bellmanFord("s"))
