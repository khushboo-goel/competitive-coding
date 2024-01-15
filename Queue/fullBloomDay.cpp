// https://leetcode.com/problems/earliest-possible-day-of-full-bloom/description/

int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
    int n = plantTime.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, sortQueue> scheduler;

    int timestamp = 0;
    for (int i = 0; i < n; i++) {
        scheduler.push(make_pair(plantTime[i], growTime[i]));
    }

    int minTime = INT_MIN;
    while (!scheduler.empty()) {
        pair<int, int> plant = scheduler.top();
        minTime = max(minTime, plant.first + plant.second + timestamp);
        timestamp += plant.first;
        scheduler.pop();
    }
    return minTime;
}
