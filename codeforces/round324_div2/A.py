(n,t)= raw_input().split()
n=int(n)-1
t=int(t)
m = 10**n;
if(t >= m*10):
	print -1
else:
	for i in range(m,m+100):
		if(i%t == 0):
			print i
			break
