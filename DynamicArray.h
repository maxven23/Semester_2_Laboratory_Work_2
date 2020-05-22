#pragma once

template <class T>

class DynamicArray
{
private:
	T* items;
	int size;

public:
	DynamicArray(T* items, const int size) {
		if (size < 0)
			throw std::exception("INVALID INPUT: size < 0");
		this->size = size;
		this->items = new T[size];
		for (int i = 0; i < size; i++) {
			this->items[i] = *(items + i);
		}
	}

	DynamicArray(const DynamicArray<T> &array) {
		this->size = array->GetSize();
		this->items = new T[this->size];
		for (int i = 0; i < this->size; i++) {
			this->Set(i, array->Get(i));
		}

	}

	DynamicArray(const int size) {
		if (size < 0)
			throw std::exception("INVALID INPUT: size < 0");
		this->items = new T[size];
		this->size = size;
	}

	int GetSize() {
		return this->size;
	}

	T Get(const int index) {
		if (index < 0 || index >= this->size)
			throw std::exception("INDEX ERROR: Index out of range or this element isn't set");
		return this->items[index];
	}

	T GetFirst() {
		return Get(0);
	}

	T GetLast() {
		return this->Get(this->GetSize() - 1);
	}

	void Set(const int index, const T value) {
		if (index < 0 || index >= this->size)
			throw std::exception("IDNEX ERROR: Index out of range");
		this->items[index] = value;
	}

	void Resize(const int newsize) {
		if (newsize < 0)
			throw std::exception("INVALID INPUT: New size < 0");

		else if (newsize > this->size) {
			T* newItems = new T[size];
			for (int i = 0; i < this->size; i++) {
				newItems[i] = this->items[i];
			}
			this->size = newsize;
			delete[] this->items;
			this->items = newItems;
		}

		else if (newsize < this->size) {
			T* newItems = new T[newsize];
			for (int i = 0; i < newsize; i++) {
				newItems[i] = this->items[i];
			}
			this->size = newsize;
			delete[] this->items;
			this->items = newItems;
		}

		else
			std::cout << "New size is equal to previous size" << std::endl;
	}
	~DynamicArray() {
		delete[] items;
	};
};