// Reverse a singly Linked List
// Iteratively as well as recursively
#include <bits/stdc++.h>
using namespace std;

class LinkedList{
    private:
        struct node{
            int data;
            node * next;
            node(){

            }
            node(int data){
                this->data = data;
                this->next = NULL;
            }
        };
        node * head, *tail;

        void recursiveReverse_util(node * &head, node * &new_head){
            if(head == NULL) return;
            node * temp = head;
            head = head->next;
            temp->next = new_head;
            new_head = temp;
            recursiveReverse_util(head,new_head);
        }

    public:
        LinkedList(){
            head = NULL;
            tail = NULL;
        }

        void push_back(int data){
            node * temp = new node(data);
            if(empty()){
                head = temp;
                tail = temp;
            }else{
                tail->next = temp;
                tail = temp;
            }
        }

        void pop_back(){
            // LL is empty
            if(empty()){
                return;
            }
            // LL has only 1 node
            if(head->next == NULL){
                tail = NULL;
                delete head;
                head = NULL;
            }
            // LL has > 1 nodes
            else{
                node * t = head;
                while(t->next != tail){
                    t = t->next;
                }
                t->next = NULL;
                delete tail;
                tail = t;
            }
        }

        void push_front(int data){
            node * temp = new node(data);
            if(empty()){
                head = temp;
                tail = temp;
            }
            else{
                temp->next = head;
                head = temp;
            }
        }

        void pop_front(){
            if(empty()){
                return ;
            }
            if(head->next == NULL){
                tail = NULL;
                delete head;
                head = NULL;
            }
            else{
                node * new_head = head->next;
                head->next = NULL;
                delete head;
                head = new_head;
            }
        }

        bool empty(){
            return head == NULL;
        }

        void print(string desc="Linked List"){
            cout<<desc<<" : ";
            node * t = head;
            while(t != NULL){
                cout<<t->data<<" ";
                t = t->next;
            }
            cout<<endl;
        }

        void iterativeReverse(){
            node * new_head = NULL;
            node * temp;
            tail = head;
            while(head){
                temp = head;
                head = head->next;
                temp->next = new_head;
                new_head = temp;
            }
            head = new_head;
        }

        void recursiveReverse(){
            node * new_head = NULL;
            tail = head;
            recursiveReverse_util(head, new_head);
            head = new_head;
        }
};

int main(){
    LinkedList l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);

    l1.print();
    l1.iterativeReverse();
    l1.print("Reversed");

    l1.recursiveReverse();
    l1.print("Reversed Again");

    return 0;
}