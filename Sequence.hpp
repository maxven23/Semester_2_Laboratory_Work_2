#pragma once

template <class T> 

class Sequence 
{
public:
	virtual Sequence<T>* GetSubSequence(int start, int end) = 0;
	virtual Sequence<T>* Copy() = 0;
	virtual Sequence<T>* Concat(Sequence<T>* toConcat) = 0;

	virtual int GetSize() = 0;
	virtual T Get(int index) = 0;
	virtual T GetLast() = 0;
	virtual T GetFirst() = 0;

	virtual void Set(int index, T item) = 0;
	virtual void Append(T item) = 0;
	virtual void Prepend(T item) = 0;
	virtual void Insert(int index,  T item) = 0;
	virtual void Remove(T item) = 0;
	virtual void RemoveAll(T item) = 0;
	virtual void RemoveAt(int index) = 0;

};