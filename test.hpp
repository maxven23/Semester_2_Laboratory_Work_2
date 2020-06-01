#pragma once
#include "Headers.hpp"
#include <iostream>

using namespace std;

// Сообщение работы функций / операций
void message(const char foo[50]) {
	cout.width(25);
	cout.setf(ios::left);
	cout << foo;
	cout.width(6);
	cout << " is OK" << endl;
}

// Тестирование функций производится только на интовом векторе
void test() {
	Vector<int>* vect_int = new Vector<int>(106);

	vect_int->Print();

	system("cls");
	message("Print()");

	system("cls");
	for (int i = 0; i < vect_int->GetDim(); i++) {
		int newcoord;
		newcoord = rand() - (RAND_MAX / 2);
		vect_int->Set(i, newcoord);
	}
	system("cls");

	message("Print()");
	message("Set()");

	system("cls");

	int newdim = 35;
	vect_int->ChangeDim(newdim);
	system("cls");

	message("Print()");
	message("Set()");
	message("ChangeDim()");

	system("cls");

	int mult;
	mult = RAND_MAX + rand();
	vect_int->Multiple(mult);
	system("cls");

	message("Print()");
	message("Set()");
	message("ChangeDim()");
	message("Multiple()");

	system("cls");

	Vector<int>* addvec = new Vector<int>(vect_int->GetDim());
	for (int i = 0; i < vect_int->GetDim(); i++) {
		system("cls");
		int temp = 0;
		temp = rand() - (RAND_MAX / 2);
		addvec->Set(i, temp);
	}
	*vect_int = *vect_int + *addvec;
	vect_int->Print();
	delete[] addvec;
	system("cls");

	message("Print()");
	message("Set()");
	message("ChangeDim()");
	message("Multiple()");
	message("Adding a vector");

	system("cls");


	Vector<int>* sub = new Vector<int>(vect_int->GetDim());
	for (int i = 0; i < vect_int->GetDim(); i++) {
		int temp = 0;
		temp = rand() - (RAND_MAX / 2);
		sub->Set(i, temp);
	}
	*vect_int = *vect_int - *sub;
	vect_int->Print();
	delete[] sub;
	system("cls");

	message("Print()");
	message("Set()");
	message("ChangeDim()");
	message("Multiple()");
	message("Adding a vector");
	message("Subtracting a vector");

	system("cls");

	cout << vect_int->norm() << endl;
	system("cls");

	message("Print()");
	message("Set()");
	message("ChangeDim()");
	message("Multiple()");
	message("Adding a vector");
	message("Subtracting a vector");
	message("Norm()");

	system("cls");


	Vector<int>* vec;
	vec = new Vector<int>(vect_int->GetDim());

	for (int i = 0; i < vect_int->GetDim(); i++) {
		int temp;
		temp = rand() - (RAND_MAX / 2);
		vec->Set(i, temp);
	}
	cout << vect_int->scalar(*vec);
	delete[] vec;
	system("cls");

	message("Print()");
	message("Set()");
	message("ChangeDim()");
	message("Multiple()");
	message("Adding a vector");
	message("Subtracting a vector");
	message("Norm()");
	message("Scalar()");

	system("cls");


	cout << "Vector dimension is  -  " << vect_int->GetDim() << endl;
	system("cls");

	message("Print()");
	message("Set()");
	message("ChangeDim()");
	message("Multiple()");
	message("Adding a vector");
	message("Subtracting a vector");
	message("Norm()");
	message("Scalar()");
	message("GetDim()");

	cout << endl << endl << "Press any button to continue . . .";
	system("pause>>VOID");

}	