#include <iostream>
#include "StackT.h"
using namespace std;

template <typename T> Stack<T>::Stack(int s) : size(s), top(s) {
	buf = new T[s];
}
template <typename T> Stack<T>::~Stack() {
	delete[] buf;
}
template <typename T> bool Stack<T>::full() const {
	return !top;
}
template <typename T> bool Stack<T>::empty() const {
	return top == size;
}
template <typename T> void Stack<T>::push(const T& a) {
	buf[--top] = a;
}
template <typename T> void Stack<T>::push(T&& a) {
	buf[--top] = move(a);
}
template <typename T> T&& Stack<T>::pop() {
	return move(buf[top++]);
}
