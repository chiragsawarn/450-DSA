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

        void removeAllDuplicates(){
            if(!head) return;
    
            node * fast = head->next;
            node * slow = head;
            
            while(fast){
                if(slow->data == fast->data){
                    slow->next = fast->next;
                    fast->next = NULL;
                    delete fast;
                    fast = slow->next;
                    if(!fast) break;
                }
                else{
                    slow = slow->next;
                    fast = fast->next;
                }
            }
        }
};

int main(){
    LinkedList l1;

    l1.push_back(1);
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(2);
    l1.push_back(4);
    l1.push_back(5);
    l1.push_back(5);

    l1.print();
    l1.removeAllDuplicates();
    l1.print("Without Duplicates");

    return 0;
}