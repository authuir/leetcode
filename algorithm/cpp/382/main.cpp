/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
private:
	int listsize = 0;
	ListNode* s_head;

public:
	/** @param head The linked list's head.
	Note that the head is guaranteed to be not null, so it contains at least one node. */
	Solution(ListNode* head) {
		ListNode* tmp = head;
		this->s_head = head;

		while (tmp != NULL)
		{
			tmp = tmp->next;
			listsize++;
		}

	}

	/** Returns a random node's value. */
	int getRandom() {
		if (listsize == 0)
			return 0;
		random_device rd;
		ListNode* tmp = this->s_head;
		int index = rd() % listsize;
		for (int i = 0; i<index; i++)
		{
			tmp = tmp->next;
		}
		return tmp->val;
	}
};

/**
* Your Solution object will be instantiated and called as such:
* Solution obj = new Solution(head);
* int param_1 = obj.getRandom();
*/