#include <bits/stdc++.h>

using namespace std;
/*
    优先队列贪心
    复杂度 ： O(nlogn)
*/
class Solution {
public:
    priority_queue<pair<int,pair<int,int> > >alice,bob;
    bool isTake[100005];
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int siz = aliceValues.size();
        memset(isTake,0,sizeof(isTake));
        for(int i=1;i<=siz;i++) {
            alice.push({aliceValues[i-1]+bobValues[i-1],{aliceValues[i-1],i}});
        }
        for(int i=1;i<=siz;i++) {
            bob.push({aliceValues[i-1]+bobValues[i-1],{bobValues[i-1],i}});
        }
        int alice_res = 0,bob_res = 0;
        int n = 0;
        for(int i=1;i<=siz;i++) {
            if(i%2) {
                while(1) {
                    pair<int,pair<int,int>> tmp = alice.top();
                    alice.pop();
                    if(isTake[tmp.second.second]) {
                        continue;
                    }
                    else {
                        alice_res+=tmp.second.first;
                        isTake[tmp.second.second] = 1;
                        break;
                    }
                }
            }
            else {
                while(1) {
                    pair<int,pair<int,int>> tmp = bob.top();
                    bob.pop();
                    if(isTake[tmp.second.second]) {
                        continue;
                    }
                    else {
                        bob_res+=tmp.second.first;
                        isTake[tmp.second.second] = 1;
                        break;
                    }
                }
            }
        }
        // cout<<alice_res<<' '<<bob_res<<endl;
        if(alice_res>bob_res) return 1;
        if(alice_res==bob_res) return 0;
        return -1;
    }
};
priority_queue<pair<int,int> >q;
int main()
{
    q.push({1,2});
    q.push({2,3});
    printf("%d %d\n",q.top().first,q.top().second);
    
    return 0;
}