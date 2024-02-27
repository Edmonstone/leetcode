class Solution {
public:
    string removeDigit(string number, char digit) {
        string ans = "";
        int size = number.size();
        for(int i=0;i < size ;i++){
            if(number[i] == digit){
                string temp = number.substr(0,i) + number.substr(i+1,size);
                if(ans.empty()){
                    ans = temp;
                }
                else{
                    if(temp > ans) ans = temp;
                }
            }
        }
        return ans;
    }
};
