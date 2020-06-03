#pragma once
#include "Headers.hpp"
#include <math.h>
#include <iostream>
using namespace std;

template <class T>

class Vector {
private:
	int dim;
	Sequence<T>* coords;
public:
	
	// Конструкторы
	Vector() {
		this->dim = 0;
		this->coords = new ArraySequence<T>(0);
	};

	Vector(int dim) {
		this->dim = dim;
		this->coords = new ArraySequence<T>(dim);
	};

	// Копирующий конструктор
	Vector(ArraySequence<T>& vector) {
		this->dim = vector->GetSize;
		this->coords = new ArraySequence(vector);
	};

	// Получение размеронсти вектора
	int GetDim() {
		return this->dim;
	};

	// Получение координаты вектора по индексу
	T Get(int index) {
		return this->coords->Get(index);
	};

	// Изменение координаты вектора по индексу
	void Set(int index, T coord) {
		this->coords->Set(index, coord);
	}

	// Умножение вектора на скаляр
	void Multiple(T multiplier) {
		for (int i = 0; i < this->coords->GetSize(); i++) {
			this->coords->Set(i, this->coords->Get(i) * multiplier);
		}
	};

	// Переопределение сложения векторов
	Vector<T>& operator + (Vector<T>& vec) {
		Vector<T>* out;
		if (this->GetDim() != vec.GetDim()) {
			throw std::exception("INVALID INPUT: Vectors have different dimensions");
		}
		out = new Vector<T>(this->GetDim());
		for (int i = 0; i < this->GetDim(); i++) {
			out->coords->Set(i, this->coords->Get(i) + vec.coords->Get(i));
		}
		return *out;
	};

	// Переопределение вычитания векторов
	Vector<T>& operator - (Vector<T>& vec) {
		Vector<T>* out;
		if (this->GetDim() != vec.GetDim()) {
			throw std::exception("INVALID INPUT: Vectors have different dimensions");
		}
		out = new Vector<T>(this->GetDim());
		for (int i = 0; i < this->GetDim(); i++) {
			out->coords->Set(i, this->coords->Get(i) - vec.coords->Get(i));
		}
		return *out;
	};

	// Переопределение умножения на скаляр
	Vector<T>& operator * (T mult) const {
		Vector<T>* out;
		out = new Vector(this->GetDim());
		for (int i = 0; i < this->GetDim(); i++) {
			out->coords->Set(i, this->coords->Get(i) * mult);
		}
		return *out;
	};

	// Вычисление нормы вектора
	T norm() {
		T out = { 0 };
		for (int i = 0; i < this->GetDim(); i++) {
			out += this->coords->Get(i) * this->coords->Get(i);
		}
		out = (T)sqrt(out);
		return out;
	};

	// Скалярное произведение векторов
	T scalar(Vector<T>& vect) {
		T out = { 0 };
		for (int i = 0; i < this->GetDim(); i++) {
			out += this->coords->Get(i) * vect.coords->Get(i);
		}
		return out;
	};

	// Вывод вектора в виде его координат
	void Print() {
		cout << "Vector = (";
		for (int i = 0; i < this->GetDim() - 1; i++) {
			cout << this->coords->Get(i) << ", ";
		}
		cout << this->coords->Get(GetDim() - 1) << ")" << endl;
	}

	// Изменение размерности вектора
	void ChangeDim(int newdim) {
		if (newdim < 0) {
			throw std::exception("INVALID INPUD: New size < 0");
		}

		ArraySequence<T>* newcoords = new ArraySequence<T>(newdim);

		if (newdim < this->GetDim()) {
			for (int i = 0; i < newdim; i++) {
				newcoords->Set(i, this->coords->Get(i));
			}
		}

		else if (newdim > this->GetDim()) {
			for (int i = 0; i < this->GetDim(); i++) {
				newcoords->Set(i, this->coords->Get(i));
			}
			for (int i = this->GetDim(); i < newdim; i++) {
				newcoords->Set(i, { 0 });
			}
		}
		
		else {
			cout << "New Dimension is equal to Current Dimension" << endl;
		}

		delete[] this->coords;
		this->coords = newcoords;
		this->dim = newdim;
	};
};