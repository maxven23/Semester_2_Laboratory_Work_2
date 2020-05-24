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

	Polynom<T>& operator + (Polynom<T>& polynom) {
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

	T Get(int wdegree) {
		return this->coefficients->Get(wdegree);
	};

	Polynom<T>& operator - (Polynom<T>&  polynom) {
		Polynom<T>* newpoly;
		if (this->GetDegree() >= polynom.GetDegree()) {
			int tempDeg = this->degree;
			newpoly = new Polynom<T>(tempDeg);
			for (int i = 0; i < polynom.GetDegree(); i++) {
				newpoly->coefficients->Set(i, this->coefficients->Get(i) - polynom.coefficients->Get(i));
			}
		}
		else {
			int tempDeg = this->degree;
			newpoly = new Polynom<T>(polynom.GetDegree());
			for (int i = tempDeg; i < polynom.GetDegree(); i++) {
				newpoly->coefficients->Set(i, polynom.coefficients->Get(i));
			}
			for (int i = 0; i < tempDeg; i++) {
				newpoly->coefficients->Set(i, this->coefficients->Get(i) - polynom.coefficients->Get(i));
			}
		}
		return *newpoly;
	};

	Polynom<T>& operator * (T multiplier) {
		Polynom<T>* newpoly;
		newpoly = new Polynom<T>(this->degree);
		for (int i = 0; i < this->degree; i++) {
			newpoly->coefficients->Set(i, this->coefficients->Get(i) * multiplier);
		}
		return *newpoly;
	};

	Polynom<T>& operator / (T divider) {
		if (divider == 0)
			throw std::exception("INVALID INPUT: Division by ZERO");
		Polynom<T>* newpoly;
		newpoly = new Polynom<T>(this->GetDegree());
		for (int i = 0; i < this->GetDegree(); i++) {
			newpoly->coefficients->Set(i, this->coefficients->Get(i) / divider);
		}
		return *newpoly;
	};

	void Calculate(T x) {
		T result = { 0 };
		for (int i = 0; i < this->GetDegree(); i++) {
			result = result + (this->coefficients->Get(i) * (pow(x, i)));
		}
		std::cout << result << std::endl;
	};

	void Print() {
		for (int i = 0; i < this->GetDegree() - 1; i++) {
			std::cout << this->coefficients->Get(i) << " * x^" << i << " + ";
		}
		std::cout << this->coefficients->Get(this->GetDegree() - 1) << " * x^" << this->GetDegree() - 1 << std::endl;
	};

	
	Polynom<T>& operator * (Polynom<T>& poly) {
		Polynom<T>* newpoly;
		newpoly = new Polynom<T>(this->GetDegree() + poly.GetDegree());
		T* newcoef = new T[this->GetDegree() + poly.GetDegree()];
		for (int i = 0; i < this->GetDegree() + poly.GetDegree(); ++i) {
			newcoef[i] = { 0 };
		}

		for (int i = 0; i < this->GetDegree(); ++i) {
			for (int j = 0; j < poly.GetDegree(); ++j) {
				newcoef[i + j] += this->coefficients->Get(i) * poly.coefficients->Get(j);
				newpoly->coefficients->Set(i + j, newcoef[i + j]);
			}
		}
		return *newpoly;
	};

	void Compose(Polynom<T>& poly) {
		Polynom<T>* newpoly;
		newpoly = new Polynom<T>(this->GetDegree() * poly.GetDegree());

	};
	

};