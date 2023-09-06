// https://leetcode.com/problems/find-good-days-to-rob-the-bank/description/

vector<int> goodDaysToRobBank(vector<int>& security, int time) {
    int days = security.size();
    vector<int> res;
    if (days == 0){
        return res;
    }

    vector<int> leftSub(days, 0);
    vector<int> rightSub(days, 0);

    int counter = 1;
    for (int i = 1; i < days; i++) {
        if (security[i - 1] >= security[i]) {
            leftSub[i] = counter;
            counter++;
        } else {
            counter = 1;
        }
    }

    for (int i = days - 2; i >= 0; i--) {
        if (security[i + 1] >= security[i]) {
            rightSub[i] = counter;
            counter++;
        } else {
            counter = 1;
        }
    }

    vector<int> result;
    for (int i = time; i < days - time; i++) {
        if (leftSub[i] >= time && rightSub[i] >= time) {
            result.push_back(i);
        }
    }

    return result;
}
