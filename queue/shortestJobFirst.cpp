bool compare(vector<int> &a, vector<int> &b) {
    return a[1] < b[1];
}

struct sortQueue{
    bool operator()(pair<int, int> &a, pair<int, int> &b){
        return (a.first == b.first) ? a.second > b.second : a.first > b.first;
    }
};

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int len = tasks.size();

        vector<vector<int>> scheduledJobs;
        for(int i = 0; i < len; i++) {
            vector<int> vals;
            vals.push_back(i);
            vals.push_back(tasks[i][0]);
            vals.push_back(tasks[i][1]);
            scheduledJobs.push_back(vals);
        }
        // sort tasks based on the enqueue time in asc order
        sort(scheduledJobs.begin(), scheduledJobs.end(), compare);
        vector<int> result;
        priority_queue<pair<int, int>, vector<pair<int, int>>, sortQueue> availJobs;

        long long j = 1; // enqueue time
        int i = 0; // job number
        int jobsComplete = 0;
        while(jobsComplete < len) {
            while(i < len && scheduledJobs[i][1] <= j) {
                pair<int, int> job;
                job.first = scheduledJobs[i][2];
                job.second = scheduledJobs[i][0];
                availJobs.push(job);
                i++;
            }

            // pick first job
            if (!availJobs.empty()) {
                pair<int, int> processedJob = availJobs.top();
                availJobs.pop();
                result.push_back(processedJob.second);
            
                j += processedJob.first;
                jobsComplete++;
            } else {
                j = scheduledJobs[i][1];
            }
        }

        return result;
    }
};

// https://leetcode.com/problems/single-threaded-cpu/description/
