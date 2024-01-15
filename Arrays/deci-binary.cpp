// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/description/

int minPartitions(string n) {
    char count = n[0];
    int len = n.length();

    for (int i = 1; i < len; i++) {
        if (count < n[i]) {
            count = n[i];
        }
    }

    return count - '0';
}
