// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/

string minRemoveToMakeValid(string s) {
  int n = s.length();
  stack<pair<char, int>> brackets;
  for (int i = 0; i < n; i++) {
      if (s[i] == '(') {
          brackets.push(make_pair(s[i], i));
      } else if (s[i] == ')') {
          if (!brackets.empty() && brackets.top().first == '(') {
              brackets.pop();
          } else {
              brackets.push(make_pair(s[i], i));
          }
      }
  }

  unordered_map<int, bool> remove;
  while(!brackets.empty()) {
      remove[brackets.top().second] = true;
      brackets.pop();
  }

  string result = "";
  for (int i = 0; i < n; i++) {
      if (remove.find(i) == remove.end()) {
          result += s[i];
      }
  }

  return result;
}
