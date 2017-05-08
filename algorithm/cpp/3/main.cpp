#include <string>
#include <list>
#include <map>

using namespace std;


int judge_is_in(list<char> q_in, char ch)
{
	int rtn = -1;
	while(!q_in.empty())
	{
		rtn++;
		if (ch == q_in.front())
			return rtn;
		else
			q_in.pop_front();
	}
	return -1;
}

void pop_x(list<char> * q_in, int ch)
{
	while (ch-- > 0)
	{
		q_in->pop_front();
	}
}


class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int cnt = 0;
		int max = 0;
		list<char> q;
			
		while (cnt < s.length())
		{
			int tp = judge_is_in(q, s[cnt]);
			if (tp == -1)
			{
				q.push_back(s[cnt]);
				cnt++;
			}
			else
			{
					
				int tmp_cnt = max - q.size() + tp + 1;
				int tmp_tp = 0;
				pop_x(&q, tp + 1);

				while ( q.size() < (max+1) && (cnt < s.length()))	//凑够max+1个数 或者 后面不够了
				{
					tmp_tp = judge_is_in(q, s[cnt]);

					if (tmp_tp >= 0)
					{
						pop_x(&q, tmp_tp + 1);
					}

					q.push_back(s[cnt]);
					cnt++;
				}
			}
			max = q.size() > max ? q.size() : max;	//保持最大max
		}

		return max;
		
	}
};

int main()
{
	Solution * ss = new Solution();
	int a = ss->lengthOfLongestSubstring("arwvivbgvtybtnudd") ;
	 a = ss->lengthOfLongestSubstring("aa");
	 a = ss->lengthOfLongestSubstring("abc");
	 a = ss->lengthOfLongestSubstring("abca");
	 a = ss->lengthOfLongestSubstring("abcad");
	int b = a;
	/*list<char> test;
	test.push('a');
	test.push('b');
	test.push('c');
	test.push('d');
	test.push('e');
	a = judge_is_in(test, 'x');
	pop_x(&test*, 3);
	b = a;*/
}