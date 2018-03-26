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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode * r1 = NULL,*rr1 =NULL, *r2 = NULL, *rr2 = NULL;
		stack<int> s;
		while (l1 != NULL)
		{
			s.push(l1->val);
			l1 = l1->next;
		}
		while (!s.empty())
		{
			if (r1 == NULL)
				rr1 = r1 = new ListNode(s.top());
			else
			{
				r1->next = new ListNode(s.top());
				r1 = r1->next;
			}
			s.pop();
		}

		while (l2 != NULL)
		{
			s.push(l2->val);
			l2 = l2->next;
		}
		while (!s.empty())
		{
			if (r2 == NULL)
				rr2 = r2 = new ListNode(s.top());
			else
			{
				r2->next = new ListNode(s.top());
				r2 = r2->next;
			}
			s.pop();
		}

		ListNode * t1 = rr1,* t2 = rr2;
		ListNode * rtn,* tmp;
		tmp = rtn = NULL;
		int JW = 0;
		while ((t1 != NULL || t2 != NULL ) || JW != 0)
		{
			if (t1 == NULL && t2 == NULL)
			{
				tmp->next = new ListNode(JW);
				break;
			}
			else if (t1 != NULL && t2 != NULL)
			{
				int var = t1->val + t2->val + JW;
				JW = var / 10;
				t1 = t1->next;
				t2 = t2->next;

				if (rtn == NULL)
				{
					tmp = rtn = new ListNode(var % 10);
				}
				else
				{
					tmp->next = new ListNode(var % 10);
					tmp = tmp->next;
				}

			}
			else if (t1 != NULL)
			{
				if (rtn == NULL)
				{
					tmp = rtn = new ListNode((t1->val + JW) % 10);
				}
				else
				{
					tmp->next = new ListNode((t1->val + JW) % 10);
					tmp = tmp->next;
				}
				t1 = t1->next;
			}
			else if (t2 != NULL)
			{
				if (rtn == NULL)
				{
					tmp = rtn = new ListNode((t2->val + JW) % 10);
				}
				else
				{
					tmp->next = new ListNode((t2->val + JW) % 10);
					tmp = tmp->next;
				}
				t2 = t2->next;
			}
		}

		while (rtn != NULL)
		{
			s.push(rtn->val);
			rtn = rtn->next;
		}
		rtn = NULL;
		tmp = NULL;
		while (!s.empty())
		{
			if (rtn == NULL)
				rtn = tmp = new ListNode(s.top());
			else
			{
				tmp->next = new ListNode(s.top());
				tmp = tmp->next;
			}
			s.pop();
		}


		return rtn;
	}
};

int main(int argc, char * argv[])
{
	Solution x;
	ListNode a(2);
	a.next = new ListNode(4);
	a.next->next = new ListNode(3);
	 

	ListNode b(1);
	b.next = new ListNode(8);
	cout << x.addTwoNumbers(&a,&b);
	return 0;
}