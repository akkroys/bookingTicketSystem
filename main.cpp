#include "admin.h"

int main() {
	
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	users* user{};
	concerts* concert;
	tickets* ticket;
	char key;
	do {
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t———————————————————————————————————————\n";
		cout << "\t\t\t\t\t|                                     |\n";
		cout << "\t\t\t\t\t|   БРОНИРОВАНИЕ БИЛЕТОВ НА КОНЦЕРТ   |\n";
		cout << "\t\t\t\t\t|                                     |\n";
		cout << "\t\t\t\t\t|   1. Регистрация                    |" << endl
			<< "\t\t\t\t\t|   2. Авторизация                    |" << endl
			<< "\t\t\t\t\t|   0. Выход                          |" << endl;
		cout << "\t\t\t\t\t|                                     |\n";
		cout << "\t\t\t\t\t———————————————————————————————————————\n\n\n\n\n\n\n\n\n\n\n\n";
		do {
			key = _getch();
		} while (key != 48 && key != 49 && key != 50);

		if (key == 49) registration(user);
		if (key == 50) entrance(user, concert, ticket);
	} while (key != 48);
}