#pragma once
#include "Sequence.hpp"
#include "DynamicArray.hpp"

template <class T>

class ArraySequence : public Sequence<T> {
private:
	DynamicArray<T>* items;
	int size;
public:
	ArraySequence(int size) {
		int current_size;
		if (size < 0) {
			std::cout << "WARNING!!! INPUTED SIZE < 0. IT WAS SETTED TO 1" << std::endl;
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
		return this->items->GetSize();
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

	virtual void Append(T item) override {
		this->items->Resize(GetSize() + 1);
		++this->size;
		for (int i = 1; i < this->size; i++) {
			this->items->Set(i, this->items->Get(i - 1));
		}
		this->items->Set(0, item);
	};

	virtual void Prepend(T item) override {
		this->items->Resize(GetSize() + 1);
		++this->size;
		this->items->Set(this->size - 1, item);
	};

	virtual void Insert(int index, T item) override {
		this->items->Resize(GetSize() + 1);
		++this->size;
		for (int i = index; i < this->size; i++) {
			this->items->Set(i, this->items->Get(i - 1));
		}
		this->items->Set(index, item);
	};

	virtual void RemoveAt(int index) override {
		if (index < 0 || index >= this->size)
			throw std::exception("INDEX ERROR: Index out of range");
		DynamicArray<T>* temp;
		temp = new DynamicArray<T>(this->size - 1);
		for (int i = 0; i < index; i++) {
			temp->Set(i, this->items->Get(i));
		}
		for (int i = index; i < this->size; i++) {
			temp->Set(i, this->items->Get(i));
		}
		delete items;
		--this->size;
		this->items = temp;
	};

	virtual void Remove(T item) override {
		for (int i = 0; i < this->size; i++) {
			if (this->items->Get(i) == item) {
				RemoveAt(i);
				break;
			}
		}
	};

	virtual void RemoveAll(T item) override {
		for (int i = 0; i < this->size; i++) {
			if (this->items->Get(i) == item) {
				RemoveAt(i);
				i--;
			}
		}
	};

	virtual Sequence<T>* Copy() override {
		ArraySequence<T>* copy;
		copy = new ArraySequence<T>(this->items->GetSize(), this->items);
		return copy;
	};

	virtual Sequence<T>* GetSubSequence(int start, int end) override {
		if (start < 0 || start >= this->size || end < 0 || end >= this->size)
			throw std::exception("INDEX ERROR: Index out of range");
		ArraySequence<T>* subseq;
		subseq = new ArraySequence(end - start + 1);
		int previndex = 0;
		for (int i = start; i < end; i++) {
			subseq->items->Set(previndex, this->items->Get(i));
			++previndex;
		}
		return subseq;
	};

	virtual Sequence<T>* Concat(Sequence<T>* toConcat) override {
		ArraySequence<T>* conc;
		conc = new ArraySequence<T>(this->size + toConcat->GetSize());
		for (int i = 0; i < this->size; i++) {
			conc->items->Set(i, this->items->Get(i));
		}
		for (int i = 0; i < toConcat->GetSize(); i++) {
			conc->items->Set(this->size + i, toConcat->Get(i));
		}
		return conc;
	};

};