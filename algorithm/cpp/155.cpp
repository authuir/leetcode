#include <iostream>
#include <vector>

using namespace std;

#define MAX_NUMS 1000

class MinStack {
public:
	/** initialize your data structure here. */
	int ptr = 0;
	int arr[MAX_NUMS];

	MinStack() {

	}

	void push(int x) {
		arr[ptr] = x;
		ptr++;
		if (ptr >= MAX_NUMS) ptr--;
	}

	void pop() {
		if (ptr == 0) return;
		ptr--;
	}

	int top() {
		if (ptr == 0) return NULL;
		return arr[ptr-1];
	}

	int getMin() {
		if (ptr == 0) return NULL;
		int rtn = arr[0];
		for (int i = 1; i < ptr; i++)
		{
			if (rtn > arr[i])
				rtn = arr[i];
		}
		return rtn;
	}
};

int main()
{
	MinStack minStack =  MinStack();
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);
	cout << minStack.getMin();
	minStack.pop();
	cout << minStack.top();
	cout << minStack.getMin();
	return 0;
}