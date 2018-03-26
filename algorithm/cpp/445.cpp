#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		vector<int> l1_v, l2_v;
		while (l1 != NULL)
		{
			l1_v.push_back(l1->val);
			l1 = l1->next;
		}
		while (l2 != NULL)
		{
			l2_v.push_back(l2->val);
			l2 = l2->next;
		}

		if (l1_v.size() == 0) return l2;
		if (l2_v.size() == 0) return l1;

		vector<int> lo;

		int adder = 0;
		int here = 0;
		vector<int> * remain_vec = NULL;
		int             here_vec = 0;

		for (int i = l1_v.size() - 1, j = l2_v.size() - 1; ; i--, j--)
		{
			here = l1_v[i] + l2_v[j] + adder;
			if (here > 9)
			{
				adder = here / 10;
				here = here % 10;
			}
			else {
				adder = 0;
			}
			lo.push_back(here);

			if (i == 0 && j != 0)
			{
				remain_vec = &l2_v;
				here_vec = j;
				break;
			}
			else if (i != 0 && j == 0)
			{
				remain_vec = &l1_v;
				here_vec = i;
				break;
			}
			else if (i == 0 && j == 0)
				break;
		}

		if (here_vec!=0)
		{
			here_vec--;
			while (here_vec >= 0)
			{
				here = (*remain_vec)[here_vec] + adder;
				if (here > 9)
				{
					adder = here / 10;
					here = here % 10;
				}
				else {
					adder = 0;
				}
				lo.push_back(here);
				here_vec--;
			}
		}

		if (adder != 0)
			lo.push_back(adder);

		ListNode* rtn = NULL;
		ListNode* tmp_ptr = NULL;
		for (int i = lo.size()-1; i >=0 ; i--)
		{
			if (rtn == NULL)
			{
				rtn = new ListNode(lo[i]);
				tmp_ptr = rtn;
			}
			else
			{
				tmp_ptr->next = new ListNode(lo[i]);
				tmp_ptr = tmp_ptr->next;
			}
		}
		return rtn;
	}
};

int main()
{
	Solution x;
	ListNode* n1 = new ListNode(1);
	n1->next = new ListNode(2);
	n1->next->next = new ListNode(3);
	n1->next->next->next = new ListNode(4);
	ListNode* n2 = new ListNode(9);
	n2->next = new ListNode(9);
	n2->next->next = new ListNode(9);
	n2->next->next->next = new ListNode(9);

	x.addTwoNumbers(n1, n2);
}