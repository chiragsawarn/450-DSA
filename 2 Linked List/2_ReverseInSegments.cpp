// Reversed all segments of k
// If the no of elements in the LL is not divisibe by k...
// ...Then, treat the remaining elements of the list as one group and reverse it
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

        pair<node *, node *> reverseOneSegment(node * &head, int k){
            node * new_head = NULL;
            node * temp;
            node * tail = head;
            for(int i=0; i<k; ++i){
                if(head == NULL) return {new_head,tail};
                node * temp = head;
                head = head->next;
                temp->next = new_head;
                new_head = temp;    
            }
            return {new_head,tail};
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

        void reverseAllSegments(int k){
            pair<node *,node *> p, temp;
            p = reverseOneSegment(head,k);
            while(head != NULL){
                temp = reverseOneSegment(head,k);
                p.second->next = temp.first;
                p.second = temp.second;
            }
            head = p.first;
        }
};

int main(){
    // Input:
    // LinkedList: 1->2->3->4->5
    // K = 3
    // Output: 3 2 1 5 4 
    LinkedList l1;

    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    l1.push_back(5);

    int k = 3;

    l1.print();
    l1.reverseAllSegments(k);
    l1.print("Reversed all segments of k");

    return 0;
}