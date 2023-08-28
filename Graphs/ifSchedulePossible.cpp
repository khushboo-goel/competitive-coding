// https://leetcode.com/problems/course-schedule/description/

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    if (numCourses == 0 || numCourses == 1) {
        return true;
    }

    vector<vector<int>> graph(numCourses, vector<int>(numCourses, 0));
    vector<int> indegree(numCourses, 0);
    for(int i = 0; i < prerequisites.size(); i++) {
        if (prerequisites[i][0] == prerequisites[i][1]) {
            return false;
        }
        graph[prerequisites[i][0]][prerequisites[i][1]] = 1;
        indegree[prerequisites[i][1]] ++;
    }

    bool startFound = false;
    deque<int> courses;

    for(int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            startFound = true;
            courses.push_back(i);
        }
    }

    if (!startFound) {
        return false;
    }
    int nodeVisited = 0;

    while(!courses.empty()) {
        int size = courses.size();
        while(size > 0) {
            int course = courses.front();
            courses.pop_front();
            nodeVisited++;
            for(int i = 0; i < numCourses; i++) {
                if (graph[course][i] == 1){
                    indegree[i]--;
                    if (indegree[i] == 0) {
                        courses.push_back(i);
                    }
                }
            }
            size --;
        }
    }

    return (nodeVisited == numCourses);
}
