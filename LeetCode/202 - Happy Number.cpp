class Solution {
public:
    bool isHappy(int n) {
        set<int>S;
        while(n!=1){
            if(!S.count(n))S.insert(n);
            else return 0;
            int t=0;
            while(n)t+=(n%10)*(n%10),n/=10;
            n=t;
        }
        return 1;
    }
};
