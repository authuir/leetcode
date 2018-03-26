#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode * l = NULL;
		ListNode * n = NULL;
		ListNode * tmp = head;
		for (int i = 0;tmp != NULL; )
		{
			n = tmp->next;
			if (n != NULL)
			{
				tmp->next = n->next;
				n->next = tmp;
				if (l == NULL)
				{
					head = n;
				}
				else
				{
					l->next = n;
				}
				l = tmp;
				tmp = tmp->next;
			}
			else
			{
				break;
			}
		}
		return head;
	}
};

int main(int argc, char * argv[])
{
	Solution x;
	ListNode l1(1);
	/*l1.next = &ListNode(2);
	l1.next->next = &ListNode(3);
	l1.next->next->next = &ListNode(4);*/

	cout << x.swapPairs(&l1) << endl;
	return 0;
}
