#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
	vector<int> data[2];
public:
	bool isPalindrome(ListNode* head) {
		if (head == NULL || head->next == NULL) return true;
		do {
			data[0].insert(data[0].begin(), head->val);
			data[1].push_back(head->val);
			head = head->next;
		} while (head != NULL);
		for (int i = 0; i<data[0].size(); i++)
		{
			if (data[0][i] != data[1][i])
				return false;
		}
		return true;
	}
};

int main()
{
	Solution x;
	ListNode * head = new ListNode(1);
	head->next = new ListNode(2);
	x.isPalindrome(head);
	return 0;
}