class Solution {
public:
	int findLUSlength(string a, string b) {
		int sizea = a.size();
		int sizeb = b.size();
		if (a == b)
			return -1;
		else
			if (sizea > sizeb)
				return sizea;
			else
				return sizeb;
	}
};