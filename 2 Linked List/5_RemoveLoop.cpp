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

        node * search(int x){
            if(head == NULL) return NULL;

            node * t = head;

            while(t){
                if(t->data == x) return t;
                t = t->next;
            }

            return NULL;
        }

        node * isThereAloop(){
            node * fast = head;
            node * slow = head;
            
            while(fast && fast->next){
                fast = fast->next->next;
                slow = slow->next;
                if(fast == slow) return slow;
            }
            
            return NULL;
        }

        void createLoop(int x){
            if(head == NULL || head->next == NULL) return;
            node * t = search(x);
            if(t){
                tail->next = t;
                cout<<"Loop has been created !"<<endl;
            }else{
                cout<<"Couldn't find "<<x<<" in the Linked List!"<<endl;
                cout<<"Hence, couldn't create a loop!"<<endl;
            }
        }

        void removeLoop(){
            node * meetingPointer = isThereAloop();
            if(!meetingPointer) return;

            // SPECIAL CASE : Start
            // Loop starts at head
            // We have to go to tail to unhinge it.
            if(meetingPointer == head){
                while(meetingPointer->next != head)
                    meetingPointer = meetingPointer->next;
                meetingPointer->next = NULL;
                return;
            }
            // SPECIAL CASE : End

            node * fast = head;

            while(fast->next != meetingPointer->next){
                fast = fast->next;
                meetingPointer = meetingPointer->next;
            }
            meetingPointer->next = NULL;
        }
};

int main(){
    LinkedList l1;

    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    l1.push_back(5);

    // attaches 5 back to 3
    l1.createLoop(3);
    cout<<"Remove loop has been called!"<<endl;
    l1.removeLoop();
    
    (l1.isThereAloop()) ? cout<<"Loop still exists" : cout<<"No loop exists";
    
    return 0;
}