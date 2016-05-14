class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>V;
        for(int i=0;i<=num;i++)V.push_back(0);
        V[1]=1;
        for(int i=1;i<=num;i++)if(!V[i])V[i]=V[i>>1]+(i&1);
        return V;
    }
};
