#include <iostream>

using namespace std;

// Node for Doubly Linked List
class Node{

    public:
        // Constructor
        Node(Node* prev, int val) : value(val), prevNode(prev), nextNode(nullptr) {};

        // get previous node
        Node* getPrevNode(){
            return prevNode;
        }

        // connect previous node with the current node
        void setPrevNode(Node* prev){
            prevNode = prev;
        }

        // get next node
        Node* getNextNode(){
            return nextNode;
        }

        // connect next node with the current node
        void setNextNode(Node* next){
            nextNode = next;
        }

        // get value the node have
        int getValue(){
            return value;
        }
        
    private:
        Node* prevNode;
        int value;
        Node* nextNode;
        
};

// Doubly Linked List
class LinkedList{

    public:
        // Constructor
        LinkedList() : head(nullptr), listSize(0){};

        // the count of how many nodes the list has
        int size(){
            return listSize;
        }

        // add new node with the value
        void add(int num){
            if(!head){
                head = new Node(nullptr, num);
            } else {
                Node* current = head;

                // search for the end of the list
                while(current -> getNextNode()){
                    current = current -> getNextNode();
                }

                // create and connect the new node at the end of the list
                Node* newNode = new Node(current, num);
                current->setNextNode(newNode);
            }

            listSize += 1;
        }

        // remove node from list with the index
        void remove(int index){
            if(index == 0){
                Node* newHead = head -> getNextNode();

                delete head;
                head = newHead;
            } else {
                Node* current = head;

                // search for the node at the index position
                for(int i = 0;  i < index; i++){
                    current = current -> getNextNode();
                }

                // get the previous and the next node from the node that would be deleted
                Node* prev = current->getPrevNode();
                Node* next = current->getNextNode();

                // if the previous node and the next node exists, connect both
                if(prev && next){
                    prev->setNextNode(next);
                    next->setPrevNode(prev);
                }

                delete current;
                current = nullptr;
            }

            listSize -= 1;
        }

        // return the value from the node with the index
        int get(int index){
            Node* target = head;
            for(int i = 0; i < index; i++){
                target = target->getNextNode();
            }
            return target->getValue();
        }

    private:
        Node* head;
        int listSize;

};

void printList(LinkedList list){
    for(int i = 0; i < list.size(); i++){
        cout << list.get(i) << endl;
    }
}

int main(){

    LinkedList list;
    list.add(10);
    list.add(20);
    list.add(30);
    cout << "Print List 1 : " << endl;
    printList(list);

    list.remove(0);
    cout << "Print List 2 : " << endl;
    printList(list);
    
    list.remove(1);
    cout << "Print List 3 : " << endl;
    printList(list);

    return 0;
}