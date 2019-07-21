import math

n=int(raw_input())

for i in range(0,30):
	if(n<(1<<i)):
		near=(1<<(i-1))-1
		power=i-1
		break
		
diff=n-near
st=''
for j in range(power):
	st+='2'
	
bin_str=str(bin(diff)[2:])

res=int(st)+int(bin_str,10)
print res
