#include <iostream>
using namespace std;

class MyStack {
private:
	int ptr;
	int data[10000];
public:
	/** Initialize your data structure here. */
	MyStack() {
		ptr = 0;
	}

	/** Push element x onto stack. */
	void push(int x) {
		data[ptr] = x;
		ptr++;
		/*if (ptr >= 10000)
			return;*/
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		if (ptr <= 0) return NULL;
		int rtn = data[ptr - 1];
		ptr--;
		return rtn;
	}

	/** Get the top element. */
	int top() {
		if (ptr <= 0) return NULL;
		return data[ptr - 1];
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		if (ptr <= 0) return true;
		else return false;
	}
};

int main()
{
	MyStack obj;
	obj.push(1);
	int param_2 = obj.pop();
	int param_3 = obj.top();
	bool param_4 = obj.empty();
	return 0;
}