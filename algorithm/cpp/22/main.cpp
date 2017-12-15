class Solution {
private:
	vector<string> rtn;

	void travel(string input, int left_remain, int right_remain)
	{
		int count_of_left = count(input.begin(), input.end(), '(');
		int count_of_right = count(input.begin(), input.end(), ')');
		count_of_left = count_of_left - count_of_right;

		if (left_remain == 0 && right_remain == 0)
		{
			rtn.push_back(input);
		}
		else if (left_remain > 0 && right_remain == 0)
		{
			input.push_back('(');
			travel(input, left_remain - 1, right_remain);
		}
		else if (right_remain > 0 && left_remain == 0)
		{
			input.push_back(')');
			travel(input, left_remain, right_remain - 1);
		}
		else
		{
			if (count_of_left <= 0 && left_remain >0)
			{
				input.push_back('(');
				travel(input, left_remain - 1, right_remain);
			}
			else if (count_of_left <= 0 && left_remain <= 0)
			{
				return;
			}
			else
			{
				input.push_back('(');
				travel(input, left_remain - 1, right_remain);
				input.pop_back();
				input.push_back(')');
				travel(input, left_remain, right_remain - 1);
			}
		}
	}

public:
	vector<string> generateParenthesis(int n) {
		if (n <= 0)
			return this->rtn;
		if (n == 1)
		{
			this->rtn.push_back("()");
			return this->rtn;
		}

		travel("(", n - 1, n);
		return this->rtn;
	}
};