// https://leetcode.com/problems/powx-n/
double myPow(double x, long long n) {
    if (n == 0) {
        return (double)(1);
    }
    if (x == (double)1) {
        return x;
    }
    if (n < 0) {
        return myPow(1/x, abs(n));
    }
    if (n % 2 != 0) {
        return x * myPow(x, n - 1);
    } else {
        double val = myPow(x, n/2);
        return val * val;
    }
}
