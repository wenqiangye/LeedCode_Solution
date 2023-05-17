#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        vector<pair<int,pair<int,int>> >tmp;
        int n = points.size();
        for(int i=0;i<points.size();++i) {
            int x = points[i][0];
            int y = points[i][1];
            int tp = x*x+y*y;
            // pair<int,pair<int,int>> xxx;
            tmp.push_back({tp,{x,y}});
        }
        sort(tmp.begin(),tmp.end());
        for(int i=1;i<=k;++i) {
            vector<int>res;
            res.push_back(tmp[i-1].second.first);
            res.push_back(tmp[i-1].second.second);
            ans.push_back(res);
        }
        return ans;
    }
};

int main()
{
    return 0;
}

