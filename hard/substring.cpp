class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.empty()) return res;
        int n = s.size();
        int m = words.size();
        int len = words[0].size();
        int totalLen = m * len;
        if (totalLen > n) return res;
        unordered_map<string, int> req;
        for (auto& w : words) req[w]++;
        for (int k = 0; k < len; k++) {
            unordered_map<string, int> cur;
            int count = 0;
            int start = k;
     
            for (int i = 0; i < m && start + i * len + len <= n; i++) {
                string sub = s.substr(start + i * len, len);
                if (req.count(sub)) {
                    cur[sub]++;
                    if (cur[sub] == req[sub]) count++;
                    else if (cur[sub] == req[sub] + 1) count--;
                }
            }
            if (count == (int)req.size()) res.push_back(start);
          
            while (start + totalLen + len <= n) {
    
                string left = s.substr(start, len);
                if (req.count(left)) {
                    if (cur[left] == req[left]) count--;
                    cur[left]--;
                    if (cur[left] == req[left]) count++;
                }
                start += len;
           
                string right = s.substr(start + (m - 1) * len, len);
                if (req.count(right)) {
                    if (cur[right] == req[right]) count--;
                    cur[right]++;
                    if (cur[right] == req[right]) count++;
                }
                if (count == (int)req.size()) res.push_back(start);
            }
        }
        return res;
    }
};
