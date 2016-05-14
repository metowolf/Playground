class NumArray {
    vector<int>sum;
public:
    NumArray(vector<int> &nums) {
        int cnt=0;
        sum.push_back(0);
        for(int i=0;i<nums.size();i++){
            cnt+=nums[i];
            sum.push_back(cnt);
        }
    }

    int sumRange(int i, int j) {
        if(i>j)swap(i,j);
        return sum[j+1]-sum[i];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
