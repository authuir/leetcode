#include <iostream>
#include <string>
#include <stack>
#include <list>

using namespace std;

bool isOperator(char& c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')');
}

bool isOperand(char& c)
{
	return (c >= '0' && c <= '9');
}

double calcByoperator(char& op, double a, double b)
{
	switch (op)
	{
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a*b;
	case '/': return a / b;
	default: return 0.0;
	}
}

int getOperatorPriority(char& c)
{
	switch (c)
	{
	case '+': return 0;
	case '-': return 0;
	case '*': return 1;
	case '/': return 1;
	default: return 0;
	}
}

bool comparePriority(char& c1, char& c2)
{
	return (getOperatorPriority(c1) >= getOperatorPriority(c2));
}

double Calculator(string& expression)
{
	deque<char> sOperand;  //运算数
	stack<char> sOperator; //运算符

	for (auto c : expression)
	{
		if (isOperand(c))
			sOperand.push_back(c);
		else
		{
			if (c == '(')
				sOperator.push(c);
			else if (c == ')')
			{
				while (sOperator.top() != '(')
				{
					sOperand.push_back(sOperator.top());
					sOperator.pop();
				}
				sOperator.pop();
			}
			else
			{
				while (true)
				{
					if (sOperator.empty())
					{
						sOperator.push(c);
						break;
					}
					else if (sOperator.top() == '(')
					{
						sOperator.push(c);
						break;
					}
					else
					{
						if (comparePriority(c, sOperator.top()))
						{
							sOperator.push(c);
							break;
						}
						else
						{
							sOperand.push_back(sOperator.top());
							sOperator.pop();
						}
					}
				}
			}
		}
	}

	while (!sOperator.empty())
	{
		char op = sOperator.top();
		sOperand.push_back(op);
		sOperator.pop();
	}

	// 输出转换后的逆波兰表达式
	// while(!sOperand.empty())
	// {
	// 	cout<<sOperand.top()<<" ";
	// 	sOperand.pop();
	// }

	stack<double> rtn;

	while (!sOperand.empty())
	{
		char op = sOperand.front();

		if (isOperand(op))
		{
			rtn.push(double(op - '0'));
		}
		else if (isOperator(op))
		{
			double k1 = rtn.top(); rtn.pop();
			double k2 = rtn.top(); rtn.pop();
			rtn.push(calcByoperator(op, k2, k1));
		}
		sOperand.pop_front();
	}

	int a = rtn.size();

	return rtn.top();
}

int main(int argc, const char *argv[])
{
	string expr = string("((1+2)*3/4-5)*4");
	cout << Calculator(expr);

	return 0;
}
