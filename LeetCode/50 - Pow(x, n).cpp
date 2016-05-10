class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        unsigned int k,f;
        if(n<0)k=(long long)n*-1,f=1;
        else k=n,f=0;
        while(k){
            if(k&1)ans*=x;
            x=x*x;
            k>>=1;
        }
        return f?1/ans:ans;
    }
};
