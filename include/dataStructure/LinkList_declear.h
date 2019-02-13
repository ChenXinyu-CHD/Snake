/**
 * name : LinkList_declear.h;
 * date : 18/4/1;
 * g++ version : 7.3.1;
 * g++ options : -O2;
 * */

//You should better build it
//whith out -std=c++11;

#ifndef LINKLIST_DECLEAR_H
#define LINKLIST_DECLEAR_H

#define Node Node<data_type>

template<typename data_type>
class LinkList
{
public:
	static const int SEARCH_FAILED = -1;
private:
	Node *first;
	int _size;
public:
	LinkList();
	LinkList(data_type datas[],int size);

	~LinkList();

	void insert(data_type data,int posi);
	void deleteData(int posi);

	int search(data_type data);

	data_type &operator[](int i);

	int getSize();
	void copy(data_type datas[],int size);

	void invert();
private:
	LinkList(const LinkList &);	//LinkList(const LinkList &)=delete;
	void deleteAfterFirst();
	void private_copy(data_type datas[],int size);

	Node* getNode(int posi);
};

#endif /* LINKLIST_DECLEAR_H */
