#pragma once

template <class T>

class DynamicArray
{
private:
	T* items;
	int size;

public:
	// Конструкторы
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

	// Получение размера массива
	int GetSize() {
		return this->size;
	}

	// Получение элемента массива по индексу
	T Get(int index) {
		if (index < 0 || index >= this->size)
			throw std::exception("INDEX ERROR: Index out of range");
		return this->items[index];
	}

	// Получение первого и последнего элемента массива (лишнее)
	T GetFirst() {
		return Get(0);
	}

	T GetLast() {
		return this->Get(this->GetSize() - 1);
	}

	// Изменение / задание новых элементов массива по индексу
	void Set(int index, const T value) {
		if (index < 0 || index >= this->size)
			throw std::exception("IDNEX ERROR: Index out of range");
		this->items[index] = value;
	}

	// Изменение размера массива
	void Resize(int newsize) {
		if (newsize < 0)
			throw std::exception("INVALID INPUT: New size < 0");

		else if (newsize > this->size) {
			T* newItems = new T[size];
			for (int i = 0; i < this->size; i++) {
				newItems[i] = this->items[i];
			}
			for (int i = this->size; i < newsize; i++) {
				newItems[i] = { 0 };
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
	};
	
	// Деструктор
	~DynamicArray() {
		delete[] items;
	};
};