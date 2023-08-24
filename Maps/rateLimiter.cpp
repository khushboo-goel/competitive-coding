class Logger {
public:
    map<string, int> loggedMsg;
    int t;
    Logger() {
        t = 10;
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (loggedMsg.find(message) == loggedMsg.end()) {
            loggedMsg[message] = timestamp;
            return true;
        } else {
            if (loggedMsg[message] + t <= timestamp) {
                loggedMsg[message] = timestamp;
                return true;
            }
        }

        return false;
    }
};

// https://leetcode.com/problems/logger-rate-limiter/description/
