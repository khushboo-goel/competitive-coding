// https://leetcode.com/problems/design-authentication-manager/description/
class AuthenticationManager {
public:
    map<string, int> tokens;
    int timer;
    AuthenticationManager(int timeToLive) {
        timer = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        tokens[tokenId] = currentTime;
    }
    
    void renew(string tokenId, int currentTime) {
        if (tokens.find(tokenId) != tokens.end() && tokens[tokenId] + timer > currentTime) {
            tokens[tokenId] = currentTime;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int count = 0;
        for(map<string, int> :: iterator itr = tokens.begin(); itr != tokens.end(); itr ++) {
            if (itr -> second + timer > currentTime) {
                count++;
            }
        }

        return count;
    }
};
