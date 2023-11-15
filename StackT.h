#ifndef STACKT_H_INCLUDED
#define STACKT_H_INCLUDED

template <typename T>
class Stack {
	T *buf;
	int top;
	int size;
public:
	Stack(int s);
	virtual ~Stack();
	bool full() const;
	bool empty() const;
	void push(const T& a);
	void push(T&& a);
	T&& pop();
};
#endif
