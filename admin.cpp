#include "admin.h"
#include "validation.h"

string enterId(concerts*& concert) {
	bool flag;
	string id;
	int NumberOfConcerts = concertData(concert);
	do {
		flag = false;
		while (!flag) {
			cout << "Введите ID мероприятия (5 цифр): ";
			cin >> id;
			if ((id.size() != 5) || !isIdValid(id)) {
				errorMessage();
			}
			else flag = true;
		}
		for (int i = 0; i < NumberOfConcerts; i++) {
			if (id == concert[i].id) {
				cout << "Концерт с таким id уже существует Проверьте введенное значение.\n";
				flag = false;
				break;
			}
		}
	} while (!flag);
	return id;
}

string enterConcertName() {
	bool flag;
	string name;

	do {
		flag = false;
		cout << "Введите исполнителя (до 25 символов): ";
		cin >> name;

		if (name.size() > 25 || name.size() < 1) {
			errorMessage();
		}
		else flag = true;
	} while (!flag);

	return name;
}

string enterDate() { //проверка даты обработать
	bool flag;
	string date;

	do {
		flag = false;
		cout << "Введите дату мероприятия (в формате XX/XX/XXXX): ";
		cin >> date;
		flag = true;
		//if (!isDateValid(date)) {
		//	errorMessage();
		//}
		//else flag = true;
	} while (!flag);

	return date;
}

string enterPlace() { //доделать проверку ввода
	bool flag;
	string place;

	do {
		flag = false;
		cout << "Введите город проведения (до 20 символов): ";
		cin >> place;

		if (place.size() > 20 || place.size() < 1) {
			errorMessage();
		}
		else flag = true;
	} while (!flag);

	return place;
}

string enterPrice() {
	bool flag;
	string price;

	do {
		flag = false;
		cout << "Введите стоимость одного билета: ";
		cin >> price;

		if (!isPriceValid(price)) {
			errorMessage();
		}
		else flag = true;
	} while (!flag);

	return price;
}

int enterAmount() {
	bool flag;
	int amount = 0;

	do {
		cout << "Введите доступное для бронирования количество билетов: ";
		amount = checkInt(amount);
		flag = true;
	} while (!flag);

	return amount;
}

void addNewConcert(concerts*& concert) {
	system("cls");
	string id, name, date, priceForUnit, place;
	int amount;

	cout << "Добавление нового концерта: \n";

	id = enterId(concert);
	name = enterConcertName();
	date = enterDate();
	priceForUnit = enterPrice();
	place = enterPlace();
	amount = enterAmount();

	addConcert(id, name, date, priceForUnit, place, amount);
}

void concertCRUD(concerts*& concert) {
	char key;
	do {
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t———————————————————————————————————————\n";
		cout << "\t\t\t\t\t|                                     |\n";
		cout << "\t\t\t\t\t|   РАБОТА С ДАННЫМИ КОНЦЕРТОВ ПО ID  |\n";
		cout << "\t\t\t\t\t|                                     |\n";
		cout << "\t\t\t\t\t|   1. Просмотреть список концертов   |" << endl
			<< "\t\t\t\t\t|   2. Добавить новый концерт         |" << endl
			<< "\t\t\t\t\t|   3. Отредактировать данные         |" << endl
			<< "\t\t\t\t\t|   4. Удалить концерт                |" << endl
			<< "\t\t\t\t\t|   0. Выход                          |" << endl;
		cout << "\t\t\t\t\t|                                     |\n";
		cout << "\t\t\t\t\t———————————————————————————————————————\n\n\n\n\n\n\n\n\n\n\n";
		do {
			key = _getch();
		} while (!(key >= 48 && key <= 52));

		if (key == 49) viewAllConcerts(concert);
		if (key == 50) addNewConcert(concert);
		if (key == 51);
		if (key == 52);

	} while (key != 48);
}

void adminMenu(users*& user, concerts*& concert, string& login) {
	system("cls");
	char key;
	do {
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t———————————————————————————————————————\n";
		cout << "\t\t\t\t\t|                                     |\n";
		cout << "\t\t\t\t\t|          МЕНЮ АДМИНИСТРАТОРА        |\n";
		cout << "\t\t\t\t\t|                                     |\n";
		cout << "\t\t\t\t\t|   1. Работа с данными концертов     |" << endl
			<< "\t\t\t\t\t|   2. База данных пользователей      |" << endl
			<< "\t\t\t\t\t|   3. Пользовательский функционал    |" << endl
			<< "\t\t\t\t\t|   0. Выход                          |" << endl;
		cout << "\t\t\t\t\t|                                     |\n";
		cout << "\t\t\t\t\t———————————————————————————————————————\n\n\n\n\n\n\n\n\n\n\n";
		do {
			key = _getch();
		} while (!(key >= 48 && key <= 51));

		if (key == 49) {
			system("cls");
			concertCRUD(concert);
		}
		if (key == 50);
		if (key == 51) {
			userMenu(user, concert, login);
			system("cls");
		}

	} while (key != 48);
}