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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == NULL || headB == NULL)
			return NULL;
		ListNode * rtn = NULL;
		vector<ListNode *> listA,listB;
		listA.push_back(headA);
		listB.push_back(headB);
		while (listA.back()->next != NULL)
		{
			listA.push_back(listA.back()->next);
		}
		while (listB.back()->next != NULL)
		{
			listB.push_back(listB.back()->next);
		}
		if (listA.back() != listB.back())
			return NULL;
		while (listA.back() == listB.back())
		{
			rtn = listA.back();
			listA.pop_back();
			listB.pop_back();
			if (listA.size() == 0 || listB.size() == 0)
				break;
		}
		return rtn;
	}
};

int main(int argc, char * argv[])
{
	Solution x;
	ListNode A(1);
	A.next = new ListNode(2);
	A.next->next = new ListNode(2);
	ListNode* B = &A;
	ListNode * ccc = x.getIntersectionNode(&A,B);
	cout << ccc->val <<endl;
	cout << &ccc << endl;
	return 0;
}