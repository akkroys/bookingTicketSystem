#include "user.h"

void personalInformation(users*& user, string& login) {
	system("cls");
	int numberOfUsers = usersData(user);
	char key;
	for (int i = 0; i < numberOfUsers; i++) {
		if (login == user[i].login) {
			cout << " ———————————————————————————————————————————————————————————————————————————————————————————————\n"
				<< "|      Ëîãèí      |      Ôàìèëèÿ      |        Èìÿ        |        Email         | Íîìåð òåëåô. |\n"
				<< " ———————————————————————————————————————————————————————————————————————————————————————————————\n";
			cout << "| " << setw(15) << left << user[i].login << " | "
				<< setw(17) << left << user[i].surname << " | "
				<< setw(17) << left << user[i].name << " | "
				<< setw(20) << left << user[i].email << " | "
				<< setw(12) << left << user[i].phoneNumber << " | " << endl;
			cout << " ———————————————————————————————————————————————————————————————————————————————————————————————\n";
			break;
		}
	}
	cout << "0. Âûõîä";
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

	cout << " —————————————————————————————————————————————————————————————————————————————————————————\n"
		<< "|    ID    |          Íàçâàíèå         |     Äàòà     | Áèëåòû (øò)|   Ãîðîä ïðîâåäåíèÿ   |\n"
		<< " ——————————————————————————————————————————————————————————————————————————————————————————\n";

	for (int i = 0; i < numberOfBookings; i++) {
		if (login == ticket[i].login) {
			for (int j = 0; j < numberOfConcerts; j++) {
				if (ticket[i].concertID == concert[j].id) {
					cout << "| " << setw(8) << left << concert[j].id << " | "
						<< setw(25) << left << concert[j].name << " | "
						<< setw(12) << left << concert[j].date << " | "
						<< setw(10) << left << ticket[i].amount << " | "
						<< setw(20) << left << concert[j].place << " | " << endl;
					cout << " ——————————————————————————————————————————————————————————————————————————————————————————\n";
					break;
				}
			}
		}
	}
	cout << "Ââåäèòå ID êîíöåðòà, áðîíü áèëåòîâ íà êîòîðûé õîòèòå îòìåíèòü: ";
	cin >> ID;
	
	for (int i = 0; i < numberOfBookings; i++) {
		if (login == ticket[i].login) {
			if (ID == ticket[i].concertID) {
				counter++;
				cout << "Ââåäèòå êîëè÷åñòâî áèëåòîâ äëÿ ñíÿòèÿ áðîíè: ";
				do {
					amount = checkInt(amount);
					if (amount > ticket[i].amount || amount <= 0) {
						cout << "Ïðîâåðüòå ïðàâèëüíîñòü ââåäåííûõ äàííûõ!" << endl;
					}
					else flagAmount = true;
				} while (!flagAmount);
				ticket[i].amount -= amount;
				cout << "Áðîíü " << amount << " áèëåòîâ íà êîíöåðò " << ticket[i].concertID << " áûëà îòìåíåíà!" << endl;
				editStrConcert(concert[i].id, concert[i].amount + amount);
			}
		}
	}
	if (!counter) cout << "Êîíöåðòà ñ òàêèì ID íå íàéäåíî!" << endl;
	else {
		cout << "0. Âûõîä";
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
	cout << "Ïîëüçîâàòåëü: " << login << endl;

	cout << " —————————————————————————————————————————————————————————————————————————————————————————\n"
		<< "|    ID    |          Íàçâàíèå         |     Äàòà     | Áèëåòû (øò)|   Ãîðîä ïðîâåäåíèÿ   |\n"
		<< " ——————————————————————————————————————————————————————————————————————————————————————————\n";

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
					cout << " ——————————————————————————————————————————————————————————————————————————————————————————\n";
					break;
				}
			}
		}
	}
	if (!counter) cout << "Çàáðîíèðîâàííûå áèëåòû îòñóòñòâóþò!" << endl;
	else {
		cout << "1. Îòìåíèòü áðîíèðîâàíèå;" << endl;
		cout << "0. Âûõîä";
		do {
			key = _getch();
		} while (key != 48 && key != 49);
		if (key == 49) cancelReservation(concert, login, ticket);
	}
}

void userProfile(users*& user, concerts*& concert, string& login, tickets*& ticket) {
	system("cls");
	char key;

	do {
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t———————————————————————————————————————\n";
		cout << "\t\t\t\t\t|                                     |\n";
		cout << "\t\t\t\t\t|             ÌÎÉ ÏÐÎÔÈËÜ             |\n";
		cout << "\t\t\t\t\t|                                     |\n";
		cout << "\t\t\t\t\t|   1. Ëè÷íàÿ èíôîðìàöèÿ              |" << endl
			<< "\t\t\t\t\t|   2. Çàáðîíèðîâàííûå áèëåòû         |" << endl
			<< "\t\t\t\t\t|   3. Èçìåíèòü ïàðîëü                |" << endl
			<< "\t\t\t\t\t|   0. Âûõîä                          |" << endl;
		cout << "\t\t\t\t\t|                                     |\n";
		cout << "\t\t\t\t\t———————————————————————————————————————\n\n\n\n\n\n\n\n\n\n\n";

		do {
			key = _getch();
		} while (key != 48 && key != 49 && key != 50 && key != 51);

		if (key == 49) personalInformation(user, login);
		if (key == 50) boockedTickets(user, concert, login, ticket);
		if (key == 51) changePassword(user, login);

	} while (key != 48);
}