struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void deleteNode(ListNode* node) {
		if (node == NULL) return;
		if (node->next == NULL)
		{
			node = NULL; return;
		}
		if (node->next != NULL && node->next->next == NULL)
		{
			ListNode * temp = node->next;
			node->val = node->next->val;
			node->next = NULL;
			delete temp;
			return;
		}
		if (node->next != NULL && node->next->next != NULL)
		{
			ListNode * temp = node->next;
			node->val = node->next->val;
			node->next = node->next->next;
			delete temp;
			return;
		}
	}
};