class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double sum = 0;
        for(int num : nums){
            sum += num;
            pq.push(num);
        }
        double target = sum / 2;

        int count = 0;

        while(sum > target){
            double val = pq.top();
            pq.pop();
            sum = sum - (val/2);
            pq.push(val/2);
            count++;
        }
        return count;
    }
};