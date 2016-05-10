class Solution {
public:
    bool isPowerOfTwo(int n) {
        while(n%2==0&&n)n>>=1;
        return n==1;
    }
};
