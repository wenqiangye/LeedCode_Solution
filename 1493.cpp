#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int pre[100005];
    int las[100005];
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++) {
            if(nums[i]==1) {
                pre[i+1]=pre[i]+1;
            }
            else pre[i+1]=0;
            ans = max(ans,pre[i+1]);
        }
        for(int i=n-1;i>=0;i--) {
            if(nums[i]==1) {
                las[i+1]=las[i+2]+1;
            }
            else las[i+1]=0;
            ans = max(ans,las[i+1]);
        }
        for(int i=1;i<=n;i++) {
            if(nums[i-1]==0) {
                ans = max(ans,pre[i-1]+las[i+1]);
            }
        }
        if(ans==n) ans--;
        return ans;
    }
};
int main()
{
    
    return 0;
}
