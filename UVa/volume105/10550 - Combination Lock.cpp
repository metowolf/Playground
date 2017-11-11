#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int A[4];
	while(~scanf("%d%d%d%d",A+0,A+1,A+2,A+3)){
		if(!(A[0]||A[1]||A[2]||A[3]))break;
		int angle=1080;
		angle+=(A[0]-A[1]+40)%40*9;
		angle+=(A[2]-A[1]+40)%40*9;
		angle+=(A[2]-A[3]+40)%40*9;
		printf("%d\n",angle);
	}
	return 0;
}
