/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        int rst = 0;
        //sort(G.begin(), G.end());
        ListNode* ptr = head;
        bool last_linked = false;
        
        while (ptr != NULL)
        {
            auto it = find(G.begin(), G.end(), ptr->val);
            if (it != G.end()){
                //cout<<*it<<endl;
                if (last_linked)
                {

                } else {
                    rst++;
                    last_linked = true;
                }
            }else{
                last_linked = false;
            }
            ptr = ptr->next;
        }
        return rst;
    }
};