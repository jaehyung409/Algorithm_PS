import heapq
import sys

n =int(input())
ordered = dict()
old = list()

array = list(map(int,sys.stdin.readline().split()))
heap = array[:]

heapq.heapify(heap)

for i in range(n):
	
	temp = heapq.heappop(heap)
	if ordered.get(temp,-1) == -1:
		ordered[temp] = i

for i in array:
	
	temp = ordered[i]
	
	while temp in old:
		temp +=1
	
	old.append(temp)
	
	print(temp,end=" ")
print("")
