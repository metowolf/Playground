cin=lambda:list(map(int,input().split()))
n,k=cin()
A=cin()
C=[0 for i in range(n+1)]
while True:
	if A[0]>A[1]:
		A[0],A[1]=A[1],A[0]
	A=A[1:]+A[:1]
	C[A[0]]+=1
	if A[0]==n or C[A[0]]>=k:
		print(A[0])
		break
