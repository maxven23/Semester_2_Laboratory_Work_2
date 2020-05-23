#include <iostream>

#include "DynamicArray.hpp"
#include "Sequence.hpp"
#include "ArraySequence.hpp"
#include "LinkedList.hpp"
#include "ListSequence.hpp"
#include "Polynom.hpp"

using namespace std;


int main(void) {
	int deg = 5;
	int deg1 = 5;
	Polynom<int>* test;
	test = new Polynom<int>(deg);
	Polynom<int>* test1;
	test1 = new Polynom<int>(deg1);
	Polynom<int>* test2 = new Polynom<int>(1);
	

	test->Set(2, 123);
	test1->Set(2, 321);

	*test2 = *test + *test1;

	cout << test2->Get(2) << " Hehe " << test->Get(2);

	return 0;
}