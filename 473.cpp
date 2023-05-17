#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        sort(matchsticks.begin(),matchsticks.end(),greater<int>());
        for(auto x:matchsticks){
            sum+=x;
        }
        if(sum%4) {
            return false;
        }
        int ave = sum/4;
        for(auto x:matchsticks) {
            if(x>ave) return false;
        }
        int n = matchsticks.size();
        vector<int>dp(1<<n,-1);
        dp[0]=0;
        for(int i=1;i<1<<n;i++) {
            for(int k = 0;k<n;k++) {
                if((i&(1<<k))==0) continue;
                int j = i&~(1<<k);
                if(dp[j]>=0&&dp[j]+matchsticks[k]<=ave) {
                    dp[i]=(dp[j]+matchsticks[k])%ave;
                    break;
                }
            }
        }
        return dp[(1<<n)-1]==0;
    }
};

int main()
{
    return 0;
}
