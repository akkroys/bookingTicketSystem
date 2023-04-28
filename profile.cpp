#include "user.h"

void personalInformation(users*& user, string& login) {
	system("cls");
	int numberOfUsers = usersData(user);
	char key;
	for (int i = 0; i < numberOfUsers; i++) {
		if (login == user[i].login) {
			cout << " �����������������������������������������������������������������������������������������������\n"
				<< "|      �����      |      �������      |        ���        |        Email         | ����� �����. |\n"
				<< " �����������������������������������������������������������������������������������������������\n";
			cout << "| " << setw(15) << left << user[i].login << " | "
				<< setw(17) << left << user[i].surname << " | "
				<< setw(17) << left << user[i].name << " | "
				<< setw(20) << left << user[i].email << " | "
				<< setw(12) << left << user[i].phoneNumber << " | " << endl;
			cout << " �����������������������������������������������������������������������������������������������\n";
			break;
		}
	}
	cout << "0. �����";
	do {
		key = _getch();
	} while (key != 48);
}

void cancelReservation(concerts*& concert, string& login, tickets*& ticket) {
	system("cls");
	int numberOfBookings = tickectsData(ticket);
	int numberOfConcerts = concertData(concert);
	string ID;
	int counter = 0, amount = 0;
	bool flagAmount = false;
	char key;

	cout << " �����������������������������������������������������������������������������������������\n"
		<< "|    ID    |          ��������         |     ����     | ������ (��)|   ����� ����������   |\n"
		<< " ������������������������������������������������������������������������������������������\n";

	for (int i = 0; i < numberOfBookings; i++) {
		if (login == ticket[i].login) {
			for (int j = 0; j < numberOfConcerts; j++) {
				if (ticket[i].concertID == concert[j].id) {
					cout << "| " << setw(8) << left << concert[j].id << " | "
						<< setw(25) << left << concert[j].name << " | "
						<< setw(12) << left << concert[j].date << " | "
						<< setw(10) << left << ticket[i].amount << " | "
						<< setw(20) << left << concert[j].place << " | " << endl;
					cout << " ������������������������������������������������������������������������������������������\n";
					break;
				}
			}
		}
	}
	cout << "������� ID ��������, ����� ������� �� ������� ������ ��������: ";
	cin >> ID;
	
	for (int i = 0; i < numberOfBookings; i++) {
		if (login == ticket[i].login) {
			if (ID == ticket[i].concertID) {
				counter++;
				cout << "������� ���������� ������� ��� ������ �����: ";
				do {
					amount = checkInt(amount);
					if (amount > ticket[i].amount || amount <= 0) {
						cout << "��������� ������������ ��������� ������!" << endl;
					}
					else flagAmount = true;
				} while (!flagAmount);
				if (ticket[i].amount == amount) {
					for (int j = i; j < numberOfBookings - 1; j++) {
						ticket[j].login = ticket[j + 1].login;
						ticket[j].concertID = ticket[j + 1].concertID;
						ticket[j].amount = ticket[j + 1].amount;
					}
					--numberOfBookings;
					ofstream ticketFile(BOOKING_INFO);
					for (int i = 0; i < numberOfBookings; i++) {
						ticketFile << setw(15) << left << ticket[i].login
							<< setw(8) << left << ticket[i].concertID
							<< setw(8) << left << ticket[i].amount << endl;
					}
					ticketFile.close();
				}
				else {
					ticket[i].amount -= amount;
					rewriteTickets(ticket);
				}
				cout << "����� " << amount << " ������� �� ������� " << ticket[i].concertID << " ���� ��������!" << endl;
				for (int j = 0; j < numberOfConcerts; j++) {
					if (ticket[i].concertID == concert[j].id) {
						editStrConcert(concert[j].id, concert[j].amount + amount);
						break;
					}
				}
			}
		}
	}
	if (!counter) cout << "�������� � ����� ID �� �������!" << endl;
	else {
		cout << "0. �����";
		do {
			key = _getch();
		} while (key != 48);
	}
}

void boockedTickets(users*& user, concerts*& concert, string& login, tickets*& ticket) {
	system("cls");
	int numberOfUsers = usersData(user);
	int numberOfBookings = tickectsData(ticket);
	int numberOfConcerts = concertData(concert);
	int counter = 0;
	char key;
	cout << "������������: " << login << endl;

	cout << " �����������������������������������������������������������������������������������������\n"
		<< "|    ID    |          ��������         |     ����     | ������ (��)|   ����� ����������   |\n"
		<< " ������������������������������������������������������������������������������������������\n";

	for (int i = 0; i < numberOfBookings; i++) {
		if (login == ticket[i].login) {
			counter++;
			for (int j = 0; j < numberOfConcerts; j++) {
				if (ticket[i].concertID == concert[j].id) {
					cout << "| " << setw(8) << left << concert[j].id << " | "
						<< setw(25) << left << concert[j].name << " | "
						<< setw(12) << left << concert[j].date << " | "
						<< setw(10) << left << ticket[i].amount << " | "
						<< setw(20) << left << concert[j].place << " | " << endl;
					cout << " ������������������������������������������������������������������������������������������\n";
					break;
				}
			}
		}
	}
	if (!counter) cout << "��������������� ������ �����������!" << endl;
	else {
		cout << "1. �������� ������������;" << endl;
		cout << "0. �����";
		do {
			key = _getch();
		} while (key != 48 && key != 49);
		if (key == 49) cancelReservation(concert, login, ticket);
	}
}

void userProfile(users*& user, concerts*& concert, string& login, tickets*& ticket) {
	char key;

	do {
		system("cls");
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

		if (key == 49) personalInformation(user, login);
		if (key == 50) boockedTickets(user, concert, login, ticket);
		if (key == 51) changePassword(user, login);

	} while (key != 48);
}