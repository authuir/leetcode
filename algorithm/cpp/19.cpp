#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		int llen = 1;
		ListNode*tmp = head;
		ListNode* prv = tmp,* thi = tmp;
		while (tmp->next != NULL)
		{
			llen++;
			tmp = tmp->next;
		}
		if (n > llen)
		{
			return head;
		}

		tmp = head;
		for (int i = 0; i < llen; i++)
		{
			if (i == (llen - n - 1))
			{
				prv = tmp;
			}
			else if (i == (llen - n) && (i!=0))
			{
				prv->next = tmp->next;
				break;
			}
			else if (i == (llen - n) && (i == 0))
			{
				head = head->next;
				break;
			}

			tmp = tmp->next;
		}
		return head;
	}
};

int main(int argc, char * argv[])
{
	Solution x;
	ListNode header(1);
	ListNode * p = & header;
	p->next = new ListNode(2);p = p->next;
	/*p->next = new ListNode(3);p = p->next;
	p->next = new ListNode(4);p = p->next;*/
	x.removeNthFromEnd(&header,2);
	return 0;
}