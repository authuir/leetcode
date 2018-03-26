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
	ListNode* reverseList(ListNode* head) {
		if (head == NULL) return NULL;
		vector<int> value;
		do
		{
			value.push_back(head->val);
			if (head->next == NULL)
			{
				delete head;
				break;
			}
			head = head->next;
		} while (true);
		head = new ListNode(value.back());
		value.pop_back();
		ListNode * temp = head;
		while (!value.empty())
		{
			temp->next = new ListNode(value.back());
			temp = temp->next;
			value.pop_back();
		}
		return head;
	}
};

int main(int argc, char* argv[])
{
	Solution x;
	ListNode hd(1);
	hd.next = new ListNode(2);
	hd.next->next = new ListNode(3);

	cout << x.reverseList(&hd);
	return 0;
}