class Solution {
public:
    bool isPowerOfFour(int num) {
        while(num%4==0&&num)num/=4;
        return num==1;
    }
};
