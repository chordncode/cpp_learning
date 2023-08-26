#include <iostream>

using namespace std;

class Node{

    public:
        Node(Node* parentNode, int val): parent(parentNode), value(val){};

        Node* getLeft(){
            return left;
        }
        void setLeft(Node* newNode){
            left = newNode;
        }

        int getValue(){
            return value;
        }

        Node* getRight(){
            return right;
        }
        void setRight(Node* newNode){
            right = newNode;
        }

    private:
        Node* parent;
        Node* left;
        int value;
        Node* right;

};

class Tree{

    public:
        Tree(): root(nullptr){};

        void add(int val){
            if(!root){
                root = new Node(nullptr, val);
            } else {
                addRecursive(root, val);
            }
        }

        void addRecursive(Node* current, int val){
            if(val < current->getValue()){
                if(current -> getLeft()){
                    addRecursive(current -> getLeft(), val);
                } else {
                    current -> setLeft(new Node(current, val));
                }
            } else if (val > current->getValue()){
                if(current -> getRight()){
                    addRecursive(current -> getRight(), val);
                } else {
                    current -> setRight(new Node(current, val));
                }
            }
        };

        int getValue(Node* current){
            return current->getValue();
        }

    private:
        Node* root;


};

int main (){

    Tree tree;
    tree.add(10);
    tree.add(20);

    return 0;
}