
#include <bitset>
#include <iostream>
#include <windows.h>

using namespace std;

union  IncomprehensibleUnion1 {
	int integerValue;
	char byteArray[sizeof(int)];
};

union IncomprehensibleUnion2 {
	int signedValue;
	unsigned int unsignedValue;
};

union IncomprehensibleUnion3 {
	int integerValue;
	bool byteBits[sizeof(int) * 8];
};


void inputInteger(IncomprehensibleUnion1& i_union) {
	cout << "Введите целое число: ";
	cin >> i_union.integerValue;
}

void viewAllBytes(const IncomprehensibleUnion1& i_union) {
	cout << "Все байты числа: ";
	for (size_t i = 0; i < sizeof(int); ++i) {
		cout << static_cast<int>(i_union.byteArray[i]) << " ";
	}
	cout << endl;
}

void viewSelectedByte(const IncomprehensibleUnion1& i_union, int index) {
	cout << "Выбранный байт числа (индекс " << index << "): " << static_cast<int>(i_union.byteArray[index]) << endl;
}


void viewBytesInBinaryAndHex(const IncomprehensibleUnion1& i_union) {
	cout << "Байты числа в двоичном виде: ";
	for (size_t i = 0; i < sizeof(int); ++i) {
		cout << bitset<8>(i_union.byteArray[i]) << " ";
	}
	cout << endl;

	cout << "Байты числа в шестнадцатеричном виде: ";
	for (size_t i = 0; i < sizeof(int); ++i) {
		cout << hex << static_cast<int>(i_union.byteArray[i]) << " ";
	}
	cout << dec << endl;
}


void inputInteger(IncomprehensibleUnion3& i_union) {
	cout << "Введите целое число: ";
	cin >> i_union.integerValue;
}

int countZeroBytes(const IncomprehensibleUnion3& i_union) {
	int count = 0;
	for (size_t i = 0; i < sizeof(int); ++i)
		if (i_union.byteBits[i] == 0)
			count++;

	return count;
}

void viewByteInfo(const IncomprehensibleUnion3& i_union) {
	for (size_t i = 0; i < sizeof(int); ++i) {
		if (i_union.byteBits[i] == 0)
			cout << "Байт " << i << " - Нулевой" << endl;

		else
			cout << "Байт " << i << " - Ненулевой" << endl;

	}
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	IncomprehensibleUnion1 i_union1;
	// 1 задание
	inputInteger(i_union1);
	viewAllBytes(i_union1);
	viewSelectedByte(i_union1, 2);
	viewBytesInBinaryAndHex(i_union1);

	// 2 задание
	IncomprehensibleUnion2 i_union2;
	i_union2.signedValue = -10;
	cout << "Знаковое значение: " << i_union2.signedValue << endl;
	cout << "Беззнаковое значение: " << i_union2.unsignedValue << endl;


	// 3 задание
	IncomprehensibleUnion3 i_union3;
	inputInteger(i_union3);
	cout << "Количество нулевых байтов: " << countZeroBytes(i_union3) << endl;
	viewByteInfo(i_union3);
}

