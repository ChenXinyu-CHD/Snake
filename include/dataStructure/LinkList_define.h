/**
 * name : LinkList_define.h;
 * date : 18/4/1;
 * g++ version : 7.3.1;
 * g++ options : -O2;
 * */

//You should better build it
//whith out -std=c++11;

#ifndef LINKLIST_DEFINE_H
#define LINKLIST_DEFINE_H

template<typename data_type>
LinkList<data_type>::LinkList():
	first(new Node()),
	_size(0)
{/* Nothing to do; */}

template<typename data_type>
LinkList<data_type>::LinkList(data_type datas[],int size):
	first(new Node()),
	_size(size)
{private_copy(datas,size);}

template<typename data_type>
LinkList<data_type>::~LinkList()
{
	for(int i = 0;i < _size;++i)
		first->deleteNext();

	delete first;
}

template<typename data_type>
void LinkList<data_type>::insert(data_type data,int posi)
{
	Node *node = getNode(posi - 1);
	node->addNext(new Node(data));
	++_size;
}

template<typename data_type>
void LinkList<data_type>::deleteData(int posi)
{
	Node *node = getNode(posi - 1);
	node->deleteNext();
	--_size;
}

template<typename data_type>
int LinkList<data_type>::search(data_type data)
{
	int result = SEARCH_FAILED;
	int i = 0;
	Node *node = first->getNext();
	while(node->getNext() != NULL)
	{
		if(node->getData() == data)
		{
			result = i;
			break;
		}
		node = node->getNext();
		++i;
	}
	return result;
}

template<typename data_type>
data_type &LinkList<data_type>::
operator[](int i)
{
	Node *node = getNode(i);
	return node->getData();
}

template<typename data_type>
int LinkList<data_type>::getSize()
{return _size;}

template<typename data_type>
void LinkList<data_type>::invert()
{
	if(first == NULL)
		return;

	Node *node = first->getNext();
	Node *change = node;
	first->addNext(NULL);

	while(node != NULL)
	{
		node = node->getNext();
		first->addNext(change);
		change = node;
	}
}

template<typename data_type>
void LinkList<data_type>::deleteAfterFirst()
{
	for(int i = 0;i < _size;++i)
		first->deleteNext();
}

template<typename data_type>
void LinkList<data_type>::copy(data_type datas[],int size)
{
	deleteAfterFirst();
	private_copy(datas,size);
}

template<typename data_type>
void LinkList<data_type>::private_copy(data_type datas[],int size)
{
	Node *node = first;
	_size = size;
	for(int i = 0;i < size;++i)
	{
		node->addNext(new Node(datas[i]));
		node = node->getNext();
	}
}

template<typename data_type>
Node *LinkList<data_type>::getNode(int posi)
{
	Node *result = first;
	for(int i = -1;i < posi;++i)
		result = result->getNext();
	return result;
}

#endif /* LINKLIST_DEFINE_H */
