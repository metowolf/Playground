#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define CLR(c,x) memset(c,x,sizeof(c))
#define sf scanf
#define pf printf
#define maxn 80
using namespace std;

char s[maxn+2];

int main(){
	int T;
	sf("%d",&T);
	while(T--){
		sf("%s",s);
		double ans=0;
		double per=0;
		int t=0;
		for(int i=0;s[i];i++){
			if(s[i]>='A'&&s[i]<='Z'){
				if(t==0)t=1;
				ans+=per*t;
				//pf("%f %d\n",per,t);
				if(s[i]=='C')per=12.01;
				if(s[i]=='H')per=1.008;
				if(s[i]=='O')per=16.00;
				if(s[i]=='N')per=14.01;
				t=0;
			}
			else{
				t=s[i]-'0';
				while(s[i+1]&&s[i+1]>='0'&&s[i+1]<='9')t=t*10+s[++i]-'0';
			}
		}
		if(t==0)t=1;
		ans+=per*t;
		pf("%.3f\n",ans);
	}
	return 0;
}

/*
4
C
C6H5OH
NH2CH2COOH
C12H22O11
*/
