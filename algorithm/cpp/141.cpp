#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct ListNode {
	int val;
	ListNode * next;
	ListNode(int x) :val(x), next(NULL){};
};

class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head == NULL) return false;
		if (head->next == NULL) return false;
		vector<ListNode *> dst;
		dst.push_back(head);
		while (head->next != NULL)
		{
			if (find(dst.begin(), dst.end(), head->next) == dst.end())
				dst.push_back(head->next);
			else
				return true;
			head = head->next;
		}
		return false;
	}
};

int main()
{
	Solution x;
	ListNode head(1);
	head.next = new ListNode(2);
	//head.next->next = new ListNode(3);
	//head.next->next->next = new ListNode(3);
	cout << x.hasCycle(&head);
	return 0;
}