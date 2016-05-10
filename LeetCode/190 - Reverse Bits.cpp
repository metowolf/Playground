class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t t=0;
        for(int i=1;i<=32;i++){
            t<<=1;
            if(n&1)++t;
            n>>=1;
        }
        return t;
    }
};
