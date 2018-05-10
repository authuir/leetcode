class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int size = candies.size() / 2;
        unordered_set<int> candy_sets;
        for (auto iter : candies)
        {
            candy_sets.insert(iter);
        }
        int candy_size = candy_sets.size();
        return min(size, candy_size);
    }
};