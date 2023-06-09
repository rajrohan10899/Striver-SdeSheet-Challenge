// https://www.codingninjas.com/codestudio/problems/1112628?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/

Node *firstNode(Node *head)
{
    //    Write your code here.
    if(head == NULL || head->next == NULL)
    {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;
    Node* meet = head;

    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            while(meet != slow)
            {
                slow = slow->next;
                meet = meet->next;
            }
            return slow;  
        } 
    }
    return NULL;
}
