// https://leetcode.com/problems/meeting-rooms-iii/description/

class sortSched {
    public:
        bool operator()(pair<long long,pair<long, long>> &a, pair<long long,pair<long, long>> &b) {
            return a.first > b.first;
        }
};

class Solution {
  public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<pair<long long,pair<long, long>>, vector<pair<long long, pair<long, long>>>, sortSched> schedule;

        vector<int> noOfMeetings(n , 0);
        vector<long long> emptyTime(n, 0);
        for (int i = 0; i < meetings.size(); i++) {
            schedule.push(make_pair(meetings[i][0], make_pair(meetings[i][0], meetings[i][1])));
        }

        while(!schedule.empty()) {
            pair<long long, pair<long, long>> meeting = schedule.top();
            schedule.pop();

            bool scheduled = false;
            long long minTime = LLONG_MAX;
            for (int i = 0; i < n; i++) {
                if (emptyTime[i] <= meeting.second.first) {
                    emptyTime[i] = meeting.second.second;
                    noOfMeetings[i] ++;
                    scheduled = true;
                    break;
                }
                minTime = minTime < emptyTime[i] ? minTime : emptyTime[i];
            }
            if (!scheduled) {
                long long timeDiff = minTime - meeting.second.first;
                schedule.push(make_pair(meeting.first, make_pair(minTime, meeting.second.second + timeDiff)));
            }
        }

        long long maxRoom = 0;
        for (int i = 0; i < n; i++) {
            if (noOfMeetings[i] == noOfMeetings[maxRoom]) {
                maxRoom = i < maxRoom ? i : maxRoom;
            } else {
                maxRoom = noOfMeetings[i] > noOfMeetings[maxRoom] ? i : maxRoom;
            }
        }

        return maxRoom;
    }
};
