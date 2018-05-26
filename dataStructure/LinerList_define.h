/**
 * name : LinerList_define.h;
 * date : 18/4/1;
 * g++ version : 7.3.1;
 * g++ options : -O2;
 * */

//You should better build it
//whith out -std=c++11;

#ifndef LINERLIST_DEFINE_H
#define LINERLIST_DEFINE_H

#include <iostream>

template<typename data_type>
LinerList<data_type>::LinerList():
	_size(0),
	_datas(NULL)
{/* Nothing to do; */}

template<typename data_type>
LinerList<data_type>::LinerList(data_type datas[],int size):
	_size(size),
	_datas(new data_type[size])
{
	try{
		copy(datas,size);
	}
	catch(char *errorMessage)
	{
		throw "ERROR : LinerList<>::LinerList(data_type[],int),LinerList<>::copy(data_type[],int);";
	}
}

template<typename data_type>
LinerList<data_type>::~LinerList()
{
	wipeAll();
}

template<typename data_type>
void LinerList<data_type>::wipeAll()
{
	if(_datas != NULL)
		delete[]_datas;
}

template<typename data_type>
void LinerList<data_type>::insert(data_type data,int posi)
{
	if(posi > _size)
		throw "ERROR : LinerList<>::insert(data_type,int);";
	++_size;
	data_type *nDatas = new data_type[_size];

	for(int i = 0;i < posi;++i)
		nDatas[i] = _datas[i];

	nDatas[posi] = data;

	for(int i = posi+1;i<_size;++i)
		nDatas[i] = _datas[i - 1];

	wipeAll();

	_datas = nDatas;
}

template<typename data_type>
void LinerList<data_type>::deleteData(int posi)
{
	int i;
	if(posi <= _size && posi >= 0)
	{
		--_size;
		for(i = posi;i < _size;++i)
		{
			_datas[i] = _datas[i+1];
		}
	}
	else
		throw "ERROR : LinerList<>::deleteData(int);";
}

template<typename data_type>
int LinerList<data_type>::search(data_type data)
{
	int result = SEARCH_FAILED;
	for(int i = 0;i < _size;++i)
		if(_datas[i] == data)
		{
			result = i;
			break;
		}
	if(result == SEARCH_FAILED)
		throw "ERROR : LinerList<>::search(data_type);";
	return result;
}

template<typename data_type>
data_type &LinerList<data_type>::
operator[](int i)
{
	if(!(i < _size))
		throw "ERROR : LinerList<>::operator[](int);";
	return _datas[i];
}

template<typename data_type>
int LinerList<data_type>::getSize()
{return _size;}

template<typename data_type>
void LinerList<data_type>::copy(data_type datas[],int size)
{
	if(size > 0)
	{
		_size = size;
		for(int i = 0;i < size;++i)
			_datas[i] = datas[i];
	}
	else
		throw "ERROR : LinerList<>::copy(data_type[],int);";
}

template<typename data_type>
void LinerList<data_type>::invert()
{
	data_type change;
	int lside = 0;
	int rside = _size -1;

	while(lside < rside)
	{
		change = _datas[lside];
		_datas[lside] = _datas[rside];
		_datas[rside] = change;

		++lside;
		--rside;
	}
}

#endif /* LINERLIST_DEFINE_H */
