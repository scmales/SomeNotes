class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return (a[0] - a[1]) < (b[0] - b[1]);
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // 假设一开始都飞往B地，然后公司改主意安排N人飞往A地，
        // 对于这些人，飞往B地的钱节约下来了，飞往A地的钱要支出
        // 于是公司要尽量少花费钱，取price_A - price_B最小的N个飞往A地
        sort(costs.begin(), costs.end(), cmp);
        int sum = 0;
        int len = costs.size();
        for(int i = 0; i < len; i++)
        {
            if(i < len/2)
                sum += costs[i][0];
            else
                sum += costs[i][1];
        }
        return sum;
    }
};