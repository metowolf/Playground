#include<bits/stdc++.h>
#define maxchar 6
using namespace std;

int sum=0;
char op[maxchar+2];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",op);
        if(op[0]=='d'){
            int x;
            scanf("%d",&x);
            sum+=x;
        }
        else printf("%d\n",sum);
    }
    return 0;
}
