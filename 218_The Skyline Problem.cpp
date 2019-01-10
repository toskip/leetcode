//草这个傻逼代码我写了一整天终于过了，感觉根本就是照着答案拼凑出来的
class Solution {
public:
	vector<pair<int, int>> result;
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
		int startpos = 0;
		for (int i = 0; i < buildings.size(); i++)
		{
			while (startpos < result.size() && buildings[i][0] >= result[startpos].first)
			{
				startpos++;
			}
			//比较前面一个关键点和第i个建筑物起点哪个高
			if (startpos == 0 || buildings[i][2] >= result[startpos - 1].second)
			{
				
				if (startpos > 0 &&  buildings[i][0] == result[startpos - 1].first)
				{
					//把起点拔高
					result[startpos - 1].second = buildings[i][2];
				}
				else
				{
					//把起点作为关键点插入
					result.insert(result.begin() + startpos, make_pair(buildings[i][0], buildings[i][2]));
				}
			}
		//把第i个建筑物起点和终点之间低的点都拔高
			int endpos = startpos;
			int temp = -1;
			while (endpos < result.size() && buildings[i][1] > result[endpos].first)
			{
				if (buildings[i][2] > result[endpos].second)
				{
					temp = result[endpos].second;
					result[endpos].second = buildings[i][2];
				}
				endpos++;
			}
			if (endpos == result.size()) //第i个建筑物的终点在所有的关键点后面
			{
				//直接插到最后，加入关键点
				result.push_back(make_pair(buildings[i][1], 0));
			}
			else if(buildings[i][1] != result[endpos].first && buildings[i][2] >= result[endpos - 1].second)
			{
				//比较前面一个关键点和第i个建筑物终点哪个高
				//把终点作为关键点插入
				if (temp == -1) temp = result[startpos - 1].second;
				result.insert(result.begin() + endpos, make_pair(buildings[i][1], temp));
			}
		}
		//最后合并相同高度的关键点
		int i = 1;
		while(i<result.size())
		{
			int j = i;
			while (result[j].second == result[j - 1].second) j++;
			result.erase(result.begin()+i,result.begin()+j);
			i++;
		}
		return result;
	}
};
