// https://leetcode.com/problems/grumpy-bookstore-owner/
int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    int len = customers.size();

    int cost = 0;
    for(int i = 0; i < len; i++){
        if (grumpy[i] == 0){
            cost += customers[i];
        }
    }

    for (int i = 0; i < minutes; i++){
        if (grumpy[i] == 1){
            cost += customers[i];
        }
    }

    int maxCost = cost;
    for (int i = minutes; i < len; i++){
        cost = cost - (grumpy[i - minutes] == 1 ? customers[i - minutes]: 0) + (grumpy[i] == 1 ? customers[i]: 0);
        maxCost = max(maxCost, cost);
    }

    return maxCost;
}
