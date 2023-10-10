// https://leetcode.com/problems/koko-eating-bananas/description/
// NOTE: Pay attention at the ceil function

int minEatingSpeed(vector<int>& piles, int h) {
    int len = piles.size();

    if (len == 1) {
        return ceil((double)piles[0] / h);
    }
    long long maxBananas = 0;

    for (int i = 0; i < len; i++) {
        maxBananas += piles[i];
    }

    long long start = 1;
    long long end = maxBananas;

    long long k = maxBananas;

    while(start < end) {
        long long mid = start + (end - start) / 2;

        long long hoursTaken = 0;
        for (int i = 0; i < len; i++) {
            hoursTaken += (long long)((piles[i] / mid) + (piles[i] % mid != 0));
        }

        if (hoursTaken > h) {
            start = mid + 1;
        } else {
            k = min(k, mid);
            end = mid;
        }
    }

    return k;
}
