// https://leetcode.com/problems/climbing-stairs/description/

int climbStairs(int n) {
    if (n == 0 || n == 1 || n == 2) {
        return n;
    }

    int oneStepBack = 2;
    int twoStepBack = 1;
    int result;
    for (int i = 3; i <= n; i++) {
        result = twoStepBack + oneStepBack;
        twoStepBack = oneStepBack;
        oneStepBack = result; 
    }
    return result;
}
