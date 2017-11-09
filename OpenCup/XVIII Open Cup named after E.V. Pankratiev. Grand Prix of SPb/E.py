def farey(a,b,c,d):
	t=a//b+1
	if t*d<c:
		return t,1
	if a==0:
		return 1,d//c+1
	if a<=b and c<=d:
		ty,tx=farey(d,c,b,a)
		return tx,ty
	t=a//b
	tx,ty=farey(a-b*t,b,c-d*t,d)
	if b<ty:
		return a,b
	return tx+ty*t,ty

def gcd(a,b):
	if b==0:
		return a
	return gcd(b,a%b)

def cd(a,b):
	d=gcd(a,b)
	return a//d,b//d

T=int(input())
for i in range(T):
	ss,s=map(int,input().split("."))
	if s==0:
		print(0,1)
		continue
	a,b=cd(s*10-5,10**19)
	c,d=cd(s*10+5,10**19)
	x,y=farey(a,b,c,d)
	x,y=cd(x,y)
	print(x,y)
