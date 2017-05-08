class Solution {
public:
	vector<int> constructRectangle(int area) {
		if (area == 1) return vector<int>{1, 1};
		float temp = sqrt(area);
		int x = floor(temp);
		while (area % x != 0)
		{
			x++;
		}
		int y = area / x;
		if (x < y)
		{
			int temp = y;
			y = x;
			x = temp;
		}
		return vector<int>{x, area / x};
	}
};