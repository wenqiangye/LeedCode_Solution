#include <bits/stdc++.h>
#include <string>
#include <type_traits>
#include <vector>

using namespace std;
class Solution{
private:
    vector<string>ans;
    vector<int>seg;
public:
    void dfs(const string &s,int segId,int segStart){
        if(segId==4) {
            if(segStart==s.size()) {
                string ipAddr="";
                for(int i=0;i<4;++i) {
                    ipAddr+=to_string(seg[i]);
                    if(i!=3) {
                        ipAddr.push_back('.');
                    }
                }
                ans.push_back(ipAddr);
            }
            return ;
        }
        if(segStart==s.size()) {
            return ;
        }
        if(s[segStart]=='0') {
            seg[segId]=0;
            dfs(s,segId+1,segStart+1);
        }
        int addr = 0;
        for(int i=segStart;i<s.size();++i) {
            addr = addr * 10 + (s[i]-'0');
            if(addr>0&&addr<=255) {
                seg[segId]=addr;
                dfs(s,segId+1,i+1);
            }
            else break;
        }
    }
    vector<string> restoreIpAddresses(string s){
        seg.resize(4);
        dfs(s,0,0);
        return ans;
    }
};

int main()
{

    return 0;
}
