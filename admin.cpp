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
		cout << "������� ����������� (�� 25 �������� ����� ������): ";
		cin >> name;

		if (name.size() > 25 || name.size() < 1) {
			errorMessage();
		}
		else flag = true;
	} while (!flag);

	return name;
}

string enterDate() {
	bool flag;
	string date;
	int counter = 0;

	do {
		counter = 0;
		flag = false;
		cout << "������� ���� ����������� (� ������� ����/��/��): ";
		cin >> date;
		if (!isDateValid(date)) {
			counter++;
			if(counter == 1)
			errorMessage();
		}
		else flag = true;
	} while (!flag);

	return date;
}

string enterPlace() {
	bool flag;
	string place;

	do {
		flag = false;
		cout << "������� ����� ���������� (�� 20 ��������): ";
		place = containsOnlyLetters(place);

		if (place.size() > 20 || place.size() < 1) {
			errorMessage();
		}
		else flag = true;
	} while (!flag);

	place = fixFirstLetter(place);
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

void deleteAConcert(concerts*& concert) {
	system("cls");
	int numberOfConcerts = concertData(concert);
	char key;
	string id;
	int counter = 0;

	cout << " �����������������������������������������������������������������������������������������\n"
		<< "|    ID    |          ��������         |     ����     | ���� (BYN) |   ����� ����������   |\n"
		<< " �����������������������������������������������������������������������������������������\n";
	if (numberOfConcerts <= 0) {
		cout << "������ ��������� ����!" << endl;
		cout << "0. �����";
		do {
			key = _getch();
		} while (key != 48);
		system("cls");
	}
	else {
		for (int i = 0; i < numberOfConcerts; i++) {
			cout << "| " << setw(8) << left << concert[i].id << " | "
				<< setw(25) << left << concert[i].name << " | "
				<< setw(12) << left << concert[i].date << " | "
				<< setw(10) << left << concert[i].priceForUnit << " | "
				<< setw(20) << left << concert[i].place << " | " << endl;
			cout << " �����������������������������������������������������������������������������������������\n";
		}
		cout << "������� ID ��������, ������� ������ �������: ";
		cin >> id;
		int indexToRemove = -1;
		for (int i = 0; i < numberOfConcerts; i++) {
			if (id == concert[i].id) {
				counter++;
				indexToRemove = i;
				}
			}
		if (!counter) cout << "�������� � ����� ID �� �������!" << endl;
		for (int j = indexToRemove; j < numberOfConcerts - 1; j++) {
			concert[j].id = concert[j + 1].id;
			concert[j].name = concert[j + 1].name;
			concert[j].date = concert[j + 1].date;
			concert[j].priceForUnit = concert[j + 1].priceForUnit;
			concert[j].place = concert[j + 1].place;
			concert[j].amount = concert[j + 1].amount;
		}
		--numberOfConcerts;
		cout << "������� ��� ������!" << endl;
		ofstream concertsFile(CONCERTS_INFO);

		for (int i = 0; i < numberOfConcerts; i++) {
			concertsFile << setw(8) << left << concert[i].id
				<< setw(25) << left << concert[i].name
				<< setw(12) << left << concert[i].date
				<< setw(10) << left << concert[i].priceForUnit
				<< setw(20) << left << concert[i].place
				<< setw(8) << left << concert[i].amount << endl;
		}
		concertsFile.close();
		//rewriteConcerts(concert);
		cout << "0. �����";
		do {
			key = _getch();
		} while (key != 48);
		system("cls");

	}
}

void concertCRUD(concerts*& concert, string& login, tickets*& ticket) {
	char key;
	do {
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t���������������������������������������\n";
		cout << "\t\t\t\t\t|                                     |\n";
		cout << "\t\t\t\t\t|   ������ � ������� ��������� �� ID  |\n";
		cout << "\t\t\t\t\t|                                     |\n";
		cout << "\t\t\t\t\t|   1. ����������� ������ ���������   |" << endl
			<< "\t\t\t\t\t|   2. �������� ����� �������         |" << endl
			<< "\t\t\t\t\t|   3. ������� �������                |" << endl
			<< "\t\t\t\t\t|   0. �����                          |" << endl;
		cout << "\t\t\t\t\t|                                     |\n";
		cout << "\t\t\t\t\t���������������������������������������\n\n\n\n\n\n\n\n\n\n\n";
		do {
			key = _getch();
		} while (!(key >= 48 && key <= 52));

		if (key == 49) viewAllConcerts(concert, login, ticket);
		if (key == 50) addNewConcert(concert);
		if (key == 51) deleteAConcert(concert);

	} while (key != 48);
}

void usersDatabase(users*& user, concerts*& concert, tickets*& ticket) {
	char key;
	int numberOfUsers = usersData(user);
	int numberOfBookings = tickectsData(ticket);
	int numberOfConcerts = concertData(concert);

	cout << " �������������������������������������������������������������������������������������������������������������������\n"
		<< "|      �����      |      �������      |        ���        |        Email         | ����� �����. | ID ����.|  ������  |\n"
		<< " �������������������������������������������������������������������������������������������������������������������\n";
	for (int i = 0; i < numberOfUsers; i++) {
		if (user[i].role == 2) { // +  || user[i].role == 1 ?
			for (int j = 0; j < numberOfBookings; j++) {
				if (user[i].login == ticket[j].login) {
					cout << "| " << setw(15) << left << user[i].login << " | "
						<< setw(17) << left << user[i].surname << " | "
						<< setw(17) << left << user[i].name << " | "
						<< setw(20) << left << user[i].email << " | "
						<< setw(12) << left << user[i].phoneNumber << " | "
						<< setw(7) << left << ticket[j].concertID << " | " 
						<< setw(7) << left << ticket[j].amount << " | " << endl;
					cout << " �������������������������������������������������������������������������������������������������������������������\n";
				}
			}
		}
	}
	cout << "0. �����";
	do {
		key = _getch();
	} while (key != 48);
}

void adminMenu(users*& user, concerts*& concert, string& login, tickets*& ticket) {
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
			concertCRUD(concert, login, ticket);
		}
		if (key == 50) {
			system("cls");
			usersDatabase(user, concert, ticket);
		}
		if (key == 51) {
			userMenu(user, concert, login, ticket);
			system("cls");
		}

	} while (key != 48);
}