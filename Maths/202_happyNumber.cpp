// https://leetcode.com/problems/happy-number/description/?envType=list&envId=pcxjbubg

bool isHappy(int n) {
    if (n == 1) {
        return true;
    }

    set<int> seenNums;
    int x = n;
    while(x > 1) {
        int sum = 0;
        while(x > 0) {
            int digit = x % 10;
            sum += digit * digit;
            x = x / 10;
        }
        if (seenNums.find(sum) == seenNums.end()) {
            x = sum;
            seenNums.insert(sum);
        } else {
            return false;
        } 
    }

    return true;
}
