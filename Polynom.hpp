#pragma once
#include "ArraySequence.hpp"
#include "Sequence.hpp"
#include "ListSequence.hpp"
#include "DynamicArray.hpp"
#include "LinkedList.hpp"
#include <complex>

template <class T>

class Polynom {
private:
	ArraySequence<T>* coefficients;
	int degree;
public:
	Polynom() {
		this->degree = 0;
		this->coefficients = new ArraySequence<T>();
	};

	Polynom(int degree) {
		this->degree = degree;
		this->coefficients = new ArraySequence<T>(degree);
	};

	Polynom(Sequence<T>& polynom) {
		this->coefficients = new ArraySequence<T>(polynom);
	};

	int GetDegree() {
		return this->coefficients->GetSize();
	};

	Polynom<T>& operator + (Polynom& polynom) {
		Polynom<T>* newpoly;
		if (this->GetDegree() >= polynom.GetDegree()) {
			int tempDeg = this->degree;
			newpoly = new Polynom<T>(tempDeg);
			for (int i = 0; i < polynom.GetDegree(); i++) {
				newpoly->coefficients->Set(i, this->coefficients->Get(i) + polynom.coefficients->Get(i));
			}
		}
		else {
			int tempDeg = this->degree;
			newpoly = new Polynom<T>(polynom.GetDegree());
			for (int i = tempDeg; i < polynom.GetDegree(); i++) {
				newpoly->coefficients->Set(i, polynom.coefficients->Get(i));
			}
			for (int i = 0; i < tempDeg; i++) {
				newpoly->coefficients->Set(i, this->coefficients->Get(i) + polynom.coefficients->Get(i));
			}
		}
		return *newpoly;
	};

	void Set(int i, T item) {
		this->coefficients->Set(i, item);
	};

	T Get(int i) {
		return this->coefficients->Get(i);
	}

};