#include<bits/stdc++.h>
using namespace std;

int main(){
	int g1,p1,g2,p2;
	cin>>g1>>p1>>g2>>p2;
	cout<<min(g2-g1,(g2*p2+g2-1)/100-(g1*p1+99)/100);
	return 0;
}
