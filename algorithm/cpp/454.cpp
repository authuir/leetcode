#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
//	unordered_map<int, int>  abSum;
//	for (auto a : A) {
//		for (auto b : B) {
//			++abSum[a + b];
//		}
//	}
//	int count = 0;
//	for (auto c : C) {
//		for (auto d : D) {
//			auto it = abSum.find(0 - c - d);
//			if (it != abSum.end()) {
//				count += it->second;
//			}
//		}
//	}
//	return count;
//}

class Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		int rtn = 0;
		unordered_map<int, int> statistics;
		for (int i_a = 0; i_a < A.size(); i_a++)
			for (int i_b = 0; i_b < A.size(); i_b++)
			{
				statistics[A[i_a] + B[i_b]] ++;
			}

		for (int i_c = 0; i_c < C.size(); i_c++)
			for (int i_d = 0; i_d < D.size(); i_d++)
			{
				if (statistics[0 - C[i_c] - D[i_d]] >0)
				{
					statistics[0 - C[i_c] - D[i_d]];
					rtn = rtn + statistics[0 - C[i_c] - D[i_d]];
				}
			}

		return rtn;
	}
};

int main()
{
	Solution x;
	x.fourSumCount(vector<int>{-1, -1}, vector<int>{-1, 1}, vector<int>{-1, 1}, vector<int>{1, -1});
	return 0;
}