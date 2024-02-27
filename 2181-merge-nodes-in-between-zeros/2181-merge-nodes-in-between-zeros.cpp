/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
         if (!head) return nullptr;

        while(head->val == 0) head = head->next;

        int sum = 0;
        ListNode *ansHead = NULL, *ansTail = NULL;

        while(head){
            if(head->val != 0){
                sum += head->val;
            }
            else{
                ListNode  *newNode = new ListNode(sum);
                if(ansHead == NULL){
                    ansHead = newNode;
                    newNode->next = NULL;
                    ansTail = newNode;
                }
                else{
                    ansTail->next = newNode;
                    newNode->next = NULL;
                    ansTail = newNode;
                }

                sum = 0;
            }
            head = head->next;
        }

        return ansHead;
    }
};