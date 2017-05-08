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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL && l2 == NULL)
			return false;
		else if (l1 == NULL)
			return l2;
		else if (l2 == NULL)
			return l1;

		ListNode * rtn, * tp,* t1, *t2 = NULL;
		t1 = l1;
		t2 = l2;
		if (t1->val < t2->val)
		{
			rtn = t1;
			t1 = t1->next;
		}
		else
		{
			rtn = t2;
			t2 = t2->next;
		}
		tp = rtn;		
		while (!(t1 == NULL && t2 == NULL))
		{
			if (t1 == NULL)
			{
				tp->next = t2;break;
			}
				
			else if (t2 == NULL)
			{
				tp->next = t1;break;
			}
			else
			{
				if (t1->val < t2->val)
				{
					tp ->next = t1;
					t1 = t1->next;
				}
				else
				{
					tp ->next = t2;
					t2 = t2->next;
				}
				tp = tp->next;
			}

		}
		return rtn;
	}
};

int main(int argc, char * argv[])
{
	Solution x;
	ListNode l1(1);
	l1.next = &ListNode(2);
	l1.next->next = &ListNode(3);
	l1.next->next->next = &ListNode(4);
	ListNode l2(2);
	cout << x.mergeTwoLists(&l1,&l2) << endl;
	return 0;
}
