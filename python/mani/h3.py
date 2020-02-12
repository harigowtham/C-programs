import array
def priority_cache(calllogs):
	cache = set()
	firstlist = []
	prio = [None] * 1000
	item_set = set()
	calllogs.sort(key = lambda x: x[0])
	print calllogs
	for i,j in calllogs:	
		item_set.add(j)
	
	for i in item_set:
		prio[i] = 0
	
	for i,j in calllogs:
		firstlist.append(i)
			
	seconds = 0
	count = 1 
	for i, j in calllogs:
		print seconds
		if count > 1:
			print "Entered count"
			count -= 1
			prio[j] = prio[j] - 1
		else:
			count = firstlist.count(i) 
			if prio[j] >= 0:
				prio[j] = prio[j] + 2
				if count > 1:
					print "entered times seconds"
					prio[j] = prio[j] + (2 * seconds)
				for item in item_set:
					if item != j and prio[item] > 0:
						prio[item] = prio[item] - 1
		seconds += 1
	
		if prio[j] > 5:
			cache.add(j)
		
		for item in item_set:
			if prio[item] <= 3:
				if item in cache:
					cache.remove(item)
		
		print("prio[j]",prio[j],"and j",j)
		print("prio[1]",prio[1])
		print("prio[2]",prio[2])
		print list(cache)
	
	print list(cache)
	return list(cache)
					 
		
			 
if __name__ == "__main__":
	priority_cache([[1,1], [2,1], [2,1], [4,2], [5,2], [6,2]])
	priority_cache([[1,1], [2,1], [3,1], [4,2], [5,2], [6,2]])
	priority_cache([[1,1],[2,1],[3,2],[4,2],[5,1],[6,1]])
	priority_cache([[1,1],[2,1],[3,2],[4,2],[5,3],[6,3],[7,1],[8,1],[9,1]])
