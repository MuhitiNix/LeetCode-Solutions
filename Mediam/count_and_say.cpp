class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string prev = countAndSay(n - 1);
        string next = "";
        int len = prev.size();
        for (int j = 0; j < len; ) {
            char ch = prev[j];
            int count = 0;
            while (j < len && prev[j] == ch) {
                count++;
                j++;
            }
            next += to_string(count) + ch;
        }
        return next;
    }
};
