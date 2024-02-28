class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int remainder = target - nums[i];
            if (mp.find(remainder) != mp.end()) {
                return {mp[remainder], i};
            }
            mp[nums[i]] = i;
        }
        return {-1, -1};
    }
};