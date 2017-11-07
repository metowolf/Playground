#include<bits/stdc++.h>
using namespace std;

const double eps=1e-7;
const int maxn=1e5;

vector<double>ps[maxn+10];
int fail[maxn+10];
double x[maxn+10],delta[maxn+10];
int n,pn;

int main(){
    while(~scanf("%d",&n)&&n){
        pn=0;
        for(int i=1;i<=n;i++)scanf("%lf",x+i);
        for(int i=1;i<=n;i++){
            double dt=-x[i];
            for(int j=0;j<ps[pn].size();j++)dt+=x[i-j-1]*ps[pn][j];
            delta[i]=dt;
            if(fabs(dt)<=eps)continue;
            fail[pn]=i;
            if(!pn){ps[++pn].resize(1);continue;}
            vector<double> &ls=ps[pn-1];
            double k=-dt/delta[fail[pn-1]];
            vector<double>cur;
            cur.resize(i-fail[pn-1]-1);
            cur.push_back(-k);
            for(int j=0;j<ls.size();j++)cur.push_back(ls[j]*k);
            if(cur.size()<ps[pn].size())cur.resize(ps[pn].size());
            for(int j=0;j<ps[pn].size();j++)cur[j]+=ps[pn][j];
            ps[++pn]=cur;
        }
        int len=(int)ps[pn].size();
        for(int i=0;i<len;++i)
            printf("%g%c",ps[pn][i]," \n"[i==len-1]);
    }
    return 0;
}
