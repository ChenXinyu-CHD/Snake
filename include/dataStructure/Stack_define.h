/**
 * name : Stack_define.h;
 * date : 18/4/4;
 * g++ version : 7.3.1;
 * g++ options : -O2;
 * */

//You should better build it
//whith out -std=c++11;

#ifndef STACK_DEFINE_H
#define STACK_DEFINE_H

template<typename data_type>
Stack<data_type>::Stack():
	top(new StackNode()),
	bottom(top)
{/* Nothing to do; */}

template<typename data_type>
Stack<data_type>::~Stack()
{
	while(!isEmpty())
		pop();
	delete bottom;
}

template<typename data_type>
void Stack<data_type>::push(data_type data)
{
	StackNode *newTop = new StackNode(data);
	newTop->setNext(top);
	top = newTop;
}

template<typename data_type>
data_type Stack<data_type>::pop()
{
	data_type result = getTop();
	StackNode *oldTop = top;

	top = oldTop->getNext();
	delete oldTop;
	
	return result;
}

template<typename data_type>
data_type Stack<data_type>::getTop()
{return top->getData();}

template<typename data_type>
bool Stack<data_type>::isEmpty()
{return top == bottom;}

#endif /* STACK_DEFINE_H */
