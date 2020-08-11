//--------
// 基本思路是贪心算法，时间从头开始算，当天先去参加最快要结束的那个会议，那些更晚结束的会议再找时间去参加
// ----
class Solution {
public:
const int MAX = 1e5 + 1;
int maxEvents(vector<vector<int>>& events)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int len = events.size();
    int cnt = 0;
    vector<vector<int>> log(MAX); //行下标代表会议开始的时间，每列的值代表结束时间
    for(int i = 0; i < len; i++)
    {
        log[events[i][0]].push_back(events[i][1]);
    }
    for(int i = 1; i < MAX; i++) {
        //对于每一天,若是当天开始的会议，把结束时间加到队列里；
       if (log[i].size() > 0) {
           for (int j = 0; j < log[i].size(); j++)
               pq.push(log[i][j]);
       }
        while (!pq.empty() && pq.top() < i) //若是已经结束了则从队列里去掉；
            pq.pop();
        if (!pq.empty()) { // 找一个最近时间结束的会议开会
            pq.pop();
            cnt++;
        }
    }
    return cnt;
}
};