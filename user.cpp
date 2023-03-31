#include "user.h"


void bookingTickets(concerts*& concert, string& login, tickets*& ticket) {
	string concertID, amount;
	int counter = 0;
	bool flag;
	int NumberOfConcerts = concertData(concert);
	do {
		flag = false;
		while (!flag) {
			cout << "������� ID �����������, ������ �� ������� ������ �������������: ";
			cin >> concertID;
			if ((concertID.size() != 5) || !isIdValid(concertID)) {
				errorMessage();
			}
			else flag = true;
		}
		for (int i = 0; i < NumberOfConcerts; i++) {
			if (concertID == concert[i].id) {
				counter++;
				cout << "��������� ���������� ������� ��� �����: " << concert[i].amount;
				cout << "������� �������� ���������� �������: ";
				cin >> amount;
				flag = false;
				break;
			}
		}
	} while (!flag);
}

void viewAllConcerts(concerts*& concert, string& login, tickets*& ticket) {
	system("cls");
	int numberOfConcerts = concertData(concert);
	char key;

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

		cout << "1. ������������� ������;" << endl << "0. �����";
		do {
			key = _getch();
		} while (key != 48 && key != 49);

		if (key == 49) bookingTickets(concert, login);
	}
}

void searchByName(concerts*& concert) {
	system("cls");
	int numberOfConcerts = concertData(concert);
	int counter = 0;
	char key;
	string name;
	cout << "������� �����������, �������� �������� ������ �����: ";
	cin >> name;

	for (int i = 0; i < numberOfConcerts; i++) {
		if (concert[i].name == name) {
			counter++;
			if (counter == 1) {
				cout << " �����������������������������������������������������������������������������������������\n"
					<< "|    ID    |          ��������         |     ����     | ���� (BYN) |   ����� ����������   |\n"
					<< " �����������������������������������������������������������������������������������������\n";
			}
			cout << "| " << setw(8) << left << concert[i].id << " | "
				<< setw(25) << left << concert[i].name << " | "
				<< setw(12) << left << concert[i].date << " | "
				<< setw(10) << left << concert[i].priceForUnit << " | "
				<< setw(20) << left << concert[i].place << " | " << endl;
			cout << " �����������������������������������������������������������������������������������������\n";
		}
	}
	if (!counter) cout << "������ �� �������!";

	cout << "0. �����";
	do {
		key = _getch();
	} while (key != 48);
}

void searchByPlace(concerts*& concert) {
	system("cls");
	int numberOfConcerts = concertData(concert);
	int counter = 0;
	char key;
	string place;
	cout << "������� �����, �������� � ������� ������ �����: ";
	cin >> place;

	for (int i = 0; i < numberOfConcerts; i++) {
		if (concert[i].place == place) {
			counter++;
			if (counter == 1) {
				cout << " �����������������������������������������������������������������������������������������\n"
					<< "|    ID    |          ��������         |     ����     | ���� (BYN) |   ����� ����������   |\n"
					<< " �����������������������������������������������������������������������������������������\n";
			}
			cout << "| " << setw(8) << left << concert[i].id << " | "
				<< setw(25) << left << concert[i].name << " | "
				<< setw(12) << left << concert[i].date << " | "
				<< setw(10) << left << concert[i].priceForUnit << " | "
				<< setw(20) << left << concert[i].place << " | " << endl;
			cout << " �����������������������������������������������������������������������������������������\n";
		}
	}
	if (!counter) cout << "������ �� �������!";

	cout << "0. �����";
	do {
		key = _getch();
	} while (key != 48);
}

