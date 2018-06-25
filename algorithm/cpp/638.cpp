#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <utility>  
#include <string>

using namespace std;

namespace std
{
    template<>
    struct hash<std::vector<int>>
    {
        size_t operator()(std::vector<int> const& v) const
        {
			size_t ret = 0;
			for(auto& i : v) {
				ret ^= hash<int>()(i);
			}
			return ret;
        }
    };
}


class Solution {
public:
	bool isEmptyInput(vector<int>& input) {
		for (auto iter : input) {
			if (iter > 0)
				return false;
		};
		return true;
	}

	bool isGetable(vector<int>& offer, vector<int>& require)
	{
		for (int i=0; i<require.size(); i++)
		{
			if (offer[i] > require[i])
				return false;
		}
		return true;
	}

	void getDp(vector<int>& price, vector<vector<int>>& offer, pair<vector<int>, int> input) {
		auto find_result = dp.find(input.first);
		if (find_result != dp.end()) {
			if (find_result->second > input.second ) {
				find_result->second = input.second;
			} else {
				return ;
			}
		} else {
			dp.insert(input);
		}

		if (isEmptyInput(input.first))
			return;

		for ( auto iter : input.first )
			cout << iter << '\t';
		cout << "price: " << input.second << endl;
		int flag = 1;
		for (auto iter : offer) {
			if (isGetable(iter, input.first)) {
				vector<int> tmp = input.first;
				for (int i=0; i<tmp.size(); i++) {
					tmp[i] = tmp[i] - iter[i];
				}
				getDp(price, offer, make_pair(tmp, input.second + iter.back()));
				flag = 0;
			}
		}
		if (flag == 1) {
			int rtn = input.second;
			for (int i = 0; i<price.size(); i++)
				rtn += price[i] * input.first[i];
			vector<int> to_find(price.size(), 0);
			getDp(price, offer, make_pair(to_find, rtn));
		}
	}

	int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
		for (auto iter = special.begin(); iter != special.end(); ) {
			int price_sum = 0;
			for (int i=0; i<price.size(); i++) {
				price_sum += price[i] * (*iter)[i];
			}
			if (price_sum < (*iter).back()) {
				iter = special.erase(iter);
			} else {
				iter ++;
			}
		}

		getDp(price, special, make_pair(needs, 0));

		vector<int> to_find(price.size(), 0);
		auto rtn = dp.find(to_find);
		if (rtn != dp.end())
			return rtn->second;
		return 0;
	}

private:
    unordered_map<vector<int>, int> dp;
};

int main()
{
	Solution x;
	vector<int> s1{9,9,7,2,1,3};

	vector<vector<int>> s2;
	s2.push_back(vector<int>{5,2,6,0,0,2,26});
	s2.push_back(vector<int>{1,3,2,0,0,6,17});
	s2.push_back(vector<int>{5,2,2,2,0,5,15});
	s2.push_back(vector<int>{4,0,0,4,3,4,30});

	vector<int> s3{6,3,1,4,5,1};
	cout << x.shoppingOffers(s1, s2, s3) << endl;
	return 0;
}
