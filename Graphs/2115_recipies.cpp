// https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/?envType=list&envId=pcxjbubg
vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
    int n = recipes.size();
    unordered_map<string, int> catalogue;
    unordered_map<int, string> reverse;

    for(int i = 0; i < n; i++) {
        catalogue[recipes[i]] = i;
        reverse[i] = recipes[i];
    }

    set<string> all;
    for(int i = 0; i < supplies.size(); i++) {
        all.insert(supplies[i]);
    }

    vector<vector<int>> graph(n, vector<int>(0));
    vector<int> inbound(n, 0);

    for (int i = 0; i < n; i++) {
        vector<int> related(0);
        bool missing = false;
        for (int j = 0; j < ingredients[i].size(); j++) {
            if (all.find(ingredients[i][j]) == all.end()) {
                if (catalogue.find(ingredients[i][j]) == catalogue.end()) {
                    missing = true;
                    inbound[i] = INT_MIN;
                    break;
                }
                if (catalogue.find(ingredients[i][j]) != catalogue.end()) {
                    related.push_back(catalogue[ingredients[i][j]]);
                }
            }
        }
        if (!missing) {
            for (int j = 0; j < related.size(); j++) {
                graph[related[j]].push_back(i);
                inbound[i] ++;
            }
        }
    }

    queue<int> q;

    for (int i = 0; i < n; i++) {
        if (inbound[i] == 0) {
            q.push(i);
        }
    }

    vector<string> list;
    while(!q.empty()) {
        int size = q.size();
        while(size > 0) {
            size --;
            int recipe = q.front();
            q.pop();
            list.push_back(reverse[recipe]);
            for (int i = 0; i < graph[recipe].size(); i++) {
                inbound[graph[recipe][i]] --;
                if (inbound[graph[recipe][i]] == 0) {
                    q.push(graph[recipe][i]);
                }
            }
        }
    }

    return list;
}
