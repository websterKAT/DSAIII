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
		
	def _add(self,v1,v2,distance):
		if v1 not in self.dic:
			self.dic[v1] = linklist()
		self.dic[v1].add(v2,distance)
		self.color[v1] = 'w'
	
	def add(self,v1,v2):
		self._add(v1,v2,distance)
		self._add(v2,v1,distance)

	def kruskals(self):
		solution = []
		





	

