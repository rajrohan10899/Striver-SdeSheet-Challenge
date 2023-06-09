// https://leetcode.com/problems/merge-k-sorted-lists

/**
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
*/

class Solution {
public:
    //Function of merge two lists:
    ListNode* mergeTwolists(ListNode* l1, ListNode* l2)
    {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        if(l1->val <= l2->val)
        {
            l1->next = mergeTwolists(l1->next, l2);
            return l1;
        }
        else{
            l2->next = mergeTwolists(l1, l2->next);
            return l2;
        }
        return NULL;
    }
    //Function for Divide And Conquer:(MergeSort)
    ListNode* divideAndconquer(int start, int end, vector<ListNode*>& lists)
    {
        if(start > end) return NULL;
        if(start == end) return lists[start];

        int mid = start + (end-start)/2;

        ListNode* L1 = divideAndconquer(start, mid, lists);
        ListNode* L2 = divideAndconquer(mid+1, end, lists);

        return mergeTwolists(L1, L2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();

        if(k == 0) return NULL;

        return divideAndconquer(0, k-1, lists);
    }
};

//Code Of Code Studio:
// https://www.codingninjas.com/codestudio/problems/merge-k-sorted-lists_992772
/************************************************************

    Following is the linked list node structure

    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/
Node<int>* mergeTwoLists(Node<int>* l1, Node<int>* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    if (l1->data <= l2->data) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

Node<int>* divideAndConquer(int start, int end, vector<Node<int>*>& listArray) {
    if (start > end) return NULL;
    if (start == end) return listArray[start];

    int mid = start + (end - start) / 2;

    Node<int>* L1 = divideAndConquer(start, mid, listArray);
    Node<int>* L2 = divideAndConquer(mid + 1, end, listArray);

    return mergeTwoLists(L1, L2);
}

Node<int>* mergeKLists(vector<Node<int>*> &listArray)
{
    // Write your code here.
    int k = listArray.size();

    if (k == 0) return NULL;

    return divideAndConquer(0, k - 1, listArray);
    
}

