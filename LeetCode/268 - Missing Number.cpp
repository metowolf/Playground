class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long sum=0,len=nums.size();
        for(int i=0;i<len;i++)sum+=nums[i];
        return len*(len+1)/2-sum;
    }
};
