class Solution {
public:
    string reverseString(string s) {
        string ans="";
        for(int i=0;i!=s.size();++i)ans=s[i]+ans;
        return ans;
    }
};
