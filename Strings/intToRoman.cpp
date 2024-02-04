// https://leetcode.com/problems/integer-to-roman/description/

string appendData(string c, int t) {
    string tmp = "";
    for (int i = 0; i < t; i++) {
        tmp += c;
    }
    return tmp;
}

string intToRoman(int num) {
    int value = num;
    string roman = "";

    while(value > 0) {
        int reps;
        if (value / 1000 >= 1) {
            int reps = value / 1000;
            roman += appendData("M", reps);
            value = value % 1000;
        } else if (value / 900 >= 1) {
            roman += appendData("CM", 1);
            value = value % 900;
        } else if (value / 500 >= 1) {
            int reps = value / 500;
            roman += appendData("D", reps);
            value = value % 500;
        } else if (value / 400 >= 1) {
            roman += appendData("CD", 1);
            value = value % 400;
        } else if (value / 100 >= 1) {
            int reps = value / 100;
            roman += appendData("C", reps);
            value = value % 100;
        } else if (value / 90 >= 1) {
            roman += appendData("XC", 1);
            value = value % 90;
        } else if (value / 50 >= 1) {
            int reps = value / 50;
            roman += appendData("L", reps);
            value = value % 50;
        } else if (value / 40 >= 1) {
            roman += appendData("XL", 1);
            value = value % 40;
        } else if (value / 10 >= 1) {
            int reps = value / 10;
            roman += appendData("X", reps);
            value = value % 10;
        } else if (value / 9 >= 1) {
            roman += appendData("IX", 1);
            value = value % 9;
        } else if (value / 5 >= 1) {
            int reps = value / 5;
            roman += appendData("V", reps);
            value = value % 5;
        } else if (value / 4 >= 1) {
            roman += appendData("IV", 1);
            value = value % 4;
        } else {
            roman += appendData("I", value);
            value = value % 1;
        }

    }
    return roman;
}