void searchByPrice(concerts*& concert) {
	system("cls");
	int numberOfConcerts = concertData(concert);
	int counter = 0;
	char key;
	bool flag;
	string minPrice, maxPrice;

	do {
		flag = false;
		while (!flag) {
			cout << "������� ����������� �������� ���������: ";
			cin >> minPrice;
			if ((minPrice.size() > 17 || minPrice.size() < 1) || !isIdValid(minPrice)) {
				errorMessage();
				flag = false;
			}
			else flag = true;
		}
	} while (!flag);

	do {
		flag = false;
		while (!flag) {
			cout << "������� ����������� �������� ���������: ";
			cin >> maxPrice;
			if ((maxPrice.size() > 17 || maxPrice.size() < 1) || !isIdValid(maxPrice)) {
				errorMessage();
				flag = false;
			}
			else flag = true;
		}
	} while (!flag);

	for (int i = 0; i < numberOfConcerts; i++) {
		if (concert[i].priceForUnit <= maxPrice && concert[i].priceForUnit >= minPrice) {
			counter++;
			if (counter == 1) {
				cout << " �����������������������������������������������������������������������������������������\n"
					<< "|    ID    |          ��������         |     ����     | ���� (BYN) |   ����� ����������   |\n"
					<< " �����������������������������������������������������������������������������������������\n";
			}
			cout << "| " << setw(8) << left << concert[i].id << " | "
				<< setw(25) << left << concert[i].name << " | "
				<< setw(12) << left << concert[i].date << " | "
				<< setw(10) << left << concert[i].priceForUnit << " | "
				<< setw(20) << left << concert[i].place << " | " << endl;
			cout << " �����������������������������������������������������������������������������������������\n";
		}
	}
	if (!counter) cout << "������ �� �������!";

	cout << "0. �����";
	do {
		key = _getch();
	} while (key != 48);
}

void searchMenu(concerts*& concert) {
	char key;

	do {
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t���������������������������������������\n";
		cout << "\t\t\t\t\t|                                     |\n";
		cout << "\t\t\t\t\t|      ����� �� ������ ���������      |\n";
		cout << "\t\t\t\t\t|                                     |\n";
		cout << "\t\t\t\t\t|   1. �� �����������                 |" << endl
			<< "\t\t\t\t\t|   2. �� ������ ����������           |" << endl
			<< "\t\t\t\t\t|   3. �� �������� ���������          |" << endl
			<< "\t\t\t\t\t|   0. �����                          |" << endl;
		cout << "\t\t\t\t\t|                                     |\n";
		cout << "\t\t\t\t\t���������������������������������������\n\n\n\n\n\n\n\n\n\n\n";

		do {
			key = _getch();
		} while (key != 48 && key != 49 && key != 50 && key != 51);

		if (key == 49) searchByName(concert);
		if (key == 50) searchByPlace(concert);
		if (key == 51) searchByPrice(concert);

	} while (key != 48);
}

void userProfile(users*& user, string& login, tickets*& ticket) {
	system("cls");
	char key;

	do {
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t���������������������������������������\n";
		cout << "\t\t\t\t\t|                                     |\n";
		cout << "\t\t\t\t\t|             ��� �������             |\n";
		cout << "\t\t\t\t\t|                                     |\n";
		cout << "\t\t\t\t\t|   1. ������ ����������              |" << endl
			<< "\t\t\t\t\t|   2. ��������������� ������         |" << endl
			<< "\t\t\t\t\t|   3. �������� ������                |" << endl
			<< "\t\t\t\t\t|   0. �����                          |" << endl;
		cout << "\t\t\t\t\t|                                     |\n";
		cout << "\t\t\t\t\t���������������������������������������\n\n\n\n\n\n\n\n\n\n\n";

		do {
			key = _getch();
		} while (key != 48 && key != 49 && key != 50 && key != 51);

		if (key == 49);
		if (key == 50);
		if (key == 51);

	} while (key != 48);
}

void userMenu(users*& user, concerts*& concert, string& login, tickets*& ticket) {
	system("cls");
	char key;

	do {
	cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t���������������������������������������\n";
	cout << "\t\t\t\t\t|                                     |\n";
	cout << "\t\t\t\t\t|   ������������ ������� �� �������   |\n";
	cout << "\t\t\t\t\t|                                     |\n";
	cout << "\t\t\t\t\t|   1. ����������� ������ ���������   |" << endl
		<< "\t\t\t\t\t|   2. ����� �� ������ ���������      |" << endl
		<< "\t\t\t\t\t|   3. ��� �������                    |" << endl
		<< "\t\t\t\t\t|   0. �����                          |" << endl;
	cout << "\t\t\t\t\t|                                     |\n";
	cout << "\t\t\t\t\t���������������������������������������\n\n\n\n\n\n\n\n\n\n\n";

	do {
		key = _getch();
	} while (key != 48 && key != 49 && key != 50 && key != 51);

	if (key == 49) viewAllConcerts(concert, login, ticket);
	if (key == 50) searchMenu(concert);
	if (key == 51) userProfile(user, login, ticket);

	} while (key != 48);

}