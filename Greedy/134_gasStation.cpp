// https://leetcode.com/problems/gas-station/?envType=list&envId=pcxjbubg
// https://www.youtube.com/watch?v=tcOcmNHFTTM
// seems like a version of kadane algorithm

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();

    int currCost = 0;
    int index = 0;
    int totalGain = 0;
    for (int i = 0; i < n; i++) {
        currCost += gas[i] - cost[i];
        totalGain += gas[i] - cost[i];
        if (currCost < 0) {
            index = i + 1;
            currCost = 0;
        }
    }
    return totalGain < 0 ? -1 : index;
}
