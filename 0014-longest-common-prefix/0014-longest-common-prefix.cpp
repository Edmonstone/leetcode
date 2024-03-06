struct Node{
    Node* links[26];
    bool flag = false;
    int prefix = 0;
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }
    
    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL);
    }
    
    Node* get(char ch){
        return links[ch - 'a'];
    }
    
    void setEnd(){
        flag = true;
    }
    void increasePrefix(){
        prefix++;
    }
    int getPrefix(){
        return prefix;
    }
    
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Node* root = new Node();
        for(auto &word : strs){
            Node* node = root;
            for(int i=0;i<word.length();i++){
                if(!node->containsKey(word[i])){
                    node->put(word[i], new Node());
                }
                node = node->get(word[i]);
                node->increasePrefix();
            }
            node->setEnd();
        }
        int n = strs.size();
        string longestPrefix = "";
        for(auto &word : strs){
            Node* node = root;
            string prefix = "";
            for(int i=0;i<word.length();i++){
                if(node->containsKey(word[i])){
                    node = node->get(word[i]);
                    if(node->getPrefix() == n){
                        prefix +=word[i];
                    }else{
                        break;
                    }
                }
            }
            if(longestPrefix < prefix){
                longestPrefix = prefix;
            }
        }
        return longestPrefix;
    }
};