#include <iostream>
#include <fstream> // библиотека, позволяющая работать с классами, взаимодействующими с файлами
// классы  - описание групп объектов, которые содержат поля и методы
#include <string>
using namespace std;

//ofstream - output file stream
//ifstream - input file stream
//fstream - file stream
//Запись слов в файл
bool statistic(string& word) {
	ofstream out;
	out.open("words.txt", ios::app);
	if (out.is_open()) {
		out << word + " " << word.size() << "\n";
		out.close();
		return true;
	}
	out.close();
	return false;
}
// Вывод содержимого файла
void printFile() {
	ifstream in;
	in.open("words.txt");
	if (in.is_open()) {
		char sym;
		while (in.get(sym))
			cout << sym;
	}
	else
		cout << "Ошибка открытия файла.\n";
	in.close();
}
// Очищение файла
void clear() {
	ofstream out;
	out.open("words.txt");
	out.close();
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	/*string path = "file.txt";// путь к файлу

	// Запись в файл - ofstream
	// конструктор класса - метод, который выполняется. когда создаётся 
	ofstream out ; // открываем файл, файл создаётся даже если его нет
	out.open(path, ios::out); // открываем файл

	if (out.is_open()) {
		cout << "Файл открыт для записи.\n";
		string str;
		cout << "Введите строку:\n";
		getline(cin, str);
		out << str + "\n";
		cout << "Запись помещена в файл.\n";
	}
	else
		cout << "Ошибка открытия файла.\n";

	out.close(); // закрываем файл

	// чТЕНИЕ ИЗ ФАЙЛА - ifstream
	ifstream in;
	in.open(path); // открытие существующего файла для чтения

	if (in.is_open()) {
		cout << "Файл открыт для записи.\n";
		string fileStr;
		// Посимвальное считывание
		char sym;
		while (in.get(sym)) 
			fileStr += sym;
		cout << fileStr;
		// Пословное считывание
		while (!in.eof()) {
			string str;
			in >> str;
			if (str != "")
				fileStr += str + "\n";
		}
		// Построчное считывание
		string tmp;
		while (getline(in, tmp))
			fileStr += tmp + "\n";
		cout << fileStr;
	}
	else
		cout << "Ошибка открытия файла.\n";

	in.close();

	if (remove("file.txt"))
		cout << "Файл удалён.\n";
	else
		cout << "Ошибка удаления файла!\n";*/

	// Задача 1
	cout << "Задача 1\n";
	int answer;
	do {
		cout << "Выберите действие:\n";
		cout << "1. Ввод слова;\n";
		cout << "2. Вывод содержимого;\n";
		cout << "3.Очистка файла;\n";
		cout << "4. Завершение работы;\n";
		cout << "Ввод -> ";
		cin >> answer;
		string str;
		switch (answer){
		case 1:
			cin >> str;
			if (statistic(str))
				cout << "Слово записано.\n";
			else
				cout << "Слово не записано";
			break;
		case 2:
			cout << "Содержимое файла:\n";
			printFile();
			break;
		case 3:
			clear();
			cout << "Файл очищен\n";
			break;
		case 4:
			cout << "Завершение работы...\n";
			break;
		default: cout << "";
		}
		system("pause");
		system("cls");
	} while (answer != 4);
	cout << "Прогорамма завешена.\n";

	return 0;
}