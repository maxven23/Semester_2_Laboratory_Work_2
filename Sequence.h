#pragma once

class Exception {};

template <class T> 

class Sequence 
{
private:
	T* items;
	bool itemsCheck;
	int size;

public:
	virtual int GetSize() = 0;

	virtual T Get(const int index) = 0;
	
	virtual Sequence<T>* GetSubSequence(int startIndex, int endIndex) = 0;
	
	virtual T GetLast() = 0;

	virtual T GetFirst() = 0;

	virtual void Set(int index, T item) = 0;

	virtual void Resize(int newsize) = 0;

	virtual void Append(T item) = 0;

	virtual void Prepend(T item) = 0;

	virtual void Insert(T item, int indrx) = 0;

	virtual ~Sequence() = 0;
};


template <class T>

class DynamicArray : public Sequence<T> {
private:
	T* items;
	bool itemsCheck;
	int size;

public:
	DynamicArray(T* items) {};

	DynamicArray(const DynamicArray<T> &array) {};

	DynamicArray(const int size) {
		if (size < 0)
			throw new Exception();
		this->items = new T[size];
		this->itemsCheck = new bool[size];
		for (int i = 0; i < size; i++)
			this->itemsCheck[i] = false;
		this->size = size;
	}

	int GetSize() override {
		return this->size;
	}

	T Get(const int index) override {
		if (index < 0 || index >= this->size || !this->itemsCheck[index])
			throw new Exception();
		return this->items[index];
	}

	T GetFirst() override {
		return Get(0);
	}

	T GetLast() override {
		return this.Get(GetSize);
	}

	void Set(const int index, const T value) override {
		if (index < 0 || index >= this->size)
			throw new Exception();
		this->items[index] = value;
		this->itemsCheck[index] = true;
	}

	void Resize(const int newsize) override {
		if (newsize < 0)
			throw new Exception();

		else if (newsize > this->size) {
			T* newItems = new T[newsize];
			bool newItemsCheck = new bool[newsize];
			for (int i = 0; i < this->size; i++) {
				newItems[i] = this->items[i];
				newItemsCheck[i] = true;
			}
			for (int i = this->size + 1; i < newsize; i++) {
				newItemsCheck[i] = false;
			}
			this->size = newsize;
			for (int i = 0; i < this->size; i++) {
				this->items[i] = newItems[i];
				this->itemsCheck[i] = newItemsCheck[i];
			}
		}

		else if (newsize < this->size) {
			T* newItems = new T[newsize];
			bool newItemsCheck = new bool[newsize];
			for (int i = 0; i < newsize; i++) {
				newItems[i] = this->items[i];
				newItemsCheck[i] = true;
			}
			this->size = newsize;
			for (int i = 0; i < this->size; i++) {
				this->items[i] = newItems[i];
				this->itemsCheck[i] = newItemsCheck[i];
			}
		}

		else std::cout << "Newsize is equal previous size" << std::endl;
	}

	void Append(T item) override {
		this.Resize(this.GetSize() + 1);
		this.Set(this->size - 1, item);
	}
};