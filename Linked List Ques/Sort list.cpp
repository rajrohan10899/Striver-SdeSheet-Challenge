//https://leetcode.com/problems/sort-list/
//TIME COMPLEXITY : 0(NlogN) && SPACE COMPLEXTIY: O(n).
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
    ListNode* sortList(ListNode* head) {

        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        vector<int> data;
        ListNode* curr = head;

        //Store the value of node in vector(data).
        while(curr != NULL) {
            data.push_back(curr->val);
            curr = curr->next;
        }

        //Sort the vector(data).
        sort(data.begin(), data.end());
        
        //Update the linked list.
        curr = head;
        int i = 0;
        while(curr != NULL)
        {
            curr->val = data[i++];
            curr= curr->next;
        }
        return head;
    }
};
