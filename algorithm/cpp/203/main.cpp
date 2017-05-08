#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		if (head == NULL) return NULL;
		while (head->val == val)
		{
			if (head->next != NULL)
				head = head->next;
			else
				return NULL;
		}
		if (head == NULL) return NULL;

		ListNode * ptr = head->next;
		ListNode * temp = head;
		while (ptr != NULL)
		{
			if (ptr->val == val)
			{
				temp->next = ptr->next;
				ListNode * tx = ptr;
				ptr = temp->next;
				delete tx;
			}
			else
			{
				temp = temp->next;
				ptr = ptr->next;
			}
		}
		return head;
	}
};

int main(int argc, char* argv[])
{
	Solution x;
	ListNode xd(1);
	xd.next = new ListNode(1);/*
	xd.next->next = new ListNode(3);
	xd.next->next->next = new ListNode(3);
	xd.next->next->next->next = new ListNode(2);
	xd.next->next->next->next->next = new ListNode(3);*/
	ListNode * rtn = x.removeElements(&xd, 1);
	while (rtn != NULL)
	{
		cout << rtn->val << "->";
		rtn = rtn->next;
	}
	
	return 0;
}