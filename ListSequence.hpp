#pragma once
#include "Sequence.hpp"
#include "LinkedList.hpp"

template <class T>

class ListSequence : public Sequence<T> {
private:
	LinkedList<T>* items;
	int size;
public:
	ListSequence() {
		this->items = new LinkedList<T>();
		this->size = 0;
	};

	ListSequence(LinkedList<T>* items, int size) {
		this->size = size;
		this->items = new LinkedList<T>();
		for (int i = 0; i < size; i++) {
			this->Prepend(items->Get(i));
		}
	};

	ListSequence(const ListSequence<T>& list) {
		this->size = list->size;
		this->items = new LinkedList<T>(list->GetSize());
		for (int i = 0; i < list->GetSize(); i++) {
			this->Prepend(list->Get(i));
		}
	};

	virtual int GetSize() const override {
		return this->items->GetSize();
	};

	virtual T Get(const int index) const override {
		if (index < 0 || index > this->size)
			throw std::exception("INDEX ERROR: Index out of range");
		return this->items->Get(index);
	};

	virtual T GetLast() const override {
		return this->items->GetLast();
	};

	virtual T GetFirst() const override {
		return this->items->GetFirst();
	};

	virtual void Append(T item) override {
		this->items->Append(item);
		++this->size;
	};

	virtual void Prepend(T item) override {
		this->items->Prepend(item);
		++this->size;
	};

	virtual void InsertAt(T item, int index) override {
		this->items->InsertAt(item, index);
		++this->size;
	};

	virtual void Remove(T item) override {
		for (int i = 0; i < this->size; i++) {
			if (this->items->Get(i) == item) {
				this->items->RemoveAt(i);
				break;
			}
		}
		++this->size;
	};

	virtual void RemoveAt(int index) override {
		if (index < 0 || index >= this->size)
			throw std::exception("INDEX ERROR: Index out of range");
		this->items->RemoveAt(index);
	};

	virtual void RemoveAll(T item) override {
		for (int i = 0; i < this->size; i++) {
			if (this->items->Get(i) == item) {
				RemoveAt(i);
				i--;
			}
		}
	};

	virtual Sequence<T>* Concat(Sequence<T>* toConcat) override {
		ListSequence<T>* tempList;
		tempList = new ListSequence<T>();
		T* temp;
		temp = new T[this->GetSize() + toConcat->GetSize()];
		for (int i = 0; i < this->GetSize(); i++) {
			temp[i] = this->Get(i);
		}
		for (int i = 0; i < toConcat->Get(i); i++) {
			temp[i + this->GetSize()] = toConcat->Get(i);
		}
		for (int i = 0; i < this->GetSize() + toConcat->GetSize(); i++) {
			tempList->Prepend(temp[i]);
		}
	};

	virtual Sequence<T>* GetSubSequence(int start, int end) override {
		if (start < 0 || start >= this->size || end < 0 || end >= this->size || end < start)
			throw std::exception("INDEX ERROR: Index out of range");
		ListSequence<T>* newList;
		newList = new ListSequence();
		newList->items = this->items->GetSubList(start, end);
		newList->size = newList->GetSize();
		return newList;
	};

	virtual Sequence<T>* Copy() override {
		ListSequence<T>* copy;
		copy = new ListSequence();
		for (int i = 0; i < this->size; i++) {
			copy->items->Prepend(this->Get(i));
		}
	};

	~ListSequence() {
		while (this->size != 0)
			this->items->fPop();
	};
};