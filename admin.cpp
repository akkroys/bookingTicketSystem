#include "admin.h"
#include "validation.h"

string enterId(concerts*& concert) {
	bool flag;
	string id;
	int NumberOfConcerts = concertData(concert);
	do {
		flag = false;
		while (!flag) {
			cout << "������� ID ����������� (5 ����): ";
			cin >> id;
			if ((id.size() != 5) || !isIdValid(id)) {
				errorMessage();
			}
			else flag = true;
		}
		for (int i = 0; i < NumberOfConcerts; i++) {
			if (id == concert[i].id) {
				cout << "������� � ����� id ��� ���������� ��������� ��������� ��������.\n";
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
		cout << "������� ����������� (�� 25 ��������): ";
		cin >> name;

		if (name.size() > 25 || name.size() < 1) {
			errorMessage();
		}
		else flag = true;
	} while (!flag);

	return name;
}

string enterDate() { //�������� ���� ����������
	bool flag;
	string date;

	do {
		flag = false;
		cout << "������� ���� ����������� (� ������� XX/XX/XXXX): ";
		cin >> date;
		flag = true;
		//if (!isDateValid(date)) {
		//	errorMessage();
		//}
		//else flag = true;
	} while (!flag);

	return date;
}

string enterPlace() { //�������� �������� �����
	bool flag;
	string place;

	do {
		flag = false;
		cout << "������� ����� ���������� (�� 20 ��������): ";
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
		cout << "������� ��������� ������ ������: ";
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
		cout << "������� ��������� ��� ������������ ���������� �������: ";
		amount = checkInt(amount);
		flag = true;
	} while (!flag);

	return amount;
}

void addNewConcert(concerts*& concert) {
	system("cls");
	string id, name, date, priceForUnit, place;
	int amount;

	cout << "���������� ������ ��������: \n";

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
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t���������������������������������������\n";
		cout << "\t\t\t\t\t|                                     |\n";
		cout << "\t\t\t\t\t|   ������ � ������� ��������� �� ID  |\n";
		cout << "\t\t\t\t\t|                                     |\n";
		cout << "\t\t\t\t\t|   1. ����������� ������ ���������   |" << endl
			<< "\t\t\t\t\t|   2. �������� ����� �������         |" << endl
			<< "\t\t\t\t\t|   3. ��������������� ������         |" << endl
			<< "\t\t\t\t\t|   4. ������� �������                |" << endl
			<< "\t\t\t\t\t|   0. �����                          |" << endl;
		cout << "\t\t\t\t\t|                                     |\n";
		cout << "\t\t\t\t\t���������������������������������������\n\n\n\n\n\n\n\n\n\n\n";
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
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t���������������������������������������\n";
		cout << "\t\t\t\t\t|                                     |\n";
		cout << "\t\t\t\t\t|          ���� ��������������        |\n";
		cout << "\t\t\t\t\t|                                     |\n";
		cout << "\t\t\t\t\t|   1. ������ � ������� ���������     |" << endl
			<< "\t\t\t\t\t|   2. ���� ������ �������������      |" << endl
			<< "\t\t\t\t\t|   3. ���������������� ����������    |" << endl
			<< "\t\t\t\t\t|   0. �����                          |" << endl;
		cout << "\t\t\t\t\t|                                     |\n";
		cout << "\t\t\t\t\t���������������������������������������\n\n\n\n\n\n\n\n\n\n\n";
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