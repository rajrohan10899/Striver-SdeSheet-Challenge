// https://www.codingninjas.com/codestudio/problems/920454?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */
 int size(Node* head) {
      int n = 0;
      while(head!=NULL) {
        n++;
        head = head->next;
      }
      return n;
    }

Node *rotate(Node *head, int k) {
     // Write your code here.
      if(head == NULL) return head;

        int n = size(head);
        int loop = k % n;
        loop = n-loop;

        if( n == 1 || loop == n) return head;

        int j = 0;
        Node* temp = head;
        Node* firstAddress = head;

         while(temp != NULL) {
          j++;
          if(j == loop) {
              firstAddress = temp->next;
              temp->next = NULL;
              break;
          }
          temp = temp->next;
        }
        temp = firstAddress;
        while (temp->next != NULL) {
          temp = temp->next;
        }
        temp->next = head;
        return firstAddress;
     
}
