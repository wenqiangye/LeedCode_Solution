#include <bits/stdc++.h>
#include <cstring>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        string ans = "";
        unordered_map<string,int>mp;
        //int out[105];
        //memset(out,0,sizeof(out));
        for(auto x:paths) {
            mp[x[0]]++;
        }
        for(auto x:paths) {
            if(mp.find(x[1])==mp.end()) {
                return x[1];
            }
        }
        return "";
    }

};
int main()
{

    return 0;
}
