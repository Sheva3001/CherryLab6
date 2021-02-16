#include "MyList.h"
#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int com = -1;
	Array<int> A;
	A.assign();
	Array<int> B;
	B.assign();
	Array<int> C;
	cout << "1. Сложение" << endl
		<< "2. Вычитание" << endl
		<< "3. Умножение" << endl
		<< "4. Деление" << endl
		<< "5. Остаток от деления" << endl
		<< "6. Сравнение" << endl;
	cin >> com;
	switch (com)
	{
	case 1:
		C = A + B;
		C.print();
		break;
	case 2:
		C = A - B;
		C.print();
		break;
	case 3:
		C = A * B;
		C.print();
		break;
	case 4:
		C = A / B;
		C.print();
		break;
	case 5:
		C = A % B;
		C.print();
		break;
	case 6:
		if (A < B)
			cout << "Меньше" << endl;
		else if (A > B)
			cout << "Больше" << endl;
		else if (A == B)
			cout << "Равны" << endl;
		break;
	}
	return 0;
}