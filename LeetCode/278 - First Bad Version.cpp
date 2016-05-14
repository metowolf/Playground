// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long L=1,R=n;
        while(L<R){
            long long mid=(L+R)>>1;
            if(isBadVersion(mid))R=mid;
            else L=mid+1;
        }
        return L;
    }
};
