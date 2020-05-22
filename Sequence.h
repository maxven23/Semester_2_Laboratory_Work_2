#pragma once

template <class T> 

class Sequence 
{
public:
	virtual Sequence<T>* GetSubSequence(const int start, const int end) = 0;
	virtual Sequence<T>* Copy() = 0;
	virtual Sequence<T>* CopyTo(Sequence<T>* toWhere, int start) = 0;

	virtual int GetSize() = 0;
	virtual T Get(const int index) = 0;
	virtual T GetLast() = 0;
	virtual T GetFirst() = 0;

	virtual void Set(const int index, T item) = 0;
	virtual void Resize(const int newsize) = 0;
	virtual void Append(T item) = 0;
	virtual void Prepend(T item) = 0;
	virtual void Insert(int index,  T item) = 0;
	virtual void Remove(T item) = 0;
	virtual void RemoveAt(const int index) = 0;

};