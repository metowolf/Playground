class Solution {
public:
    int climbStairs(int n) {
        int a=1,b=1;
        while(n--)a+=b,swap(a,b);
        return a;
    }
};
