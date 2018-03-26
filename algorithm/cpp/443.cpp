#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
public:
	int compress(vector<char>& chars) {
		int now = 0, ptr = 1;
		int cnt = 1, end = 0;
		char tmp[5] = { '\0' };
		if (chars.size() < 1)
			return 0;
		else if (chars.size() == 1)
			return 1;

		while (ptr <= chars.size())
		{
			if (ptr<chars.size() && chars[now] == chars[ptr])
			{
				cnt++;
				ptr++;
			}
			else
			{
				chars[end] = chars[now];
				end++;
				if (cnt <= 1)
				{
				}
				else
				{
					sprintf(tmp, "%d", cnt);
					for (int i = 0; ; i++)
					{
						if (tmp[i] == '\0')
							break;
						
						chars[end] = tmp[i];
						end++;
					}
				}
				now = ptr;
				ptr = ptr + 1;
				cnt = 1;
			}
		}

		return end;
	}
};

int main()
{
	Solution x;
	x.compress(vector<char>{'a', 'b', 'd', 'b', 'b', 'b', 'c', 'c'});

	return 0;
}