/**
 * name : Stack_declear.h;
 * date : 18/4/4;
 * g++ version : 7.3.1;
 * g++ options : -O2;
 * */

//You should better build it
//whith out -std=c++11;

#ifndef STACK_DECLEAR_H
#define STACK_DECLEAR_H

template<typename data_type>
class Stack
{
public:
	typedef Node<data_type> StackNode;
private:
	StackNode *top;
	StackNode *bottom;
public:
	Stack();

	~Stack();

	void push(data_type data);
	data_type pop();
	data_type getTop();

	bool isEmpty();
};

#endif /* STACK_DECLEAR_H */
