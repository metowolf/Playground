class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return 0;
        int a,b,c,d;
        a=b=c=d=1;
        for(int i=0;i<s.size();i++){
            a+=s[i],b+=t[i];
            c*=s[i],d*=t[i];
        }
        return a==b&&c==d;
    }
};
