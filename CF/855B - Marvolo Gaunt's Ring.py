cin=lambda:map(int,input().split())
n,p,q,r=cin()
A=cin()
tp,tq,tr=-1e20,-1e20,-1e20
for a in A:
	tp=max(tp,p*a)
	tq=max(tq,tp+q*a)
	tr=max(tr,tq+r*a)
print(tr)
