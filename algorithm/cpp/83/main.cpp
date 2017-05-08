#include <iostream>

struct ListNode {
    int val;
	ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL) return NULL;
		ListNode * t = new ListNode(head->val);
		ListNode * 	rtn = t;
		while (head->next != NULL)
		{
			head = head->next;
			if (t->val != head->val)
			{
				t->next = new ListNode(head->val);
				t = t->next;
			}
		}
		return rtn;
	}
};

int main(int argc, char *argv[])
{
	Solution s;
	ListNode * tt = new ListNode(1);
	tt->next = new ListNode(2);
	tt->next->next = new ListNode(3);
	ListNode * rt = s.deleteDuplicates(tt);
	return 0;
}
