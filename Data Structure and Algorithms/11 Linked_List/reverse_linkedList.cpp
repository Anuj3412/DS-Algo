// Time Complexity = O(n)
// Space Complexity = O(1)


#include<bits/stdc++.h>
using namespace std;

class node{

    public:
    int data ;
    node* next = NULL;

    node(int data ){
        this-> data = data ;
        this->next = NULL;
    }
};

void print (node* &head){

    node* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp-> next;
    }
    cout<<endl;
}

void insert( int data , node* &tail){

    node* temp = new node(data);
    tail->next = temp;
    tail = temp;
}

// Iterative approach 
void reverse(node* &head){
    node* prev = NULL;
    node* curr = NULL;
    curr = head;
    while(curr){
        node* nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
    }
    head = prev;

}

// recursive approach ---> head recursion
void reverse(node* &head , node* curr , node* prev){

    //base condition
    if(curr==NULL or curr->next == NULL){
        head = curr;
        curr->next = prev;
        return;
    }

    /* yaha first pair ki linking change ki or fir baaki k liye recursion call kar diya */
    node* nex = curr->next;
    curr->next = prev;
    prev = curr;
    reverse(head , nex , prev);

}

// approach - 3   ---> tail recursion
/*
we pass the head and then keep on changing the head pointer before passing it for next recursion 
*/


int main(){

    node* head = new node(10);
    node* tail = head;
    insert(20 , tail);
    insert(30 , tail);
    insert(40 , tail);
    insert(50 , tail);
    insert(60 , tail);
    insert(70 , tail);
    print(head);
    cout << "after reversing" << endl;
    reverse(head , head , NULL);
    print(head);



    return 0;
}