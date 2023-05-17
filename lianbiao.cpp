#include <bits/stdc++.h>


using namespace std;


 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = nullptr;
        int a = 0,b = 0;
        int add = 0;
        ListNode* tmp = ans;
        // cout<<tmp->val<<endl;
        while(l1!=nullptr||l2!=nullptr) {
            if(l1!=nullptr) a = l1->val;
            else a = 0;
            if(l2!=nullptr) b = l2->val;
            else b = 0;
            if(ans==nullptr) {
                ans = tmp = new ListNode((a+b+add)%10);
            }
            else {
                tmp->next = new ListNode((a+b+add)%10);
                tmp = tmp->next;
            }
            add = (a+b+add)/10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(add) {
            tmp->next = new ListNode(add);
        }
        // if(tmp->val==0) tmp = nullptr;
        return ans;
    }
};
int main()
{

    return 0;
}
