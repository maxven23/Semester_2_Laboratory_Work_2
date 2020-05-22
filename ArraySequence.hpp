#pragma once
#include "Sequence.h"
#include "DynamicArray.h"

template <class T>

class ArraySequence : public Sequence<T> {
private:
	DynamicArray<T>* items;
	int size;
public:
	ArraySequence(int size) {
		int current_size;
		if (size < 0) {
			std::cout << "WARNING!!! INPUTED SIZE < 0. IT WAS SETTED AS 1" << std::endl;
			current_size = 1;
		}
		else 
			current_size = size;
		this->items = new DynamicArray<T>(current_size);
		this->size = size;
		for (int i = 0; i < current_size; i++) {
			this->items->Set(i, { 0 });
		}
	};

	ArraySequence(int size, DynamicArray<T>* items) {
		this->size = size;
		this->items = new DynamicArray<T>(size);
		for (int i = 0; i < size; i++) {
			this->items->Set(i, items->Get(i));
		}
	};

	ArraySequence(const ArraySequence<T>& tocopy) {
		this->size = tocopy->size;
		this->items = new DynamicArray(tocopy->items);
	};

	virtual int GetSize() const override {
		return this->items->GetSize;
	};

	virtual T Get(const int index) const override {
		return this->items->Get(index);
	};

	virtual T GetLast() const override {
		return this->items->GetLast();
	};

	virtual T GetFirst() const override {
		return this->items->GetFirst();
	};

	virtual void Set(int index, T item) override {
		this->items->Set(index, item);
	};

	virtual void Resize(int newsize) override {


	};


};

