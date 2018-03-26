class MyQueue {
private:
	int data[10000];
	int ptr_f = 0;
	int ptr_e = 0;

public:
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		if (((ptr_e + 1) != ptr_f) || (ptr_e + 1 - 10000) != ptr_f)
		{
			data[ptr_e] = x;
			ptr_e++; if (ptr_e == 10000) ptr_e = 0;
		}
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		if (ptr_e == ptr_f) return NULL;
		else {
			int rtn = data[ptr_f];
			ptr_f++; if (ptr_f == 10000) ptr_f = 0;
			return rtn;
		}
	}

	/** Get the front element. */
	int peek() {
		if (ptr_e == ptr_f) return NULL;
		else return data[ptr_f];
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		if (ptr_e == ptr_f) return true;
		return false;
	}
};

/**
* Your MyQueue object will be instantiated and called as such:
* MyQueue obj = new MyQueue();
* obj.push(x);
* int param_2 = obj.pop();
* int param_3 = obj.peek();
* bool param_4 = obj.empty();
*/