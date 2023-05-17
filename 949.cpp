#include<bits/stdc++.h>
#include <vector>

using namespace std;


class Solution {
public:
    bool vis[4];
    vector<string>ok;
    void dfs(vector<int>&arr,int id,string tmp){
        if(id==4) {
            if(tmp[0]=='0'||tmp[0]=='1'||tmp[0]=='2') {
                if(tmp[0]=='2') {
                    if(tmp[1]>='0'&&tmp[1]<='3') {
                        if(tmp[2]>='0'&&tmp[2]<='5') {
                            ok.push_back(tmp);
                            return ;
                        }
                        else return;
                    }
                    else return;
                }
                if(tmp[2]>='0'&&tmp[2]<='5') {
                    ok.push_back(tmp);
                    return;
                }
            }
            else return ;
        }
        for(int i=0;i<4;i++) {
            if(vis[i]) continue;
            vis[i]=1;
            string tmpp = "";
            tmpp.push_back((arr[i]-0)+'0');
            dfs(arr,id+1,tmp+tmpp);
            vis[i]=0;
        }
    }
    string largestTimeFromDigits(vector<int>& arr) {
        string ans;
        dfs(arr,0,"");
        if(ok.size()==0) {
            return "";
        }
        sort(ok.begin(),ok.end());
        int n = ok.size();
        for(int i=0;i<4;i++) {
            if(i==2) {
                ans.push_back(':');
            }
            ans.push_back(ok[n-1][i]);
        }
        return ans;
    }
};
int main()
{
    return 0;
}
