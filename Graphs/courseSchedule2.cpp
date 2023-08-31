vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> res;
    if (numCourses == 1) {
        res.push_back(0);
        return res;
    }

    vector<vector<int>> graph(numCourses, vector<int>(0));
    vector<int> indegree(numCourses, 0);

    for (int i = 0; i < prerequisites.size(); i++) {
        graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        indegree[prerequisites[i][0]]++;
    }

    deque<int> courseSeq;
    for (int i = 0; i < numCourses; i++){
        if (indegree[i] == 0) {
            courseSeq.push_back(i);
        }
    }
    
    while(!courseSeq.empty()) {
        int size = courseSeq.size();
        while(size > 0) {
            int course = courseSeq.front();
            courseSeq.pop_front();
            res.push_back(course);

            for (int i = 0; i < graph[course].size(); i++) {
                indegree[graph[course][i]] --;
                if (indegree[graph[course][i]] == 0){
                    courseSeq.push_back(graph[course][i]);
                }
            }
            size--;
        }
    }

    return res.size() == numCourses ? res : vector<int>(0);
}

// https://leetcode.com/problems/course-schedule-ii/
