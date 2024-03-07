// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

int numPairsDivisibleBy60(vector<int>& time) {
    int n = time.size();
    map<int, int> count;

    for(int i = 0; i < n; i++) {
        count[time[i]]++;
    }

    int totalPair = 0;
    
    for(map<int, int>:: iterator itr = count.begin(); itr != count.end(); itr ++) {
        int currTime = itr -> first;
        int currCount = itr -> second;
        if (currTime % 60 == 0 || currTime % 60 == 30) {
            totalPair += (currCount * (long long)(currCount - 1)) / 2;
        }
        int searchTime = 60 * ((currTime + 60) / 60) - currTime;
        while(searchTime <= 500) {
            if (searchTime > currTime && count.find(searchTime) != count.end()) {
                totalPair += currCount * count[searchTime];
            }
            searchTime += 60;
        }
    }

    return totalPair;
}
