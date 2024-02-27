class Solution {
public:
    string removeDigit(string number, char digit) {
        string ans = "";
        int size = number.size();
        
        // Initialize index to -1 to represent no digit encountered yet
        int maxDigitIndex = -1;

        for (int i = 0; i < size; i++) {
            if (number[i] == digit) {
                // Update maxDigitIndex to the current index if it is greater
                if (maxDigitIndex == -1 || number[i] > number[maxDigitIndex]) {
                    maxDigitIndex = i;
                }
            }
        }

        // Remove the maximum digit encountered
        if (maxDigitIndex != -1) {
            ans = number.substr(0, maxDigitIndex) + number.substr(maxDigitIndex + 1, size - maxDigitIndex - 1);
        }

        return ans;
    }
};
