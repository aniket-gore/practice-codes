#include<iostream>
#include<stack>

using namespace std;

typedef struct linkedList{
    int data;
    struct linkedList *next;
}LinkedListNode;

LinkedListNode *getNode(int data){
    LinkedListNode *temp = new LinkedListNode();
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void printList(LinkedListNode *head){
    cout<<endl;
    while(head){
       cout<<head->data<<"\t";
       head = head->next;
    } 
}

bool checkPalindrome(LinkedListNode *head){
    if(!head){
        return true;  
    }
    stack<LinkedListNode *> stk;
    LinkedListNode *slow = head, *fast = head;

    while(fast && fast->next){
        stk.push(slow);
        slow = slow->next;
        fast = fast->next->next;
    }

    if(fast && !fast->next){
        slow = slow->next; 
    }

    while(slow){
        if(slow->data != stk.top()->data){
            return false; 
        } 
        stk.pop();
        slow = slow->next;
    }
    
    return true;
}
/*
int main(){
    LinkedListNode *head = getNode(1);
    head->next = getNode(2);
    head->next->next = getNode(3);
    head->next->next->next = getNode(2);
    head->next->next->next->next = getNode(1);
    printList(head);
    cout<<"Output: "<<checkPalindrome(head)<<endl;
    printList(head);
    return 1;
}
*/
