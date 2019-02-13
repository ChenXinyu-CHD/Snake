/**
 * name : Queue_define.h;
 * date : 18/4/16;
 * g++ version : 7.3.1;
 * g++ options : -O2;
 * */

//You should better build it
//whith out -std=c++11;

#ifndef QUEUE_DEFINE_H
#define QUEUE_DEFINE_H

#include <iostream>

template<typename data_type>
Queue<data_type>::Queue():
	top(NULL),
	bottom(NULL)
{/* Nothing to do; */}

template<typename data_type>
Queue<data_type>::~Queue()
{
	while(!isEmpty())
		pop();
}

template<typename data_type>
void Queue<data_type>::push(data_type data)
{
	QueueNode *newBottom = new QueueNode(data);

	if(isEmpty())
	{
		bottom = newBottom;
		top = bottom;
	}
	else
	{
		bottom->setNext(newBottom);
		bottom = newBottom;
	}
}

template<typename data_type>
data_type Queue<data_type>::pop()
{
	data_type result = getTop();
	QueueNode *oldTop = top;

	top = oldTop->getNext();
	delete oldTop;

	return result;
}
	
template<typename data_type>
data_type Queue<data_type>::getTop()
{return top->getData();}

template<typename data_type>
data_type Queue<data_type>::getBottom()
{return bottom->getData();}

template<typename data_type>
bool Queue<data_type>::isEmpty()
{return top == NULL;}

#endif /* QUEUE_DEFINE_H */
