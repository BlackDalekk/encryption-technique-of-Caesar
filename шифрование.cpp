#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <ios>
using namespace std;

int isStr(char str_[]) {
	string str = string(str_); //переводим в string чтобы выполнять функции size()
	int l = str.size();        //размер строки
	if (l == 0 || l > 200) {   //если размер = 0 или больше 200 то false
		return 0;
	}
	for (int i = 0; i < l; ++i) {
		if ((str_[i] < 'A') || (str_[i] > 'Z' && str_[i] < 'a') || (str_[i] > 'z'))  //если до A ,между Z и a , или после А , то 0
			return 0;
	}
	return 1;
}

int isKey(int key) {
	string key_ = to_string(key);
	if (key < 1 || key > 25)    //key не должен быть больше 25 потому что в английском алфавите 26 букв
		return 0;
	return 1;
}

char encryption_smoll(char ch, int key) {
	if (ch == ' ')
		return ch;
	if ((ch + key) > 90 && (ch + key) < 97 || (ch + key) > 122)
		ch -= 26;
	return ch += key;
}

char deciphermen_smoll(char ch, int key) {
	if (ch == ' ')
		return ch;
	if ((ch - key) < 65 || (ch - key) > 90 && (ch - key) < 97)
		ch += 26;
	return ch -= key;
}

void encryption() {
	int key;                      //ключ
	int c = 0;                    //счетчик символов
	char str[200];                //исходная строка
	char str_[200];               //конечная (закодированая) строка
	memset(str_, 0, 200);         //обнуляем строку

	cout << "Шифрование методом Цезаря\n"
		<< "Сначала введите стоку на английском. Строка не должна быть больше 200 символов!\n"
		<< "Затем введите ключ. Ключ - только целое число от 1 до 25!\n";
	cout << "Введите строку: ";
	cin.getline(str, 200);
	cout << "Введие ключ: ";
	cin >> key;

	while (static_cast<int>(str[c] >= 65) && static_cast<int>(str[c]) <= 90 ||
		static_cast<int>(str[c]) >= 97 && static_cast<int>(str[c]) <= 122 || str[c] == ' ')
		c++;
	
	for (int i = 0; i < c; ++i)
		str_[i] = encryption_smoll(str[i], key);

	cout << str_ << endl << endl;
	
}

void deciphermen() {
	int key;
	int c = 0;
	char str[200];
	char str_[200];
	memset(str_, 0, 200);

	cout << "Введите закодированную строку: ";
	cin.getline(str, 200);
	cout << "Введите ключ: ";
	cin >> key;

	while (static_cast<int>(str[c]) >= 65 && static_cast<int>(str[c]) <= 90
		|| static_cast<int>(str[c]) >= 97 && static_cast<int>(str[c]) <= 122
		|| str[c] == ' ')
		c++;

	for (int i = 0; i < c; ++i)
		str_[i] = deciphermen_smoll(str[i], key);

	cout << str_ << endl << endl;
}


int main(void)
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251 >> null");

	char ch;
	char ch1;
	do {
		cout << "Закодировать(1)\nРаскодировать(2)\nВыход(3): "; cin >> ch1;
		if (ch1 == '1') {
			cin.ignore(10, '\n');
			encryption();
		}
		else if (ch1 == '2') {
			cin.ignore(10, '\n');
			deciphermen();
		}
		else if (ch1 == '3') {
			_exit(0);
		}
		else
			cout << "Ошибка ввода!\n";
	} while (1);

}
