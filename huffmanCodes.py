class Node:
	def __init__(self,value):
		self.left = None
		self.right = None
		self.data = value

	def __str__(self):
		return str(self.data)

class Tree:
	def __init__(self):
		self.root = None
		

	def insert(self,data):
		if self.root == None:
			self.root = Node(data)

		else:
			current = self.root
			while True:
				if data < current.data:
					if current.left:
						current = current.left
					else:
						current.left = Node(data)
						break
				elif data >= current.data:
					if current.right:
						current = current.right
					else:
						current.right = Node(data)
						break
				else:
					break

	def preOrder(self,node):
		if node is not None:
			print node.data
			self.preOrder(node.left)
			self.preOrder(node.right)
			


	def search(self,data):
		current = self.root
		while True:
			if current is None:
				return False
				break
			elif data == current.data:
				return True
				break
			elif data < current.data:
				current = current.left
			else:
				current = current.right

class huffman:
	def __init__(self):
		self.d = {}
		self.count = 0
		self.lst = []

	def enter(self,symbol,frequeny):
		if symbol not in self.d::
			self.d[symbol] = frequeny
			self.lst.append(frequency)
			self.count += 1


	def mysort(self):
		self.lst = sorted(self.lst)
		return self.lst
	

	def ayodya(self):
		self.mysort()
		while self.count > 1:
		num1 = self.lst.pop(0)
		num2 = self.lst.pop(0)

		
	