// https://leetcode.com/problems/reverse-integer/description/
// NOT the best approach since the question says environment doesnt support 64-bit integer and we used long long.

int reverse(int x) {
  int reverse = 0;
  int number = x;
  
  while(number != 0) {
    int temp = (number) % 10;
    if (reverse > INT_MAX / 10 || reverse < INT_MIN / 10) {
      return 0;
    }
    reverse = (reverse * 10) + temp;
    number = number / 10;
  }
  
  return (int)reverse;
}
