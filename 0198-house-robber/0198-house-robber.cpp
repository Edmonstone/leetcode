class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = nums[0];
        int prev2 = 0;
        for(int i=0;i<nums.size();i++){
            int rob = nums[i];
            if(i>1) rob += prev2;
            int not_rob = 0 + prev;
            int curr = max(rob,not_rob);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};