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
private:
    struct compare{
        bool operator() (const ListNode* a, const ListNode* b){
            return a->val > b->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode*> , compare> minHeap;

        for(ListNode* root : lists){
            if(root != nullptr){
                minHeap.push(root);
            }
        }
        
        ListNode dummy(0);
        ListNode (*tail) = &dummy;

        while(!minHeap.empty()){
            ListNode* smallest = minHeap.top();
            minHeap.pop();

            tail -> next = smallest;
            tail = tail -> next;

            if(smallest -> next != nullptr){
                minHeap.push(smallest->next);
            }
        }
        return dummy.next;
    }
};