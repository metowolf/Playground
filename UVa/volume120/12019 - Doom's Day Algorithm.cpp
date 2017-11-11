#include<iostream>
#include<cstdio>
using namespace std;

int whatday(int y,int m,int d){
	if(m<3)m+=12,y--;
	if(y<1752||y==1752&&m<9||y==1752&&m==9&&d<3)
		return (d+2*m+3*(m+1)/5+y+y/4+5)%7;
	else return (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
}

char week[][10]={"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int m,d;
		scanf("%d%d",&m,&d);
		printf("%s\n",week[whatday(2011,m,d)]);
	}
	return 0;
}
