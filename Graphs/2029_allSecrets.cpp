// https://leetcode.com/problems/find-all-people-with-secret/
class sortQueue {
    public:
        bool operator()(pair<int, int> &a, pair<int, int> &b) {
            return a.second == b.second ? a.first > b.first : a.second > b.second;
        }
};
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int, int>>> graph(n);
        graph[0].push_back(make_pair(firstPerson, 0));
        graph[firstPerson].push_back(make_pair(0, 0));
        for (int i = 0; i < meetings.size(); i++) {
            graph[meetings[i][0]].push_back({meetings[i][1], meetings[i][2]});
            graph[meetings[i][1]].push_back({meetings[i][0], meetings[i][2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, sortQueue> people;
        people.push(make_pair(0, 0));
        people.push(make_pair(firstPerson, 0));
        vector<int> visited(n, 0);

        while(!people.empty()) {
            pair<int, int> curr = people.top();
            int time = curr.second;
            int person = curr.first;
            people.pop();
            if (visited[person]) {
                continue;
            }
            visited[person] = 1;
            for (int i = 0; i < graph[person].size(); i++) {
                if (graph[person][i].second >= time && visited[graph[person][i].first] == 0) {
                    people.push({ graph[person][i].first, graph[person][i].second });
                }
            }
        }

        vector<int> result;
        for(int i = 0; i < n; i++) {
            if (visited[i]) {
                result.push_back(i);
            }
        }
        return result;
    }
};
