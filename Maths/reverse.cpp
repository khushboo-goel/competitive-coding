// https://leetcode.com/problems/reverse-integer/description/
// NOT the best approach since the question says environment doesnt support 64-bit integer and we used long long.

int reverse(int x) {
    long long reverse = 0;
    int number = x;

    while(number != 0) {
        int temp = (number) % 10;
        reverse = (reverse * 10) + temp;
        if (reverse > INT_MAX || reverse < INT_MIN) {
            return 0;
        }
        number = number / 10;
    }

    return (int)reverse;
}
