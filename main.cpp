#include <iostream>
#include "Vector.hpp"
#include "test.hpp"

using namespace std;


int main(void) {

	const int INTEGER = 1;
	const int REAL = 2;
	int DIM = -1;
	int TYPE = 0;
	int MENU;
	bool NOTREADY = true;
	bool START = true;
	


	while (NOTREADY) {
		system("cls");
		cout << "----------------MENU----------------" << endl;
		cout << endl;
		cout << "1. CREATE your vector and START" << endl;
		cout << "2. Test programm" << endl;
		cout << "3. Exit" << endl;
		cout << endl;
		cout << "------------------------------------" << endl;
		cout << endl;


		cin >> MENU;

		if (MENU == 1) {

			while (DIM < 0) {
				system("cls");
				cout << "Choose DIMENSION of your Vector:" << endl;
				cout << endl;

				cin >> DIM;
			}

			while (TYPE < 1 || TYPE > 2) {
				system("cls");
				cout << "Choose TYPE of your Vector:" << endl;
				cout << endl;
				cout << "1. INTEGER" << endl;
				cout << "2. REAL" << endl;
				cout << endl;

				cin >> TYPE;

				if (TYPE == INTEGER) {
					Vector<int>* vector;
					vector = new Vector<int>(DIM);
					Vector<int>* vector_sc;
					vector_sc = new Vector<int>(DIM);

					while (START) {
						system("cls");
						cout << "----------------MENU----------------" << endl;
						cout << endl;
						cout << "1. Print vector" << endl;
						cout << "2. Change coordinates" << endl;
						cout << "3. Change dimension" << endl;
						cout << "4. Multiplication by a scalar" << endl;
						cout << "5. Add another vector" << endl;
						cout << "6. Subtract another vector" << endl;
						cout << "7. Get the norm of the vector" << endl;
						cout << "8. Scalar multiplication by a vector" << endl;
						cout << "9. Get dimension of vector" << endl;
						cout << "10. Exit" << endl;
						cout << endl;
						cout << "------------------------------------" << endl;
						cout << endl;

						cin >> MENU;

						if (MENU == 1) {
							system("cls");
							vector->Print();
							cout << endl;
							cout << "Press any button to continue . . .";
							system("pause>>VOID");
						}

						if (MENU == 2) {
							for (int i = 0; i < vector->GetDim(); i++) {
								int newcoord;
								system("cls");
								cout << "Enter " << i << "-th new coefficient: " << endl;
								cout << endl;
								
								cin >> newcoord;
								
								vector->Set(i, newcoord);
							}
							cout << endl;
							cout << "Press any button to continue . . .";
							system("pause>>VOID");
						}

						else if (MENU == 3) {
							int newdim = -1;
							while (newdim < 0) {
								system("cls");
								cout << "Choose new dimension: " << endl;
								cout << endl;

								cin >> newdim;
							}
							vector->ChangeDim(newdim);

							system("cls");
							cout << endl;
							cout << "Press any button to continue . . .";
							system("pause>>VOID");
						}

						else if (MENU == 4) {
							int mult;

							system("cls");
							cout << "Enter a multiplier: " << endl;
							cout << endl;

							cin >> mult;

							vector->Multiple(mult);
							cout << "Press any button to continue . . .";
							system("pause>>VOID");
						}

						else if (MENU == 5) {
							int CONFIRM = 0;
							Vector<int>* add = new Vector<int>(vector->GetDim());
							for (int i = 0; i < vector->GetDim(); i++) {
								system("cls");
								int temp = 0;
								cout << "Enter " << i + 1 << "-th coefficient of vector you want to ADD: " << endl;
								cout << endl;

								cin >> temp;
								add->Set(i, temp);
							}
							
							while (CONFIRM < 1 || CONFIRM > 2) {
								system("cls");
								cout << "Vector you want to add: ";

								add->Print();

								cout << endl << endl;
								cout << "1. CONFIRM" << endl;
								cout << "2. CANCEL" << endl;
								cout << endl;

								cin >> CONFIRM;
							}

							if (CONFIRM == 1) {
								*vector = *vector + *add;

								system("cls");
								cout << "Completed" << endl;
								cout << endl;
							}

							else if (CONFIRM == 2) {
								system("cls");
								cout << "Canceled" << endl;
								cout << endl;
							}

							delete[] add;
							cout << "Press any button to continue . . .";
							system("pause>>VOID");
						}

						else if (MENU == 6) {
							int CONFIRM = 0;
							Vector<int>* add = new Vector<int>(vector->GetDim());
							for (int i = 0; i < vector->GetDim(); i++) {
								system("cls");

								int temp = 0;

								cout << "Enter " << i + 1 << "-th coefficient of vector you want to ADD: " << endl;
								cout << endl;

								cin >> temp;
								add->Set(i, temp);
							}

							while (CONFIRM < 1 || CONFIRM > 2) {
								system("cls");
								cout << "Vector you want to add: ";
								add->Print();

								cout << endl << endl;
								cout << "1. CONFIRM" << endl;
								cout << "2. CANCEL" << endl;
								cout << endl;

								cin >> CONFIRM;
							}

							if (CONFIRM == 1) {
								*vector = *vector - *add;

								system("cls");
								cout << "Completed" << endl;
								cout << endl;
							}

							else if (CONFIRM == 2) {
								system("cls");
								cout << "Canceled" << endl;
								cout << endl;
							}
				
							delete[] add;
							cout << "Press any button to continue . . .";
							system("pause>>VOID");
						}

						else if (MENU == 7) {
							system("cls");
							cout << vector->norm() << endl;

							cout << endl;
							cout << "Press any button to continue . . .";
							system("pause>>VOID");
						}

						else if (MENU == 8) {
							int CONFIRM = 0;
							Vector<int>* mult = new Vector<int>(vector->GetDim());

							for (int i = 0; i < vector->GetDim(); i++) {
								system("cls");

								int temp = 0;

								cout << "Enter " << i + 1 << "-th coefficient of vector you want to ADD: " << endl;
								cout << endl;

								cin >> temp;
								mult->Set(i, temp);
							}

							while (CONFIRM < 1 || CONFIRM > 2) {
								system("cls");
								cout << "Vector you want to multiple by: ";
								mult->Print();

								cout << endl << endl;
								cout << "1. CONFIRM" << endl;
								cout << "2. CANCEL" << endl;
								cout << endl;

								cin >> CONFIRM;
							}

							if (CONFIRM == 1) {
								system("cls");
								cout << "Result: " << vector->scalar(*mult) << endl;
								cout << endl;
							}

							else if (CONFIRM == 2) {
								system("cls");
								cout << "Canceled" << endl;
								cout << endl;
							}

							delete[] mult;
							cout << "Press any button to continue . . .";
							system("pause>>VOID");
						}

						else if (MENU == 9) {
							system("cls");
							cout << "Vector dimension is  -  " << vector->GetDim() << endl;
							cout << endl;
							cout << "Press any button to continue . . .";
							system("pause>>VOID");
						}

						else if (MENU == 10) {
							system("cls");
							cout << "Closing . . ." << endl;
							exit(1);
						}
					}
				}

				else if (TYPE == REAL) {
					Vector<double>* vector;
					vector = new Vector<double>(DIM);

					while (START) {
						system("cls");
						cout << "----------------MENU----------------" << endl;
						cout << endl;
						cout << "1. Print vector" << endl;
						cout << "2. Change coordinates" << endl;
						cout << "3. Change dimension" << endl;
						cout << "4. Multiplication by a scalar" << endl;
						cout << "5. Add another vector" << endl;
						cout << "6. Subtract another vector" << endl;
						cout << "7. Get the norm of the vector" << endl;
						cout << "8. Scalar multiplication by a vector" << endl;
						cout << "9. Get dimension of vector" << endl;
						cout << "10. Exit" << endl;
						cout << endl;
						cout << "------------------------------------" << endl;
						cout << endl;

						cin >> MENU;

						if (MENU == 1) {
							system("cls");
							vector->Print();
							cout << endl;
							cout << "Press any button to continue . . .";
							system("pause>>VOID");
						}

						if (MENU == 2) {
							for (int i = 0; i < vector->GetDim(); i++) {
								double newcoord;
								system("cls");
								cout << "Enter " << i + 1 << "-th new coefficient: " << endl;
								cout << endl;

								cin >> newcoord;

								vector->Set(i, newcoord);
							}
							cout << endl;
							cout << "Press any button to continue . . .";
							system("pause>>VOID");
						}

						else if (MENU == 3) {
							int newdim = -1;
							while (newdim < 0) {
								system("cls");
								cout << "Choose new dimension: " << endl;
								cout << endl;

								cin >> newdim;
							}
							vector->ChangeDim(newdim);

							system("cls");
							cout << endl;
							cout << "Press any button to continue . . .";
							system("pause>>VOID");
						}

						else if (MENU == 4) {
							double mult;

							system("cls");
							cout << "Enter a multiplier: " << endl;
							cout << endl;

							cin >> mult;

							vector->Multiple(mult);
							cout << "Press any button to continue . . .";
							system("pause>>VOID");
						}

						else if (MENU == 5) {
							int CONFIRM = 0;
							Vector<double>* add = new Vector<double>(vector->GetDim());
							for (int i = 0; i < vector->GetDim(); i++) {
								system("cls");
								double temp = 0;
								cout << "Enter " << i + 1 << "-th coefficient of vector you want to ADD: " << endl;
								cout << endl;

								cin >> temp;
								add->Set(i, temp);
							}

							while (CONFIRM < 1 || CONFIRM > 2) {
								system("cls");
								cout << "Vector you want to add: ";

								add->Print();

								cout << endl << endl;
								cout << "1. CONFIRM" << endl;
								cout << "2. CANCEL" << endl;
								cout << endl;

								cin >> CONFIRM;
							}

							if (CONFIRM == 1) {
								*vector = *vector + *add;

								system("cls");
								cout << "Completed" << endl;
								cout << endl;
							}

							else if (CONFIRM == 2) {
								system("cls");
								cout << "Canceled" << endl;
								cout << endl;
							}

							delete[] add;
							cout << "Press any button to continue . . .";
							system("pause>>VOID");
						}

						else if (MENU == 6) {
							int CONFIRM = 0;
							Vector<double>* sub = new Vector<double>(vector->GetDim());
							for (int i = 0; i < vector->GetDim(); i++) {
								system("cls");

								double temp = 0;

								cout << "Enter " << i + 1 << "-th coefficient of vector you want to ADD: " << endl;
								cout << endl;

								cin >> temp;
								sub->Set(i, temp);
							}

							while (CONFIRM < 1 || CONFIRM > 2) {
								system("cls");
								cout << "Vector you want to add: ";
								sub->Print();

								cout << endl << endl;
								cout << "1. CONFIRM" << endl;
								cout << "2. CANCEL" << endl;
								cout << endl;

								cin >> CONFIRM;
							}

							if (CONFIRM == 1) {
								*vector = *vector - *sub;

								system("cls");
								cout << "Completed" << endl;
								cout << endl;
							}

							else if (CONFIRM == 2) {
								system("cls");
								cout << "Canceled" << endl;
								cout << endl;
							}

							delete[] sub;
							cout << "Press any button to continue . . .";
							system("pause>>VOID");
						}

						else if (MENU == 7) {
							system("cls");
							cout << vector->norm() << endl;

							cout << endl;
							cout << "Press any button to continue . . .";
							system("pause>>VOID");
						}

						else if (MENU == 8) {
							int CONFIRM = 0;
							Vector<double>* mult = new Vector<double>(vector->GetDim());

							for (int i = 0; i < vector->GetDim(); i++) {
								system("cls");

								double temp = 0;

								cout << "Enter " << i + 1 << "-th coefficient of vector you want to ADD: ";
								cout << endl;
								cout << endl;

								cin >> temp;
								mult->Set(i, temp);
							}

							while (CONFIRM < 1 || CONFIRM > 2) {
								system("cls");
								cout << "Vector you want to multiple by: ";
								mult->Print();

								cout << endl << endl;
								cout << "1. CONFIRM" << endl;
								cout << "2. CANCEL" << endl;
								cout << endl;

								cin >> CONFIRM;
							}

							if (CONFIRM == 1) {
								system("cls");
								cout << "Result: " << vector->scalar(*mult) << endl;
								cout << endl;
							}

							else if (CONFIRM == 2) {
								system("cls");
								cout << "Canceled" << endl;
								cout << endl;
							}

							delete[] mult;
							cout << "Press any button to continue . . .";
							system("pause>>VOID");
						}

						else if (MENU == 9) {
							system("cls");
							cout << "Vector dimension is  -  " << vector->GetDim() << endl;
							cout << "Press any button to continue . . .";
							system("pause>>VOID");
						}

						else if (MENU == 10) {
							delete[] vector;
							system("cls");
							cout << "Closing . . ." << endl;
							exit(1);
						}
					}
				}
			}

			NOTREADY = false;
		}

		else if (MENU == 2) {
			test();
		}

		else if (MENU == 3) {
			system("cls");
			cout << "Closing . . ." << endl;
			exit(1);
		}
	}

	return 0;
}