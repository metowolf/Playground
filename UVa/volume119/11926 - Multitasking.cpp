#include<bits/stdc++.h>
using namespace std;

struct node{
	int L,R;
	bool operator < (const node o) const{
		return make_pair(R,L)<make_pair(o.R,o.L);
	}
};

vector<node>A;

int main(){

	//freopen("input.txt","r",stdin);

	int n,m;
	while(~scanf("%d%d",&n,&m),n||m){
		A.clear();
		for(int i=1;i<=n;i++){
			int L,R;
			scanf("%d%d",&L,&R);
			A.push_back((node){L,R});
		}
		for(int i=1;i<=m;i++){
			int L,R,t;
			scanf("%d%d%d",&L,&R,&t);
			for(int _L=L,_R=R;_R<=1000000;_L+=t,_R+=t){
				A.push_back((node){_L,_R});
			}
		}
		sort(A.begin(),A.end());
		bool flag=1;
		for(int i=1;i<A.size();i++){
			if(A[i].L<A[i-1].R){
				flag=0;
				break;
			}
		}
		printf(flag?"NO CONFLICT\n":"CONFLICT\n");
	}
	return 0;
}
