#include<bits/stdc++.h>
using namespace std;

// Node kaisa hoga uska class bana diya 

class Node{

    public:
    int data;
    Node *next;

    // ye Node ka parameterisd constructor h 

    Node(int data){
        this->data = data;
        this->next = NULL; // ye next jo h --> vo address h 

    }

    // print function details dekhne k liye
    void print(){

        cout<<"Data is: "<<this->data<<endl<<"Address is: "<<this->next<<endl;
    }


};



int main(){


    //ye node ke liye object ko create krna h parametersied constructor se
    Node N1(10);      // (Static memory allocation)

    // --> kyoki humne ek pointer banaya h --> to usko address dena hoga heap memory me
    Node *N2 = new Node(20);   // (Dynamic memory allocation)

    N1.print();
    (*N2).print();



    return 0;
}