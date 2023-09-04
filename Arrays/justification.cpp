// https://leetcode.com/problems/text-justification/
vector<string> fullJustify(vector<string>& words, int maxWidth) {
    int n = words.size();
    vector<string> result;
    queue<string> wordsInLine;

    int wordsPerLine = 1;
    int charPerLine = words[0].length();
    wordsInLine.push(words[0]);

    for(int i = 1; i < n; i++) {
        if (charPerLine + wordsPerLine + words[i].length() <= maxWidth) {
            wordsInLine.push(words[i]);
            charPerLine += words[i].length();
            wordsPerLine++;
        } else {
            int spaces = maxWidth - charPerLine;
            int perWordGap = 0;
            
            string currLine = "";
            while(!wordsInLine.empty()) {
                if (wordsPerLine > 2) {
                    perWordGap = (spaces + wordsPerLine - 2) / (wordsPerLine - 1);
                } else {
                    perWordGap = spaces;
                }
                string currWord = wordsInLine.front();
                wordsInLine.pop();
                wordsPerLine--;
                currLine += currWord;
                if(spaces > 0) {
                    currLine += " ";
                    spaces --;
                    for (int i = 0; i < perWordGap - 1 && spaces > 0; i++) {
                        currLine += " ";
                        spaces --;
                    }
                }
            }
            result.push_back(currLine);
            wordsPerLine = 1;
            charPerLine = words[i].length();
            wordsInLine.push(words[i]);
        }
    }

    int spaces = maxWidth - charPerLine;
    string currLine = "";
    while(!wordsInLine.empty()) {   
        string currWord = wordsInLine.front();
        wordsInLine.pop();
        currLine += currWord;
        if (spaces > 0) {
            currLine += " ";
        }
        spaces--;
    }
    while(spaces > 0) {
        currLine += " ";
        spaces--;
    }
    result.push_back(currLine);

    return result;
}
