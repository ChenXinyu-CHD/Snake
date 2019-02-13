/**
 * name : Node.h;
 * date : 18/4/1;
 * g++ version : 7.3.1;
 * g++ options : -O2;
 * */

//You should better build it
//whith out -std=c++11;

#ifndef NODE_DECLEAR_H
#define NODE_DECLEAR_H

template<typename data_type>
class Node
{
private:
	data_type _data;
	Node *_next;
public:
	Node();
	Node(data_type data);

	void addNext(Node *node);
	void setNext(Node *node);

	void deleteNext();

	data_type &getData();
	Node *getNext();
};

#endif /* NODE_DECLEAR_H */
