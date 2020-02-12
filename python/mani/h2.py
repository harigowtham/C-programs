import math
def final(instances, averageUtil):
	action_taken = False
	count_action = 0
	for num in averageUtil:
		is_odd = False
		if action_taken and count_action < 10:
			count_action += 1
		elif num < 25:
			if instances > 1:
				action_taken = True
				count_action = 0
				if instances % 2 != 0:
					is_odd = True
				
				instances = instances / 2
				
				if is_odd:
					instances = instances + 1
		elif num > 60:
			reassign_instances = instances
			instances = instances * 2
			if instances > (2 * (10 ** 8)):
				instances = reassign_instances
				action_taken = False
			else:
				action_taken = True
				count_action = 0
		print("num = ",num,"instances = ", instances)
	return instances	

if __name__ == "__main__":
	count = final(2, [25, 23, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 76, 80])
	print("count=",count)
	count = final(1, [5, 10, 80])
	print("count=",count)
	count = final(5, [30, 5, 4, 8, 19, 89] )
	print("count=",count)
	
