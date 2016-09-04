class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        vector<int>nums;
        for(int i:nums1)nums.push_back(i);
        for(int i:nums2)nums.push_back(i);
        sort(nums.begin(),nums.end());
        double ans=(n+m)&1?(nums[(n+m)>>1]):(nums[(n+m-1)>>1]+nums[(n+m)>>1])/2.;
        return ans;
    }
};
