#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

struct edge{
	int from,to,dis;
};

struct FBS{
	int n,m;
	vector<int>father;
	vector<edge>E;

	void init(int n){
		this->n=n;
		father.resize(n+2);
		for(int i=1;i<=n;i++)father[i]=-1;
		E.clear();
	}

	int find(int x){
		int p=x;
		while(father[p]>0)p=father[p];
		while(x!=p){
			int t=father[x];
			father[x]=p;
			x=t;
		}
		return x;
	}

	bool bind(int a,int b){
		int fa=find(a),fb=find(b);
		if(fa==fb)return 0;
		if(father[fa]<father[fb]){
			father[fa]+=father[fb];
			father[fb]=fa;
		}
		else{
			father[fb]+=father[fa];
			father[fa]=b;
		}
		return 1;
	}

}ans;

struct Point{
	int x,y;
};
vector<Point>P;

int length(Point a,Point b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

bool cmp(edge a,edge b){
	return a.dis<b.dis;
};

int main(){
	int T,_=0;
	scanf("%d",&T);
	while(T--){
		int n,m,r;
		scanf("%d%d",&n,&r);
		m=n*(n-1)/2;
		ans.init(m);
		P.resize(n+2);
		for(int i=1;i<=n;i++)scanf("%d%d",&P[i].x,&P[i].y);
		for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
			ans.E.push_back((edge){i,j,length(P[i],P[j])});
		}
		sort(ans.E.begin(),ans.E.end(),cmp);

		double ans1=0,ans2=0;int cnt=n;
		for(edge e:ans.E){
			if(ans.bind(e.from,e.to)){
				if(e.dis<=r*r)ans1+=sqrt(e.dis),cnt--;
				else ans2+=sqrt(e.dis);
			}
		}
		printf("Case #%d: %d %.0lf %.0lf\n",++_,cnt,ans1,ans2);
	}
	return 0;
}
