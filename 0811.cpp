#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const int mod = 1e9+7;
    int dp[1000005];
    int coins[4]={25,10,5,1};
    int waysToChange(int n) {
        dp[0]=1;
        for(int c=0;c<4;++c) {
            int tmp = coins[c];
            for(int i=tmp;i<=n;++i) {
                dp[i] = (dp[i]+dp[i-tmp])%mod;
            }
        }
        return dp[n];
    }
};
int main()
{

    return 0;
}
