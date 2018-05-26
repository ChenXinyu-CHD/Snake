/**
 * name : LinerList_declear.h;
 * date : 18/4/1;
 * g++ version : 7.3.1;
 * g++ options : -O2;
 * */

//You should better build it
//whith out -std=c++11;

#ifndef LINERLIST_DECLEAR_H
#define LINERLIST_DECLEAR_H

template<typename data_type>
class LinerList
{
public:
	static const int SEARCH_FAILED = -1;
private:
	data_type *_datas;
	int _size;
public:
	LinerList();
	LinerList(data_type datas[],int size);

	~LinerList();

	void insert(data_type data,int posi);
	void deleteData(int posi);

	int search(data_type data);

	data_type &operator[](int i);

	int getSize();
	void copy(data_type datas[],int size);

	void invert();
private:
	void wipeAll();
};

#endif /* LINERLIST_DECLEAR_H */
