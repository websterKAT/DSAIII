def preprocessor(pat):
	mydic = {}
	for k in range(len(pat)):
		mydic[pat[k]] = k
	return mydic

def search(pattern, text):
	m = len(pattern)
	n = len(text)
	shifts = 0
	special = preprocessor(pattern)
	while (shifts <= n-m):
		j = m-1
		while(j >= 0 and pattern[j] == text[shifts+j]):
			j -= 1
		if(j < 0):
			print("pattern fount at "+str(shifts+1))
			shifts += 1; 
		else:
			if text[shifts+j] in special:
				shifts += max(1,(j-special[text[shifts+j]]))
			else:
				shifts += j+1


mytxt = "this is test"
pat = "test"
search(pat,mytxt)	