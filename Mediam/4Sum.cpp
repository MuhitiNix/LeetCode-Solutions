class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;          // To store the resulting quadruplets
        int n = nums.size();
        sort(nums.begin(), nums.end());   // Step 1: Sort the array
        
        for (int i = 0; i < n - 3; ++i) {            // Fix the first number
            if (i > 0 && nums[i] == nums[i - 1])     // Skip duplicates for first number
                continue;
            
            for (int j = i + 1; j < n - 2; ++j) {    // Fix the second number
                if (j > i + 1 && nums[j] == nums[j - 1])  // Skip duplicates for second number
                    continue;
                
                int left = j + 1, right = n - 1;     // Two pointers for the last two numbers
                
                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    
                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});  // Found quadruplet
                        
                        // Skip duplicates for left pointer
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        // Skip duplicates for right pointer
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        
                        left++;
                        right--;
                    }
                    else if (sum < target) {
                        left++;    // Need a larger sum
                    }
                    else {
                        right--;   // Need a smaller sum
                    }
                }
            }
        }
        
        return res;
