// https://leetcode.com/problems/bulls-and-cows/?envType=list&envId=pcxjbubg
string getHint(string secret, string guess) {
    unordered_map<int, int> count;
    int cows = 0;
    int bulls = 0;

    for (int i = 0; i < secret.size(); i++) {
        if (secret[i] != guess[i]) {
            count[secret[i]] += 1;
        } else {
            bulls++;
        }
    }

    for (int i = 0; i < guess.size(); i++) {
        if (secret[i] != guess[i]) {
            if (count.find(guess[i]) != count.end() && count[guess[i]] > 0) {
                cows++;
                count[guess[i]] --;
            }
        }
    }

    return to_string(bulls) + "A" + to_string(cows) + "B";
}
