#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
int main()
{
	/*----------FIRST OUTPUT---------*/
	cout << "Welcome to the program\n";
	cout << "In this program you will be able to do operations on matrices of size 3*3 only \n";

	/*----------FIRST WHILE LOOP WHICH WILL BE USED TO CLOSE THE PROGRAM----------*/
	string the_first_text;
	for (1; the_first_text != "exit";)
	{
		string line_of_matrixA;
		double matrixA_1D_array[9] = { 0 };
		int iA = 0, kA = 0;
		double matrixA_2D_array[3][3] = { 0 };
		string line_of_matrixB;
		double matrixB_1D_array[9] = { 0 };
		int iB = 0, kB = 0;
		double matrixB_2D_array[3][3] = { 0 };
		double the_sum[3][3] = { 0 };
		double the_sub[3][3] = { 0 };
		double transpose_of_matrixA[3][3] = { 0 };
		double transpose_of_matrixB[3][3] = { 0 };
		double multiplication[3][3] = { 0 };
		double cofactor[3][3] = { 0 };
		double det = 1;
		double inverse_function[3][3] = { 0 };
		double transpose_to_get_inverse[3][3];
		double division[3][3] = { 0 };
		int counter = 1;
		char letter_of_operation;
		string the_second_text;

		/*----------FIRST OUTPUT FOR MATRIX INPUT---------*/
		cout << "Please enter matrix A with 9 numbers in the form of: [a1 a2 a3; a4 a5 a6; a7 a8 a9] \n";
		cout << "Use semicolons to separate between rows \n";

		/*-----------FIRST INPUT IN FORM OF STRING & REMOVING BRAKETS & SEMICOLONS----------*/
		getline(cin, line_of_matrixA);
		cin.clear();
		line_of_matrixA.erase(remove(line_of_matrixA.begin(), line_of_matrixA.end(), ';'), line_of_matrixA.end());
		line_of_matrixA.erase(remove(line_of_matrixA.begin(), line_of_matrixA.end(), '['), line_of_matrixA.end());
		line_of_matrixA.erase(remove(line_of_matrixA.begin(), line_of_matrixA.end(), ']'), line_of_matrixA.end());

		/*----------CONVERTING THE INPUT FROM STRING TO ARRAY OF FLOAT----------*/
		stringstream ssA(line_of_matrixA);

		while (getline(ssA, line_of_matrixA, ' '))
		{
			matrixA_1D_array[iA] = stof(line_of_matrixA);
			iA++;
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				matrixA_2D_array[i][j] = matrixA_1D_array[kA];
				kA++;
			}
		}

		/*---------SECOND OUTPUT----------*/
		cout << "Please enter matrix B with 9 numbers in the form of: [b1 b2 b3; b4 b5 b6; b7 b8 b9] \n";
		cout << "Use semi-colons to sperate between rows \n";

		/*-----------SECOND INPUT IN FORM OF STRING & REMOVING BRAKETS & SEMICOLONS----------*/
		getline(cin, line_of_matrixB);
		cin.clear();

		line_of_matrixB.erase(remove(line_of_matrixB.begin(), line_of_matrixB.end(), ';'), line_of_matrixB.end());
		line_of_matrixB.erase(remove(line_of_matrixB.begin(), line_of_matrixB.end(), '['), line_of_matrixB.end());
		line_of_matrixB.erase(remove(line_of_matrixB.begin(), line_of_matrixB.end(), ']'), line_of_matrixB.end());

		/*----------CONVERTING THE INPUT FROM STRING TO ARRAY OF FLOAT----------*/
		stringstream ssB(line_of_matrixB);

		while (getline(ssB, line_of_matrixB, ' '))
		{
			matrixB_1D_array[iB] = stof(line_of_matrixB);
			iB++;
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				matrixB_2D_array[i][j] = matrixB_1D_array[kB];
				kB++;
			}
		}

		/*-----------OPERATIONS OUTPUT----------*/
		cout << "Type the letter of any operation: \n";
		cout << "a. Show matrix A \n";
		cout << "b. Show matrix B \n";
		cout << "c. Addition: (C= A + B) \n";
		cout << "d. Subtraction: (C= A - B) \n";
		cout << "e. Multiplication: (C= A * B) \n";
		cout << "f. Transpose of matrix A: (C= A') \n";
		cout << "g. Transpose of matrix B: (C= B') \n";
		cout << "h. Division: (C= A/B) \n";

		/*-----------OPERATIONS INPUT----------*/
		cin >> letter_of_operation;

		/*----------THE FIRST SWITCH CASE TO SWITCH BETWEEN OPERATIONS----------*/
		switch (letter_of_operation)
		{
		case 'a':
			cout << "Matrix A = " << endl;

			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					cout << matrixA_2D_array[i][j] << "\t";
				}
				cout << endl;
			}

			/*----------OUTPUT & INPUT WHICH WILL DECIDE THE NEXT STEP----------*/
			cout << "Do you want to choose another operator or no?\n";
			cout << "If yes type yes\n";
			cout << "If no type no\n";
			cin >> the_second_text;

			/*----------SMALL WHILE LOOP TO LET YOU CHOOSE ANOTHER OPERATIONS----------*/
			while (1 && the_second_text != "no")
			{
				/*----------INPUT & OUTPUT TO LET YOU CHOOSE MORE OPERATIONS----------*/
				cout << "Type the letter of any operation \n";
				cout << "a. Show matrix A \n";
				cout << "b. Show matrix B \n";
				cout << "c. Addition: (C= A + B) \n";
				cout << "d. Subtraction: (C= A - B) \n";
				cout << "e. Multiplication: (C= A * B) \n";
				cout << "f. Transpose of matrix A: (C= A') \n";
				cout << "g. Transpose of matrix B: (C= B') \n";
				cout << "h. Division: (C= A/B) \n";
				cin >> letter_of_operation;

				/*----------SMALL SWITCH CASE TO GIVE YOU THE ANSWER--------*/
				switch (letter_of_operation)
				{
				case'a':
					cout << "Matrix A = " << endl;

					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << matrixA_2D_array[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ? \n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case 'b':
					cout << "Matrix B = " << endl;

					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << matrixB_2D_array[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case 'c':
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							the_sum[i][j] = matrixA_2D_array[i][j] + matrixB_2D_array[i][j];
						}
					}

					cout << "The sum of matrix A and matrix B =" << endl;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << the_sum[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case'd':
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							the_sub[i][j] = matrixA_2D_array[i][j] - matrixB_2D_array[i][j];
						}
					}
					cout << "The subtraction of matrix A - matrix B =" << endl;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << the_sub[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case'e':
					for (int i = 0; i < 3; i++)
						for (int j = 0; j < 3; j++) {
							for (int u = 0; u < 3; u++)
								multiplication[i][j] += matrixA_2D_array[i][u] * matrixB_2D_array[u][j];
						}
					cout << "The product of matrix A * matrix B =" << endl;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << multiplication[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ? \n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case'f':
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							transpose_of_matrixA[j][i] = matrixA_2D_array[i][j];
						}

					}
					cout << "The transpose of matrix A =" << endl;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << transpose_of_matrixA[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case'g':
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							transpose_of_matrixB[j][i] = matrixB_2D_array[i][j];
						}

					}
					cout << "The transpose of matrix B =" << endl;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << transpose_of_matrixB[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case'h':
					/*-----------THE DETERMINANT OF MATRIX B----------*/
					det = (double)((matrixB_2D_array[0][0]) * ((matrixB_2D_array[1][1] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][1] * matrixB_2D_array[1][2])))
						+ ((double)((matrixB_2D_array[0][1]) * ((matrixB_2D_array[1][0] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][2])) * (-1.0)))
						+ ((double)((matrixB_2D_array[0][2]) * ((matrixB_2D_array[1][0] * matrixB_2D_array[2][1]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][1]))));
					if (det != 0)
					{
						/*----------THE COFACTORS OF MATRIX B---------*/
						cofactor[0][0] = (((matrixB_2D_array[1][1] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][1] * matrixB_2D_array[1][2])) * (-1));
						cofactor[0][1] = (((matrixB_2D_array[1][0] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][2])) * (-1));
						cofactor[0][1] = ((matrixB_2D_array[1][0] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][2]));
						cofactor[0][2] = (((matrixB_2D_array[1][0] * matrixB_2D_array[2][1]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][1])) * (-1));
						cofactor[1][0] = ((matrixB_2D_array[0][1] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][1] * matrixB_2D_array[0][2]));
						cofactor[1][1] = (((matrixB_2D_array[0][0] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][0] * matrixB_2D_array[0][2])) * (-1));
						cofactor[1][2] = ((matrixB_2D_array[0][0] * matrixB_2D_array[2][1]) - (matrixB_2D_array[2][0] * matrixB_2D_array[0][1]));
						cofactor[2][0] = (((matrixB_2D_array[0][1] * matrixB_2D_array[1][2]) - (matrixB_2D_array[1][1] * matrixB_2D_array[0][2])) * (-1));
						cofactor[2][1] = ((matrixB_2D_array[0][0] * matrixB_2D_array[1][2]) - (matrixB_2D_array[1][0] * matrixB_2D_array[0][2]));
						cofactor[2][2] = (((matrixB_2D_array[0][0] * matrixB_2D_array[1][1]) - (matrixB_2D_array[1][0] * matrixB_2D_array[0][1])) * (-1));

						/*----------FINAL INVERSE FUNCTION----------*/
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								inverse_function[i][j] = cofactor[i][j] * ((1 / det) * (-1));
							}
						}
						// the transpose
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								transpose_to_get_inverse[j][i] = inverse_function[i][j];
							}

						}

						cout << "The result of matrix A/matrix B =\n";
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								division[i][j] = 0;
								for (int k = 0; k < 3; k++)
								{
									division[i][j] += (matrixA_2D_array[i][k] * transpose_to_get_inverse[k][j]);
								}
							}
						}
						//for printing result    
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								cout << division[i][j] << " ";
							}
							cout << "\n";
						}
						cout << "Do you want to do another operation ?\n";
						cout << "If yes type yes \n";
						cout << "If no type no \n";
						cin >> the_second_text;
					}
					else
					{
						cout << "This division can't be done\n";
						cout << "Do you want to do another operation ?\n";
						cout << "If yes type yes \n";
						cout << "If no type no \n";
						cin >> the_second_text;
					}
					break;
				}


			}

			cout << "Do you want to enter another two matrices or exit?\n";
			cin >> the_first_text;
			cin.ignore();
			cin.clear();

			break;

		case 'b':
			cout << "Matrix B = " << endl;

			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					cout << matrixB_2D_array[i][j] << "\t";
				}
				cout << endl;
			}
			/*----------OUTPUT & INPUT WHICH WILL DECIDE THE NEXT STEP----------*/
			cout << "Do you want to choose another operator or no?\n";
			cout << "If yes type yes\n";
			cout << "If no type no\n";
			cin >> the_second_text;

			/*----------SMALL WHILE LOOP TO LET YOU CHOOSE ANOTHER OPERATIONS----------*/
			while (1 && the_second_text != "no")
			{
				/*----------INPUT & OUTPUT TO LET YOU CHOOSE MORE OPERATIONS----------*/
				cout << "Type the letter of any operation \n";
				cout << "a. Show matrix A \n";
				cout << "b. Show matrix B \n";
				cout << "c. Addition: (C= A + B) \n";
				cout << "d. Subtraction: (C= A - B) \n";
				cout << "e. Multiplication: (C= A * B) \n";
				cout << "f. Transpose of matrix A: (C= A') \n";
				cout << "g. Transpose of matrix B: (C= B') \n";
				cout << "h. Division: (C= A/B) \n";
				cin >> letter_of_operation;

				/*----------SMALL SWITCH CASE TO GIVE YOU THE ANSWER--------*/
				switch (letter_of_operation)
				{
				case'a':
					cout << "Matrix A = " << endl;

					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << matrixA_2D_array[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case 'b':
					cout << "Matrix B = " << endl;

					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << matrixB_2D_array[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case 'c':
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							the_sum[i][j] = matrixA_2D_array[i][j] + matrixB_2D_array[i][j];
						}
					}

					cout << "The sum of matrix A and matrix B =" << endl;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << the_sum[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case'd':
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							the_sub[i][j] = matrixA_2D_array[i][j] - matrixB_2D_array[i][j];
						}
					}
					cout << "The subtraction of matrix A - matrix B =" << endl;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << the_sub[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case'e':
					for (int i = 0; i < 3; i++)
						for (int j = 0; j < 3; j++) {
							for (int u = 0; u < 3; u++)
								multiplication[i][j] += matrixA_2D_array[i][u] * matrixB_2D_array[u][j];
						}
					cout << "The product of matrix A * matrix B =" << endl;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << multiplication[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case'f':
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							transpose_of_matrixA[j][i] = matrixA_2D_array[i][j];
						}

					}
					cout << "The transpose of matrix A =" << endl;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << transpose_of_matrixA[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case'g':
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							transpose_of_matrixB[j][i] = matrixB_2D_array[i][j];
						}

					}
					cout << "The transpose of matrix B =" << endl;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << transpose_of_matrixB[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case'h':
					/*-----------THE DETERMINANT OF MATRIX B----------*/
					det = (double)((matrixB_2D_array[0][0]) * ((matrixB_2D_array[1][1] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][1] * matrixB_2D_array[1][2])))
						+ ((double)((matrixB_2D_array[0][1]) * ((matrixB_2D_array[1][0] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][2])) * (-1.0)))
						+ ((double)((matrixB_2D_array[0][2]) * ((matrixB_2D_array[1][0] * matrixB_2D_array[2][1]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][1]))));
					if (det != 0)
					{
						/*----------THE COFACTORS OF MATRIX B---------*/
						cofactor[0][0] = (((matrixB_2D_array[1][1] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][1] * matrixB_2D_array[1][2])) * (-1));
						cofactor[0][1] = (((matrixB_2D_array[1][0] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][2])) * (-1));
						cofactor[0][1] = ((matrixB_2D_array[1][0] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][2]));
						cofactor[0][2] = (((matrixB_2D_array[1][0] * matrixB_2D_array[2][1]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][1])) * (-1));
						cofactor[1][0] = ((matrixB_2D_array[0][1] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][1] * matrixB_2D_array[0][2]));
						cofactor[1][1] = (((matrixB_2D_array[0][0] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][0] * matrixB_2D_array[0][2])) * (-1));
						cofactor[1][2] = ((matrixB_2D_array[0][0] * matrixB_2D_array[2][1]) - (matrixB_2D_array[2][0] * matrixB_2D_array[0][1]));
						cofactor[2][0] = (((matrixB_2D_array[0][1] * matrixB_2D_array[1][2]) - (matrixB_2D_array[1][1] * matrixB_2D_array[0][2])) * (-1));
						cofactor[2][1] = ((matrixB_2D_array[0][0] * matrixB_2D_array[1][2]) - (matrixB_2D_array[1][0] * matrixB_2D_array[0][2]));
						cofactor[2][2] = (((matrixB_2D_array[0][0] * matrixB_2D_array[1][1]) - (matrixB_2D_array[1][0] * matrixB_2D_array[0][1])) * (-1));

						/*----------FINAL INVERSE FUNCTION----------*/
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								inverse_function[i][j] = cofactor[i][j] * ((1 / det) * (-1));
							}
						}
						// the transpose
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								transpose_to_get_inverse[j][i] = inverse_function[i][j];
							}

						}

						cout << "The result of matrix A/matrix B =\n";
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								division[i][j] = 0;
								for (int k = 0; k < 3; k++)
								{
									division[i][j] += (matrixA_2D_array[i][k] * transpose_to_get_inverse[k][j]);
								}
							}
						}
						//for printing result    
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								cout << division[i][j] << " ";
							}
							cout << "\n";
						}
						cout << "Do you want to do another operation ?\n";
						cout << "If yes type yes \n";
						cout << "If no type no \n";
						cin >> the_second_text;
					}
					else
					{
						cout << "This division can't be done\n";
						cout << "Do you want to do another operation ?\n";
						cout << "If yes type yes \n";
						cout << "If no type no \n";
						cin >> the_second_text;
					}
					break;
				}
			}

			cout << "Do you want to enter another two matrices or exit ?\n";
			cin >> the_first_text;
			cin.ignore();
			cin.clear();
			break;



		case 'c':
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					the_sum[i][j] = matrixA_2D_array[i][j] + matrixB_2D_array[i][j];
				}
			}

			cout << "The sum of matrix A and matrix B =" << endl;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					cout << the_sum[i][j] << "\t";
				}
				cout << endl;
			}
			/*----------OUTPUT & INPUT WHICH WILL DECIDE THE NEXT STEP----------*/
			cout << "Do you want to choose another operator or no?\n";
			cout << "If yes type yes\n";
			cout << "If no type no\n";
			cin >> the_second_text;

			/*----------SMALL WHILE LOOP TO LET YOU CHOOSE ANOTHER OPERATIONS----------*/
			while (1 && the_second_text != "no")
			{
				/*----------INPUT & OUTPUT TO LET YOU CHOOSE MORE OPERATIONS----------*/
				cout << "Type the letter of any operation \n";
				cout << "a. Show matrix A \n";
				cout << "b. Show matrix B \n";
				cout << "c. Addition: (C= A + B) \n";
				cout << "d. Subtraction: (C= A - B) \n";
				cout << "e. Multiplication: (C= A * B) \n";
				cout << "f. Transpose of matrix A: (C= A') \n";
				cout << "g. Transpose of matrix B: (C= B') \n";
				cout << "h. Division: (C= A/B) \n";
				cin >> letter_of_operation;

				/*----------SMALL SWITCH CASE TO GIVE YOU THE ANSWER--------*/
				switch (letter_of_operation)
				{
				case'a':
					cout << "Matrix A = " << endl;

					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << matrixA_2D_array[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case 'b':
					cout << "Matrix B = " << endl;

					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << matrixB_2D_array[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case 'c':
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							the_sum[i][j] = matrixA_2D_array[i][j] + matrixB_2D_array[i][j];
						}
					}

					cout << "The sum of matrix A and matrix B =" << endl;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << the_sum[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case'd':
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							the_sub[i][j] = matrixA_2D_array[i][j] - matrixB_2D_array[i][j];
						}
					}
					cout << "The subtraction of matrix A - matrix B =" << endl;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << the_sub[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case'e':
					for (int i = 0; i < 3; i++)
						for (int j = 0; j < 3; j++) {
							for (int u = 0; u < 3; u++)
								multiplication[i][j] += matrixA_2D_array[i][u] * matrixB_2D_array[u][j];
						}
					cout << "The product of matrix A * matrix B =" << endl;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << multiplication[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case'f':
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							transpose_of_matrixA[j][i] = matrixA_2D_array[i][j];
						}

					}
					cout << "The transpose of matrix A =" << endl;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << transpose_of_matrixA[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case'g':
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							transpose_of_matrixB[j][i] = matrixB_2D_array[i][j];
						}

					}
					cout << "The transpose of matrix B =" << endl;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << transpose_of_matrixB[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case'h':
					/*-----------THE DETERMINANT OF MATRIX B----------*/
					det = (double)((matrixB_2D_array[0][0]) * ((matrixB_2D_array[1][1] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][1] * matrixB_2D_array[1][2])))
						+ ((double)((matrixB_2D_array[0][1]) * ((matrixB_2D_array[1][0] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][2])) * (-1.0)))
						+ ((double)((matrixB_2D_array[0][2]) * ((matrixB_2D_array[1][0] * matrixB_2D_array[2][1]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][1]))));
					if (det != 0)
					{
						/*----------THE COFACTORS OF MATRIX B---------*/
						cofactor[0][0] = (((matrixB_2D_array[1][1] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][1] * matrixB_2D_array[1][2])) * (-1));
						cofactor[0][1] = (((matrixB_2D_array[1][0] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][2])) * (-1));
						cofactor[0][1] = ((matrixB_2D_array[1][0] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][2]));
						cofactor[0][2] = (((matrixB_2D_array[1][0] * matrixB_2D_array[2][1]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][1])) * (-1));
						cofactor[1][0] = ((matrixB_2D_array[0][1] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][1] * matrixB_2D_array[0][2]));
						cofactor[1][1] = (((matrixB_2D_array[0][0] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][0] * matrixB_2D_array[0][2])) * (-1));
						cofactor[1][2] = ((matrixB_2D_array[0][0] * matrixB_2D_array[2][1]) - (matrixB_2D_array[2][0] * matrixB_2D_array[0][1]));
						cofactor[2][0] = (((matrixB_2D_array[0][1] * matrixB_2D_array[1][2]) - (matrixB_2D_array[1][1] * matrixB_2D_array[0][2])) * (-1));
						cofactor[2][1] = ((matrixB_2D_array[0][0] * matrixB_2D_array[1][2]) - (matrixB_2D_array[1][0] * matrixB_2D_array[0][2]));
						cofactor[2][2] = (((matrixB_2D_array[0][0] * matrixB_2D_array[1][1]) - (matrixB_2D_array[1][0] * matrixB_2D_array[0][1])) * (-1));

						/*----------FINAL INVERSE FUNCTION----------*/
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								inverse_function[i][j] = cofactor[i][j] * ((1 / det) * (-1));
							}
						}
						// the transpose
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								transpose_to_get_inverse[j][i] = inverse_function[i][j];
							}

						}

						cout << "The result of matrix A/matrix B =\n";
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								division[i][j] = 0;
								for (int k = 0; k < 3; k++)
								{
									division[i][j] += (matrixA_2D_array[i][k] * transpose_to_get_inverse[k][j]);
								}
							}
						}
						//for printing result    
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								cout << division[i][j] << " ";
							}
							cout << "\n";
						}
						cout << "Do you want to do another operation ?\n";
						cout << "If yes type yes \n";
						cout << "If no type no \n";
						cin >> the_second_text;
					}
					else
					{
						cout << "This division can't be done\n";
						cout << "Do you want to do another operation ?\n";
						cout << "If yes type yes \n";
						cout << "If no type no \n";
						cin >> the_second_text;
					}
					break;
				}
			}

			cout << "Do you want to enter another two matrices or exit ?\n";
			cin >> the_first_text;
			cin.ignore();
			cin.clear();
			break;


		case'd':
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					the_sub[i][j] = matrixA_2D_array[i][j] - matrixB_2D_array[i][j];
				}
			}

			cout << "The subtraction of matrix A - matrix B =" << endl;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					cout << the_sub[i][j] << "\t";
				}
				cout << endl;
			}
			/*----------OUTPUT & INPUT WHICH WILL DECIDE THE NEXT STEP----------*/
			cout << "Do you want to choose another operator or no?\n";
			cout << "If yes type yes\n";
			cout << "If no type no\n";
			cin >> the_second_text;

			/*----------SMALL WHILE LOOP TO LET YOU CHOOSE ANOTHER OPERATIONS----------*/
			while (1 && the_second_text != "no")
			{
				/*----------INPUT & OUTPUT TO LET YOU CHOOSE MORE OPERATIONS----------*/
				cout << "Type the letter of any operation \n";
				cout << "a. Show matrix A \n";
				cout << "b. Show matrix B \n";
				cout << "c. Addition: (C= A + B) \n";
				cout << "d. Subtraction: (C= A - B) \n";
				cout << "e. Multiplication: (C= A * B) \n";
				cout << "f. Transpose of matrix A: (C= A') \n";
				cout << "g. Transpose of matrix B: (C= B') \n";
				cout << "h. Division: (C= A/B) \n";
				cin >> letter_of_operation;

				/*----------SMALL SWITCH CASE TO GIVE YOU THE ANSWER--------*/
				switch (letter_of_operation)
				{
				case'a':
					cout << "Matrix A = " << endl;

					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << matrixA_2D_array[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case 'b':
					cout << "Matrix B = " << endl;

					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << matrixB_2D_array[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case 'c':
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							the_sum[i][j] = matrixA_2D_array[i][j] + matrixB_2D_array[i][j];
						}
					}

					cout << "The sum of matrix A and matrix B =" << endl;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << the_sum[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case'd':
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							the_sub[i][j] = matrixA_2D_array[i][j] - matrixB_2D_array[i][j];
						}
					}
					cout << "The subtraction of matrix A - matrix B =" << endl;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << the_sub[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case'e':
					for (int i = 0; i < 3; i++)
						for (int j = 0; j < 3; j++) {
							for (int u = 0; u < 3; u++)
								multiplication[i][j] += matrixA_2D_array[i][u] * matrixB_2D_array[u][j];
						}
					cout << "The product of matrix A * matrix B =" << endl;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << multiplication[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case'f':
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							transpose_of_matrixA[j][i] = matrixA_2D_array[i][j];
						}

					}
					cout << "The transpose of matrix A =" << endl;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << transpose_of_matrixA[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case'g':
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							transpose_of_matrixB[j][i] = matrixB_2D_array[i][j];
						}

					}
					cout << "The transpose of matrix B =" << endl;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << transpose_of_matrixB[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case'h':
					/*-----------THE DETERMINANT OF MATRIX B----------*/
					det = (double)((matrixB_2D_array[0][0]) * ((matrixB_2D_array[1][1] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][1] * matrixB_2D_array[1][2])))
						+ ((double)((matrixB_2D_array[0][1]) * ((matrixB_2D_array[1][0] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][2])) * (-1.0)))
						+ ((double)((matrixB_2D_array[0][2]) * ((matrixB_2D_array[1][0] * matrixB_2D_array[2][1]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][1]))));
					if (det != 0)
					{
						/*----------THE COFACTORS OF MATRIX B---------*/
						cofactor[0][0] = (((matrixB_2D_array[1][1] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][1] * matrixB_2D_array[1][2])) * (-1));
						cofactor[0][1] = (((matrixB_2D_array[1][0] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][2])) * (-1));
						cofactor[0][1] = ((matrixB_2D_array[1][0] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][2]));
						cofactor[0][2] = (((matrixB_2D_array[1][0] * matrixB_2D_array[2][1]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][1])) * (-1));
						cofactor[1][0] = ((matrixB_2D_array[0][1] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][1] * matrixB_2D_array[0][2]));
						cofactor[1][1] = (((matrixB_2D_array[0][0] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][0] * matrixB_2D_array[0][2])) * (-1));
						cofactor[1][2] = ((matrixB_2D_array[0][0] * matrixB_2D_array[2][1]) - (matrixB_2D_array[2][0] * matrixB_2D_array[0][1]));
						cofactor[2][0] = (((matrixB_2D_array[0][1] * matrixB_2D_array[1][2]) - (matrixB_2D_array[1][1] * matrixB_2D_array[0][2])) * (-1));
						cofactor[2][1] = ((matrixB_2D_array[0][0] * matrixB_2D_array[1][2]) - (matrixB_2D_array[1][0] * matrixB_2D_array[0][2]));
						cofactor[2][2] = (((matrixB_2D_array[0][0] * matrixB_2D_array[1][1]) - (matrixB_2D_array[1][0] * matrixB_2D_array[0][1])) * (-1));

						/*----------FINAL INVERSE FUNCTION----------*/
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								inverse_function[i][j] = cofactor[i][j] * ((1 / det) * (-1));
							}
						}
						// the transpose
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								transpose_to_get_inverse[j][i] = inverse_function[i][j];
							}

						}

						cout << "The result of matrix A/matrix B =\n";
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								division[i][j] = 0;
								for (int k = 0; k < 3; k++)
								{
									division[i][j] += (matrixA_2D_array[i][k] * transpose_to_get_inverse[k][j]);
								}
							}
						}
						//for printing result    
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								cout << division[i][j] << " ";
							}
							cout << "\n";
						}
						cout << "Do you want to do another operation ?\n";
						cout << "If yes type yes \n";
						cout << "If no type no \n";
						cin >> the_second_text;
					}
					else
					{
						cout << "This division can't be done\n";
						cout << "Do you want to do another operation ?\n";
						cout << "If yes type yes \n";
						cout << "If no type no \n";
						cin >> the_second_text;
					}
					break;
				}
			}

			cout << "Do you want to enter another two matrices or exit ?\n";
			cin >> the_first_text;
			cin.ignore();
			cin.clear();
			break;


		case'e':
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++) {
					for (int u = 0; u < 3; u++)
						multiplication[i][j] += matrixA_2D_array[i][u] * matrixB_2D_array[u][j];
				}

			cout << "The product of matrix A * matrix B =" << endl;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					cout << multiplication[i][j] << "\t";
				}
				cout << endl;
			}
			/*----------OUTPUT & INPUT WHICH WILL DECIDE THE NEXT STEP----------*/
			cout << "Do you want to choose another operator or no?\n";
			cout << "If yes type yes\n";
			cout << "If no type no\n";
			cin >> the_second_text;

			/*----------SMALL WHILE LOOP TO LET YOU CHOOSE ANOTHER OPERATIONS----------*/
			while (1 && the_second_text != "no")
			{
				/*----------INPUT & OUTPUT TO LET YOU CHOOSE MORE OPERATIONS----------*/
				cout << "Type the letter of any operation \n";
				cout << "a. Show matrix A \n";
				cout << "b. Show matrix B \n";
				cout << "c. Addition: (C= A + B) \n";
				cout << "d. Subtraction: (C= A - B) \n";
				cout << "e. Multiplication: (C= A * B) \n";
				cout << "f. Transpose of matrix A: (C= A') \n";
				cout << "g. Transpose of matrix B: (C= B') \n";
				cout << "h. Division: (C= A/B) \n";
				cin >> letter_of_operation;

				/*----------SMALL SWITCH CASE TO GIVE YOU THE ANSWER--------*/
				switch (letter_of_operation)
				{
				case'a':
					cout << "Matrix A = " << endl;

					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << matrixA_2D_array[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case 'b':
					cout << "Matrix B = " << endl;

					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << matrixB_2D_array[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case 'c':
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							the_sum[i][j] = matrixA_2D_array[i][j] + matrixB_2D_array[i][j];
						}
					}

					cout << "The sum of matrix A and matrix B =" << endl;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << the_sum[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case'd':
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							the_sub[i][j] = matrixA_2D_array[i][j] - matrixB_2D_array[i][j];
						}
					}
					cout << "The subtraction of matrix A - matrix B =" << endl;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << the_sub[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case'e':
					for (int i = 0; i < 3; i++)
						for (int j = 0; j < 3; j++) {
							for (int u = 0; u < 3; u++)
								multiplication[i][j] += matrixA_2D_array[i][u] * matrixB_2D_array[u][j];
						}
					cout << "The product of matrix A * matrix B =" << endl;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << multiplication[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case'f':
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							transpose_of_matrixA[j][i] = matrixA_2D_array[i][j];
						}

					}
					cout << "The transpose of matrix A =" << endl;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << transpose_of_matrixA[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case'g':
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							transpose_of_matrixB[j][i] = matrixB_2D_array[i][j];
						}

					}
					cout << "The transpose of matrix B =" << endl;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << transpose_of_matrixB[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case'h':
					/*-----------THE DETERMINANT OF MATRIX B----------*/
					det = (double)((matrixB_2D_array[0][0]) * ((matrixB_2D_array[1][1] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][1] * matrixB_2D_array[1][2])))
						+ ((double)((matrixB_2D_array[0][1]) * ((matrixB_2D_array[1][0] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][2])) * (-1.0)))
						+ ((double)((matrixB_2D_array[0][2]) * ((matrixB_2D_array[1][0] * matrixB_2D_array[2][1]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][1]))));
					if (det != 0)
					{
						/*----------THE COFACTORS OF MATRIX B---------*/
						cofactor[0][0] = (((matrixB_2D_array[1][1] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][1] * matrixB_2D_array[1][2])) * (-1));
						cofactor[0][1] = (((matrixB_2D_array[1][0] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][2])) * (-1));
						cofactor[0][1] = ((matrixB_2D_array[1][0] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][2]));
						cofactor[0][2] = (((matrixB_2D_array[1][0] * matrixB_2D_array[2][1]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][1])) * (-1));
						cofactor[1][0] = ((matrixB_2D_array[0][1] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][1] * matrixB_2D_array[0][2]));
						cofactor[1][1] = (((matrixB_2D_array[0][0] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][0] * matrixB_2D_array[0][2])) * (-1));
						cofactor[1][2] = ((matrixB_2D_array[0][0] * matrixB_2D_array[2][1]) - (matrixB_2D_array[2][0] * matrixB_2D_array[0][1]));
						cofactor[2][0] = (((matrixB_2D_array[0][1] * matrixB_2D_array[1][2]) - (matrixB_2D_array[1][1] * matrixB_2D_array[0][2])) * (-1));
						cofactor[2][1] = ((matrixB_2D_array[0][0] * matrixB_2D_array[1][2]) - (matrixB_2D_array[1][0] * matrixB_2D_array[0][2]));
						cofactor[2][2] = (((matrixB_2D_array[0][0] * matrixB_2D_array[1][1]) - (matrixB_2D_array[1][0] * matrixB_2D_array[0][1])) * (-1));

						/*----------FINAL INVERSE FUNCTION----------*/
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								inverse_function[i][j] = cofactor[i][j] * ((1 / det) * (-1));
							}
						}
						// the transpose
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								transpose_to_get_inverse[j][i] = inverse_function[i][j];
							}

						}

						cout << "The result of matrix A/matrix B =\n";
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								division[i][j] = 0;
								for (int k = 0; k < 3; k++)
								{
									division[i][j] += (matrixA_2D_array[i][k] * transpose_to_get_inverse[k][j]);
								}
							}
						}
						//for printing result    
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								cout << division[i][j] << " ";
							}
							cout << "\n";
						}
						cout << "Do you want to do another operation ?\n";
						cout << "If yes type yes \n";
						cout << "If no type no \n";
						cin >> the_second_text;
					}
					else
					{
						cout << "This division can't be done\n";
						cout << "Do you want to do another operation ?\n";
						cout << "If yes type yes \n";
						cout << "If no type no \n";
						cin >> the_second_text;
					}
					break;
				}
			}

			cout << "Do you want to enter another two matrices or exit ?\n";
			cin >> the_first_text;
			cin.ignore();
			cin.clear();
			break;



		case'f':
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					transpose_of_matrixA[j][i] = matrixA_2D_array[i][j];
				}

			}

			cout << "The transpose of matrix A =" << endl;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					cout << transpose_of_matrixA[i][j] << "\t";
				}
				cout << endl;
			}
			/*----------OUTPUT & INPUT WHICH WILL DECIDE THE NEXT STEP----------*/
			cout << "Do you want to choose another operator or no?\n";
			cout << "If yes type yes\n";
			cout << "If no type no\n";
			cin >> the_second_text;

			/*----------SMALL WHILE LOOP TO LET YOU CHOOSE ANOTHER OPERATIONS----------*/
			while (1 && the_second_text != "no")
			{
				/*----------INPUT & OUTPUT TO LET YOU CHOOSE MORE OPERATIONS----------*/
				cout << "Type the letter of any operation \n";
				cout << "a. Show matrix A \n";
				cout << "b. Show matrix B \n";
				cout << "c. Addition: (C= A + B) \n";
				cout << "d. Subtraction: (C= A - B) \n";
				cout << "e. Multiplication: (C= A * B) \n";
				cout << "f. Transpose of matrix A: (C= A') \n";
				cout << "g. Transpose of matrix B: (C= B') \n";
				cout << "h. Division: (C= A/B) \n";
				cin >> letter_of_operation;

				/*----------SMALL SWITCH CASE TO GIVE YOU THE ANSWER--------*/
				switch (letter_of_operation)
				{
				case'a':
					cout << "Matrix A = " << endl;

					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << matrixA_2D_array[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case 'b':
					cout << "Matrix B = " << endl;

					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << matrixB_2D_array[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case 'c':
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							the_sum[i][j] = matrixA_2D_array[i][j] + matrixB_2D_array[i][j];
						}
					}

					cout << "The sum of matrix A and matrix B =" << endl;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << the_sum[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case'd':
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							the_sub[i][j] = matrixA_2D_array[i][j] - matrixB_2D_array[i][j];
						}
					}
					cout << "The subtraction of matrix A - matrix B =" << endl;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << the_sub[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case'e':
					for (int i = 0; i < 3; i++)
						for (int j = 0; j < 3; j++) {
							for (int u = 0; u < 3; u++)
								multiplication[i][j] += matrixA_2D_array[i][u] * matrixB_2D_array[u][j];
						}
					cout << "The product of matrix A * matrix B =" << endl;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << multiplication[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case'f':
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							transpose_of_matrixA[j][i] = matrixA_2D_array[i][j];
						}

					}
					cout << "The transpose of matrix A =" << endl;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << transpose_of_matrixA[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case'g':
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							transpose_of_matrixB[j][i] = matrixB_2D_array[i][j];
						}

					}
					cout << "The transpose of matrix B =" << endl;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << transpose_of_matrixB[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case'h':
					/*-----------THE DETERMINANT OF MATRIX B----------*/
					det = (double)((matrixB_2D_array[0][0]) * ((matrixB_2D_array[1][1] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][1] * matrixB_2D_array[1][2])))
						+ ((double)((matrixB_2D_array[0][1]) * ((matrixB_2D_array[1][0] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][2])) * (-1.0)))
						+ ((double)((matrixB_2D_array[0][2]) * ((matrixB_2D_array[1][0] * matrixB_2D_array[2][1]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][1]))));
					if (det != 0)
					{
						/*----------THE COFACTORS OF MATRIX B---------*/
						cofactor[0][0] = (((matrixB_2D_array[1][1] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][1] * matrixB_2D_array[1][2])) * (-1));
						cofactor[0][1] = (((matrixB_2D_array[1][0] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][2])) * (-1));
						cofactor[0][1] = ((matrixB_2D_array[1][0] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][2]));
						cofactor[0][2] = (((matrixB_2D_array[1][0] * matrixB_2D_array[2][1]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][1])) * (-1));
						cofactor[1][0] = ((matrixB_2D_array[0][1] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][1] * matrixB_2D_array[0][2]));
						cofactor[1][1] = (((matrixB_2D_array[0][0] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][0] * matrixB_2D_array[0][2])) * (-1));
						cofactor[1][2] = ((matrixB_2D_array[0][0] * matrixB_2D_array[2][1]) - (matrixB_2D_array[2][0] * matrixB_2D_array[0][1]));
						cofactor[2][0] = (((matrixB_2D_array[0][1] * matrixB_2D_array[1][2]) - (matrixB_2D_array[1][1] * matrixB_2D_array[0][2])) * (-1));
						cofactor[2][1] = ((matrixB_2D_array[0][0] * matrixB_2D_array[1][2]) - (matrixB_2D_array[1][0] * matrixB_2D_array[0][2]));
						cofactor[2][2] = (((matrixB_2D_array[0][0] * matrixB_2D_array[1][1]) - (matrixB_2D_array[1][0] * matrixB_2D_array[0][1])) * (-1));

						/*----------FINAL INVERSE FUNCTION----------*/
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								inverse_function[i][j] = cofactor[i][j] * ((1 / det) * (-1));
							}
						}
						// the transpose
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								transpose_to_get_inverse[j][i] = inverse_function[i][j];
							}

						}

						cout << "The result of matrix A/matrix B =\n";
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								division[i][j] = 0;
								for (int k = 0; k < 3; k++)
								{
									division[i][j] += (matrixA_2D_array[i][k] * transpose_to_get_inverse[k][j]);
								}
							}
						}
						//for printing result    
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								cout << division[i][j] << " ";
							}
							cout << "\n";
						}
						cout << "Do you want to do another operation ?\n";
						cout << "If yes type yes \n";
						cout << "If no type no \n";
						cin >> the_second_text;
					}
					else
					{
						cout << "This division can't be done\n";
						cout << "Do you want to do another operation ?\n";
						cout << "If yes type yes \n";
						cout << "If no type no \n";
						cin >> the_second_text;
					}
					break;
				}
			}

			cout << "Do you want to enter another two matrices or exit ?\n";
			cin >> the_first_text;
			cin.ignore();
			cin.clear();
			break;


		case'g':

			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					transpose_of_matrixB[j][i] = matrixB_2D_array[i][j];
				}

			}

			cout << "The transpose of matrix B =" << endl;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					cout << transpose_of_matrixB[i][j] << "\t";
				}
				cout << endl;
			}
			/*----------OUTPUT & INPUT WHICH WILL DECIDE THE NEXT STEP----------*/
			cout << "Do you want to choose another operator or no?\n";
			cout << "If yes type yes\n";
			cout << "If no type no\n";
			cin >> the_second_text;

			/*----------SMALL WHILE LOOP TO LET YOU CHOOSE ANOTHER OPERATIONS----------*/
			while (1 && the_second_text != "no")
			{
				/*----------INPUT & OUTPUT TO LET YOU CHOOSE MORE OPERATIONS----------*/
				cout << "Type the letter of any operation \n";
				cout << "a. Show matrix A \n";
				cout << "b. Show matrix B \n";
				cout << "c. Addition: (C= A + B) \n";
				cout << "d. Subtraction: (C= A - B) \n";
				cout << "e. Multiplication: (C= A * B) \n";
				cout << "f. Transpose of matrix A: (C= A') \n";
				cout << "g. Transpose of matrix B: (C= B') \n";
				cout << "h. Division: (C= A/B) \n";
				cin >> letter_of_operation;

				/*----------SMALL SWITCH CASE TO GIVE YOU THE ANSWER--------*/
				switch (letter_of_operation)
				{
				case'a':
					cout << "Matrix A = " << endl;

					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << matrixA_2D_array[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case 'b':
					cout << "Matrix B = " << endl;

					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << matrixB_2D_array[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case 'c':
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							the_sum[i][j] = matrixA_2D_array[i][j] + matrixB_2D_array[i][j];
						}
					}

					cout << "The sum of matrix A and matrix B =" << endl;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << the_sum[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case'd':
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							the_sub[i][j] = matrixA_2D_array[i][j] - matrixB_2D_array[i][j];
						}
					}
					cout << "The subtraction of matrix A - matrix B =" << endl;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << the_sub[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case'e':
					for (int i = 0; i < 3; i++)
						for (int j = 0; j < 3; j++) {
							for (int u = 0; u < 3; u++)
								multiplication[i][j] += matrixA_2D_array[i][u] * matrixB_2D_array[u][j];
						}
					cout << "The product of matrix A * matrix B =" << endl;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << multiplication[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case'f':
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							transpose_of_matrixA[j][i] = matrixA_2D_array[i][j];
						}

					}
					cout << "The transpose of matrix A =" << endl;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << transpose_of_matrixA[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case'g':
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							transpose_of_matrixB[j][i] = matrixB_2D_array[i][j];
						}

					}
					cout << "The transpose of matrix B =" << endl;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << transpose_of_matrixB[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case'h':
					/*-----------THE DETERMINANT OF MATRIX B----------*/
					det = (double)((matrixB_2D_array[0][0]) * ((matrixB_2D_array[1][1] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][1] * matrixB_2D_array[1][2])))
						+ ((double)((matrixB_2D_array[0][1]) * ((matrixB_2D_array[1][0] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][2])) * (-1.0)))
						+ ((double)((matrixB_2D_array[0][2]) * ((matrixB_2D_array[1][0] * matrixB_2D_array[2][1]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][1]))));
					if (det != 0)
					{
						/*----------THE COFACTORS OF MATRIX B---------*/
						cofactor[0][0] = (((matrixB_2D_array[1][1] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][1] * matrixB_2D_array[1][2])) * (-1));
						cofactor[0][1] = (((matrixB_2D_array[1][0] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][2])) * (-1));
						cofactor[0][1] = ((matrixB_2D_array[1][0] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][2]));
						cofactor[0][2] = (((matrixB_2D_array[1][0] * matrixB_2D_array[2][1]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][1])) * (-1));
						cofactor[1][0] = ((matrixB_2D_array[0][1] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][1] * matrixB_2D_array[0][2]));
						cofactor[1][1] = (((matrixB_2D_array[0][0] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][0] * matrixB_2D_array[0][2])) * (-1));
						cofactor[1][2] = ((matrixB_2D_array[0][0] * matrixB_2D_array[2][1]) - (matrixB_2D_array[2][0] * matrixB_2D_array[0][1]));
						cofactor[2][0] = (((matrixB_2D_array[0][1] * matrixB_2D_array[1][2]) - (matrixB_2D_array[1][1] * matrixB_2D_array[0][2])) * (-1));
						cofactor[2][1] = ((matrixB_2D_array[0][0] * matrixB_2D_array[1][2]) - (matrixB_2D_array[1][0] * matrixB_2D_array[0][2]));
						cofactor[2][2] = (((matrixB_2D_array[0][0] * matrixB_2D_array[1][1]) - (matrixB_2D_array[1][0] * matrixB_2D_array[0][1])) * (-1));

						/*----------FINAL INVERSE FUNCTION----------*/
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								inverse_function[i][j] = cofactor[i][j] * ((1 / det) * (-1));
							}
						}
						// the transpose
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								transpose_to_get_inverse[j][i] = inverse_function[i][j];
							}

						}

						cout << "The result of matrix A/matrix B =\n";
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								division[i][j] = 0;
								for (int k = 0; k < 3; k++)
								{
									division[i][j] += (matrixA_2D_array[i][k] * transpose_to_get_inverse[k][j]);
								}
							}
						}
						//for printing result    
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								cout << division[i][j] << " ";
							}
							cout << "\n";
						}
						cout << "Do you want to do another operation ?\n";
						cout << "If yes type yes \n";
						cout << "If no type no \n";
						cin >> the_second_text;
					}
					else
					{
						cout << "This division can't be done\n";
						cout << "Do you want to do another operation ?\n";
						cout << "If yes type yes \n";
						cout << "If no type no \n";
						cin >> the_second_text;
					}

					break;
				}
			}

			cout << "Do you want to enter another two matrices or exit ?\n";
			cin >> the_first_text;
			cin.ignore();
			cin.clear();
			break;



		case'h':

			/*-----------THE DETERMINANT OF MATRIX B----------*/
			det = (double)((matrixB_2D_array[0][0]) * ((matrixB_2D_array[1][1] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][1] * matrixB_2D_array[1][2])))
				+ ((double)((matrixB_2D_array[0][1]) * ((matrixB_2D_array[1][0] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][2])) * (-1.0)))
				+ ((double)((matrixB_2D_array[0][2]) * ((matrixB_2D_array[1][0] * matrixB_2D_array[2][1]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][1]))));
			if (det != 0)
			{
				/*----------THE COFACTORS OF MATRIX B---------*/
				cofactor[0][0] = (((matrixB_2D_array[1][1] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][1] * matrixB_2D_array[1][2])) * (-1));
				cofactor[0][1] = (((matrixB_2D_array[1][0] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][2])) * (-1));
				cofactor[0][1] = ((matrixB_2D_array[1][0] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][2]));
				cofactor[0][2] = (((matrixB_2D_array[1][0] * matrixB_2D_array[2][1]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][1])) * (-1));
				cofactor[1][0] = ((matrixB_2D_array[0][1] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][1] * matrixB_2D_array[0][2]));
				cofactor[1][1] = (((matrixB_2D_array[0][0] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][0] * matrixB_2D_array[0][2])) * (-1));
				cofactor[1][2] = ((matrixB_2D_array[0][0] * matrixB_2D_array[2][1]) - (matrixB_2D_array[2][0] * matrixB_2D_array[0][1]));
				cofactor[2][0] = (((matrixB_2D_array[0][1] * matrixB_2D_array[1][2]) - (matrixB_2D_array[1][1] * matrixB_2D_array[0][2])) * (-1));
				cofactor[2][1] = ((matrixB_2D_array[0][0] * matrixB_2D_array[1][2]) - (matrixB_2D_array[1][0] * matrixB_2D_array[0][2]));
				cofactor[2][2] = (((matrixB_2D_array[0][0] * matrixB_2D_array[1][1]) - (matrixB_2D_array[1][0] * matrixB_2D_array[0][1])) * (-1));

				/*----------FINAL INVERSE FUNCTION----------*/
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						inverse_function[i][j] = cofactor[i][j] * ((1 / det) * (-1));
					}
				}
				// the transpose
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						transpose_to_get_inverse[j][i] = inverse_function[i][j];
					}

				}

				cout << "The result of matrix A/matrix B =\n";
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						division[i][j] = 0;
						for (int k = 0; k < 3; k++)
						{
							division[i][j] += (matrixA_2D_array[i][k] * transpose_to_get_inverse[k][j]);
						}
					}
				}
				//for printing result    
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						cout << division[i][j] << " ";
					}
					cout << "\n";
				}
				cout << "Do you want to do another operation ?\n";
				cout << "If yes type yes \n";
				cout << "If no type no \n";
				cin >> the_second_text;
			}
			else
			{
				cout << "This division can't be done \n";
				cout << "Do you want to do another operation ?\n";
				cout << "If yes type yes \n";
				cout << "If no type no \n";
				cin >> the_second_text;
			}

			/*----------SMALL WHILE LOOP TO LET YOU CHOOSE ANOTHER OPERATIONS----------*/
			while (1 && the_second_text != "no")
			{
				/*----------INPUT & OUTPUT TO LET YOU CHOOSE MORE OPERATIONS----------*/
				cout << "Type the letter of any operation \n";
				cout << "a. Show matrix A \n";
				cout << "b. Show matrix B \n";
				cout << "c. Addition: (C= A + B) \n";
				cout << "d. Subtraction: (C= A - B) \n";
				cout << "e. Multiplication: (C= A * B) \n";
				cout << "f. Transpose of matrix A: (C= A') \n";
				cout << "g. Transpose of matrix B: (C= B') \n";
				cout << "h. Division: (C= A/B) \n";
				cin >> letter_of_operation;

				/*----------SMALL SWITCH CASE TO GIVE YOU THE ANSWER--------*/
				switch (letter_of_operation)
				{
				case'a':
					cout << "Matrix A = " << endl;

					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << matrixA_2D_array[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case 'b':
					cout << "Matrix B = " << endl;

					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << matrixB_2D_array[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case 'c':
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							the_sum[i][j] = matrixA_2D_array[i][j] + matrixB_2D_array[i][j];
						}
					}

					cout << "The sum of matrix A and matrix B =" << endl;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << the_sum[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case'd':
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							the_sub[i][j] = matrixA_2D_array[i][j] - matrixB_2D_array[i][j];
						}
					}
					cout << "The subtraction of matrix A - matrix B =" << endl;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << the_sub[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case'e':
					for (int i = 0; i < 3; i++)
						for (int j = 0; j < 3; j++) {
							for (int u = 0; u < 3; u++)
								multiplication[i][j] += matrixA_2D_array[i][u] * matrixB_2D_array[u][j];
						}
					cout << "The product of matrix A * matrix B =" << endl;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << multiplication[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case'f':
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							transpose_of_matrixA[j][i] = matrixA_2D_array[i][j];
						}

					}
					cout << "The transpose of matrix A =" << endl;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << transpose_of_matrixA[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case'g':
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							transpose_of_matrixB[j][i] = matrixB_2D_array[i][j];
						}

					}
					cout << "The transpose of matrix B =" << endl;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							cout << transpose_of_matrixB[i][j] << "\t";
						}
						cout << endl;
					}
					cout << "Do you want to do another operation ?\n";
					cout << "If yes type yes \n";
					cout << "If no type no \n";
					cin >> the_second_text;
					break;

				case'h':
					/*-----------THE DETERMINANT OF MATRIX B----------*/
					det = (double)((matrixB_2D_array[0][0]) * ((matrixB_2D_array[1][1] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][1] * matrixB_2D_array[1][2])))
						+ ((double)((matrixB_2D_array[0][1]) * ((matrixB_2D_array[1][0] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][2])) * (-1.0)))
						+ ((double)((matrixB_2D_array[0][2]) * ((matrixB_2D_array[1][0] * matrixB_2D_array[2][1]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][1]))));
					if (det != 0)
					{
						/*----------THE COFACTORS OF MATRIX B---------*/
						cofactor[0][0] = (((matrixB_2D_array[1][1] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][1] * matrixB_2D_array[1][2])) * (-1));
						cofactor[0][1] = (((matrixB_2D_array[1][0] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][2])) * (-1));
						cofactor[0][1] = ((matrixB_2D_array[1][0] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][2]));
						cofactor[0][2] = (((matrixB_2D_array[1][0] * matrixB_2D_array[2][1]) - (matrixB_2D_array[2][0] * matrixB_2D_array[1][1])) * (-1));
						cofactor[1][0] = ((matrixB_2D_array[0][1] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][1] * matrixB_2D_array[0][2]));
						cofactor[1][1] = (((matrixB_2D_array[0][0] * matrixB_2D_array[2][2]) - (matrixB_2D_array[2][0] * matrixB_2D_array[0][2])) * (-1));
						cofactor[1][2] = ((matrixB_2D_array[0][0] * matrixB_2D_array[2][1]) - (matrixB_2D_array[2][0] * matrixB_2D_array[0][1]));
						cofactor[2][0] = (((matrixB_2D_array[0][1] * matrixB_2D_array[1][2]) - (matrixB_2D_array[1][1] * matrixB_2D_array[0][2])) * (-1));
						cofactor[2][1] = ((matrixB_2D_array[0][0] * matrixB_2D_array[1][2]) - (matrixB_2D_array[1][0] * matrixB_2D_array[0][2]));
						cofactor[2][2] = (((matrixB_2D_array[0][0] * matrixB_2D_array[1][1]) - (matrixB_2D_array[1][0] * matrixB_2D_array[0][1])) * (-1));

						/*----------FINAL INVERSE FUNCTION----------*/
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								inverse_function[i][j] = cofactor[i][j] * ((1 / det) * (-1));
							}
						}
						// the transpose
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								transpose_to_get_inverse[j][i] = inverse_function[i][j];
							}

						}

						cout << "The result of matrix A/matrix B =\n";
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								division[i][j] = 0;
								for (int k = 0; k < 3; k++)
								{
									division[i][j] += (matrixA_2D_array[i][k] * transpose_to_get_inverse[k][j]);
								}
							}
						}
						//for printing result    
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								cout << division[i][j] << " ";
							}
							cout << "\n";
						}
						cout << "Do you want to do another operation ?\n";
						cout << "If yes type yes \n";
						cout << "If no type no \n";
						cin >> the_second_text;
					}
					else
					{
						cout << "This division can't be done\n";
						cout << "Do you want to do another operation ?\n";
						cout << "If yes type yes \n";
						cout << "If no type no \n";
						cin >> the_second_text;
					}
					break;
				}
			}
			cout << "Do you want to enter another two matrices or exit ?\n";
			cin >> the_first_text;
			cin.ignore();
			cin.clear();

			break;
		}

		counter++;
	}

	return 0;
}

