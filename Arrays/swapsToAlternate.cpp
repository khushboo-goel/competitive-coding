// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/description/

int minSwaps(string s) {
    int n = s.length();

    int zero = 0;
    int ones = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            zero++;
        } else {
            ones++;
        }
    }

    if (abs(zero - ones) >= 2) {
        return -1;
    }

    int zeroNeeded = 0;
    int oneNeeded = 0;
    for (int i = 0; i < n; i += 2) {
        if (s[i] != '0'){
            zeroNeeded++;
        }
        if (s[i] != '1'){
            oneNeeded++;
        }
    }

    return ones == zero ? min(zeroNeeded, oneNeeded) : (ones > zero ? oneNeeded : zeroNeeded);
}
