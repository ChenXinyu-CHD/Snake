/**
 * name : Queue_declear.h;
 * date : 18/4/16;
 * g++ version : 7.3.1;
 * g++ options : -O2;
 * */

//You should better build it
//whith out -std=c++11;

#ifndef QUEUE_DECLEAR_H
#define QUEUE_DECLEAR_H

template<typename data_type>
class Queue
{
public:
	typedef Node<data_type> QueueNode;
private:
	QueueNode *top;
	QueueNode *bottom;
public:
	Queue();

	~Queue();

	void push(data_type data);
	data_type pop();
	data_type getTop();
	data_type getBottom();

	bool isEmpty();
};

#endif /* QUEUE_DECLEAR_H */
