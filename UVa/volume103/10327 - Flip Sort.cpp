#include<bits/stdc++.h>
using namespace std;

int n;
int A[1000+2];

int main(){
	while(~scanf("%d",&n)){
		int cnt=0;
		for(int i=1;i<=n;i++)scanf("%d",A+i);
		for(int i=1;i<=n;i++)
			for(int j=n;j>i;j--)if(A[j-1]>A[j]){
				swap(A[j-1],A[j]);
				cnt++;
			}
		printf("Minimum exchange operations : %d\n",cnt);
	}
	return 0;
}
