// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/?envType=list&envId=pcxjbubg

int minAddToMakeValid(string s) {
    int n = s.length();

    stack<char> stk;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            stk.push(s[i]);
        } else {
            if (!stk.empty() && stk.top() == '(') {
                stk.pop();
            } else {
                stk.push(s[i]);
            }
        }
    }

    return stk.size();
}
