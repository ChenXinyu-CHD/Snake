/**
 * name : Node_define.h;
 * date : 18/4/1;
 * g++ version : 7.3.1;
 * g++ options : -O2;
 * */

//You should better build it
//whith out -std=c++11;

#ifndef NODE_DEFINE_H
#define NODE_DEFINE_H

#include <iostream>

template<typename data_type>
Node<data_type>::Node():
	_next(NULL)
{/* Nothing to do; */}

template<typename data_type>
Node<data_type>::Node(data_type data):
	_data(data),
	_next(NULL)
{/* Nothing to do; */}

template<typename data_type>
void Node<data_type>::addNext(Node *node)
{
	if(node != NULL)
		node->_next = _next;
	_next = node;
}

template<typename data_type>
void Node<data_type>::deleteNext()
{
	Node<data_type> *node = _next;
	_next = node->_next;
	delete node;
}

template<typename data_type>
data_type &Node<data_type>::getData()
{return _data;}

template<typename data_type>
Node<data_type> *Node<data_type>::getNext()
{return _next;}

template<typename data_type>
void Node<data_type>::setNext(Node *node)
{_next = node;}

#endif /* NODE_DEFINE_H */
