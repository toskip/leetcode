class Solution {
public:
    /**
     * @param buildings: A list of lists of integers
     * @return: Find the outline of those buildings
     */
    vector<vector<int>> buildingOutline(vector<vector<int>> &buildings) {
        // write your code here
        map<int,int> height;
        for(int i =0;i<buildings.size();i++)
        {
            buildings[i]
            height[buildings[i][0]] = max(height[buildings[i][0]],buildings[i][2]);
            height[buildings[i][1]] = min(height[buildings[i][1]],buildings[i][2]);
        }
        vector<<vector<int> > result;
        for(auto it:height)
        {
            vector<int> temp;
            temp.push_back(it->first);
            temp.push_back(0);
            temp.push_back(it->second);
            result.push_back(temp);
        }
        return result;
    }
};
