// https://leetcode.com/problems/encode-and-decode-tinyurl/

class Solution {
public:
    string defaultStr = "http://tinyurl.com/";
    map<string, string> encoding;
    map<string, string> decoding;
    int count = 0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (encoding.find(longUrl) == encoding.end()) {
            string generatedUrl = defaultStr + to_string(count);
            encoding[longUrl] = generatedUrl;
            decoding[generatedUrl] = longUrl;
            count++;
            return generatedUrl;
        } else {
            return encoding[longUrl];
        }
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return decoding[shortUrl];
    }
};
