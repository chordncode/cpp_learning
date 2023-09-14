#ifndef CHARSTACK_H_INCLUDED
#define CHARSTACK_H_INCLUDED
class CharStack {
    enum {SIZE = 20};
    int top; 
    char buf[SIZE];
public:
    CharStack() : top(SIZE) {}
    bool isEmpty() const {
        return top == SIZE;
    }
    bool isFull() const {
        return !top;
    }
    bool push(char ch) {
        if(isFull()) {
            return false;
        }
        buf[--top] = ch;
        return true;
    }
    char pop() {
        if(isEmpty()) {
            return 0;
        }
        return buf[top++];
    }
};
#endif