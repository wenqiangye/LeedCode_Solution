#include<bits/stdc++.h>
#include <functional>
#include <queue>
#include <vector>

using namespace std;

class Solution {
    public:
        int networkDelayTime(vector<vector<int>>& times, int n, int k) {
            int ans = 0;
            int dis[105];
            bool vis[105];
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >q;
            vector<pair<int,int>>e[105];
            for(int i=1;i<=n;i++) {
                dis[i]=INT_MAX;
                vis[i]=0;
            }
            dis[k]=0;
            int m = times.size();
            for(int i=0;i<m;i++) {
                int u = times[i][0];
                int v = times[i][1];
                int w = times[i][2];
                e[u].push_back({w,v});
            }
            q.push({0,k});
            while(q.size()) {
                pair<int,int> top = q.top();
                q.pop();
                int u = top.second;
                if(vis[u]) continue;
                vis[u]=1;
                for(auto x:e[u]) {
                    int v = x.second;
                    int w = x.first;
                    if(dis[v]>dis[u]+w){
                        dis[v] = dis[u]+w;
                        q.push({dis[v],v});
                    }
                }
            }
            for(int i=1;i<=n;i++) {
                if(dis[i]==INT_MAX) return -1;
                ans = max(ans,dis[i]);
            }
            return ans;
        }
};
int main()
{
    return 0;
}
