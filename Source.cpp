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
	cout << "1. ��������" << endl
		<< "2. ���������" << endl
		<< "3. ���������" << endl
		<< "4. �������" << endl
		<< "5. ������� �� �������" << endl
		<< "6. ���������" << endl;
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
			cout << "������" << endl;
		else if (A > B)
			cout << "������" << endl;
		else if (A == B)
			cout << "�����" << endl;
		break;
	}
	return 0;
}