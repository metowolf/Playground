class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans(digits.size(),0);
        int one=1;
        for(int i=ans.size()-1;i>=0;i--){
            int sum=one+digits[i];
            one=sum/10;
            ans[i]=sum%10;
        }
        if(one)ans.insert(ans.begin(),one);
        return ans;
    }
};
