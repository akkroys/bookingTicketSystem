#include "user.h"


void bookingTickets(concerts*& concert, string& login, tickets*& ticket) {
	string concertID;
	int counter = 0, amount = 0;
	bool flag, flagT = false;
	int numberOfConcerts = concertData(concert);
	do {
		flag = false;
		while (!flag) {
			cout << "\n\nÂâåäèòå ID ìåðîïðèÿòèÿ, áèëåòû íà êîòîðîå õîòèòå çàáðîíèðîâàòü: ";
			cin >> concertID;
			if ((concertID.size() != 5) || !isIdValid(concertID)) {
				errorMessage();
			}
			else flag = true;
		}
		for (int i = 0; i < numberOfConcerts; i++) {
			if (concertID == concert[i].id) {
				counter++;
				cout << "Äîñòóïíîå êîëè÷åñòâî áèëåòîâ äëÿ áðîíè: " << concert[i].amount << endl;
				do {
					cout << "Ââåäèòå æåëàåìîå êîëè÷åñòâî áèëåòîâ: ";
					amount = checkInt(amount);
					if (amount > concert[i].amount || amount <= 0) {
						cout << "Êîëè÷åñòâî çàáðîíèðîâàííûõ áèëåòîâ ìîæåò áûòü îò 1 äî " << concert[i].amount << "!" << endl;
					}
					else flagT = true;
				} while (!flagT);
				addTickets(login, concertID, amount);
				concertData(concert);
				concert[i].amount -= amount;
				//rewriteConcerts(concert);
				break;
			}
		}
		if (counter == 0) cout << "Êîíöåðòà ñ òàêèì ID íåò â àêòóàëüíîì ñïèñêå.\n";
	} while (!flag);
}

void viewAllConcerts(concerts*& concert, string& login, tickets*& ticket) {
	system("cls");
	int numberOfConcerts = concertData(concert);
	char key;

	cout << " —————————————————————————————————————————————————————————————————————————————————————————\n"
		<< "|    ID    |          Íàçâàíèå         |     Äàòà     | Öåíà (BYN) |   Ãîðîä ïðîâåäåíèÿ   |\n"
		<< " —————————————————————————————————————————————————————————————————————————————————————————\n";

	if (numberOfConcerts <= 0) {
		cout << "Ñïèñîê êîíöåðòîâ ïóñò!" << endl;
		cout << "0. Âûõîä";
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
			cout << " —————————————————————————————————————————————————————————————————————————————————————————\n";
		}

		cout << "1. Çàáðîíèðîâàòü áèëåòû;" << endl << "0. Âûõîä";
		do {
			key = _getch();
		} while (key != 48 && key != 49);

		if (key == 49) bookingTickets(concert, login, ticket);
	}
}

void searchByName(concerts*& concert) {
	system("cls");
	int numberOfConcerts = concertData(concert);
	int counter = 0;
	char key;
	string name;
	cout << "Ââåäèòå èñïîëíèòåëÿ, êîíöåðòû êîòîðîãî õîòèòå íàéòè: ";
	cin >> name;

	for (int i = 0; i < numberOfConcerts; i++) {
		if (concert[i].name == name) {
			counter++;
			if (counter == 1) {
				cout << " —————————————————————————————————————————————————————————————————————————————————————————\n"
					<< "|    ID    |          Íàçâàíèå         |     Äàòà     | Öåíà (BYN) |   Ãîðîä ïðîâåäåíèÿ   |\n"
					<< " —————————————————————————————————————————————————————————————————————————————————————————\n";
			}
			cout << "| " << setw(8) << left << concert[i].id << " | "
				<< setw(25) << left << concert[i].name << " | "
				<< setw(12) << left << concert[i].date << " | "
				<< setw(10) << left << concert[i].priceForUnit << " | "
				<< setw(20) << left << concert[i].place << " | " << endl;
			cout << " —————————————————————————————————————————————————————————————————————————————————————————\n";
		}
	}
	if (!counter) cout << "Íè÷åãî íå íàéäåíî!";

	cout << "0. Âûõîä";
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
	cout << "Ââåäèòå ãîðîä, êîíöåðòû â êîòîðîì õîòèòå íàéòè: ";
	cin >> place;

	for (int i = 0; i < numberOfConcerts; i++) {
		if (concert[i].place == place) {
			counter++;
			if (counter == 1) {
				cout << " —————————————————————————————————————————————————————————————————————————————————————————\n"
					<< "|    ID    |          Íàçâàíèå         |     Äàòà     | Öåíà (BYN) |   Ãîðîä ïðîâåäåíèÿ   |\n"
					<< " —————————————————————————————————————————————————————————————————————————————————————————\n";
			}
			cout << "| " << setw(8) << left << concert[i].id << " | "
				<< setw(25) << left << concert[i].name << " | "
				<< setw(12) << left << concert[i].date << " | "
				<< setw(10) << left << concert[i].priceForUnit << " | "
				<< setw(20) << left << concert[i].place << " | " << endl;
			cout << " —————————————————————————————————————————————————————————————————————————————————————————\n";
		}
	}
	if (!counter) cout << "Íè÷åãî íå íàéäåíî!";

	cout << "0. Âûõîä";
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
			cout << "Ââåäèòå ìèíèìàëüíóþ æåëàåìóþ ñòîèìîñòü: ";
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
			cout << "Ââåäèòå ìèíèìàëüíóþ æåëàåìóþ ñòîèìîñòü: ";
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
				cout << " —————————————————————————————————————————————————————————————————————————————————————————\n"
					<< "|    ID    |          Íàçâàíèå         |     Äàòà     | Öåíà (BYN) |   Ãîðîä ïðîâåäåíèÿ   |\n"
					<< " —————————————————————————————————————————————————————————————————————————————————————————\n";
			}
			cout << "| " << setw(8) << left << concert[i].id << " | "
				<< setw(25) << left << concert[i].name << " | "
				<< setw(12) << left << concert[i].date << " | "
				<< setw(10) << left << concert[i].priceForUnit << " | "
				<< setw(20) << left << concert[i].place << " | " << endl;
			cout << " —————————————————————————————————————————————————————————————————————————————————————————\n";
		}
	}
	if (!counter) cout << "Íè÷åãî íå íàéäåíî!";

	cout << "0. Âûõîä";
	do {
		key = _getch();
	} while (key != 48);
}

void searchMenu(concerts*& concert) {
	char key;

	do {
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t———————————————————————————————————————\n";
		cout << "\t\t\t\t\t|                                     |\n";
		cout << "\t\t\t\t\t|      ÏÎÈÑÊ ÏÎ ÑÏÈÑÊÓ ÊÎÍÖÅÐÒÎÂ      |\n";
		cout << "\t\t\t\t\t|                                     |\n";
		cout << "\t\t\t\t\t|   1. Ïî èñïîëíèòåëþ                 |" << endl
			<< "\t\t\t\t\t|   2. Ïî ãîðîäó ïðîâåäåíèÿ           |" << endl
			<< "\t\t\t\t\t|   3. Ïî öåíîâîìó äèàïàçîíó          |" << endl
			<< "\t\t\t\t\t|   0. Âûõîä                          |" << endl;
		cout << "\t\t\t\t\t|                                     |\n";
		cout << "\t\t\t\t\t———————————————————————————————————————\n\n\n\n\n\n\n\n\n\n\n";

		do {
			key = _getch();
		} while (key != 48 && key != 49 && key != 50 && key != 51);

		if (key == 49) searchByName(concert);
		if (key == 50) searchByPlace(concert);
		if (key == 51) searchByPrice(concert);

	} while (key != 48);
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

	cout << "0. Âûõîä";
	do {
		key = _getch();
	} while (key != 48);

	_getch();
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

		if (key == 49);
		if (key == 50) boockedTickets(user, concert, login, ticket);
		if (key == 51);

	} while (key != 48);
}

void userMenu(users*& user, concerts*& concert, string& login, tickets*& ticket) {
	system("cls");
	char key;

	do {
	cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t———————————————————————————————————————\n";
	cout << "\t\t\t\t\t|                                     |\n";
	cout << "\t\t\t\t\t|   ÁÐÎÍÈÐÎÂÀÍÈÅ ÁÈËÅÒÎÂ ÍÀ ÊÎÍÖÅÐÒ   |\n";
	cout << "\t\t\t\t\t|                                     |\n";
	cout << "\t\t\t\t\t|   1. Ïðîñìîòðåòü ñïèñîê êîíöåðòîâ   |" << endl
		<< "\t\t\t\t\t|   2. Ïîèñê ïî ñïèñêó êîíöåðòîâ      |" << endl
		<< "\t\t\t\t\t|   3. Ìîé ïðîôèëü                    |" << endl
		<< "\t\t\t\t\t|   0. Âûõîä                          |" << endl;
	cout << "\t\t\t\t\t|                                     |\n";
	cout << "\t\t\t\t\t———————————————————————————————————————\n\n\n\n\n\n\n\n\n\n\n";

	do {
		key = _getch();
	} while (key != 48 && key != 49 && key != 50 && key != 51);

	if (key == 49) viewAllConcerts(concert, login, ticket);
	if (key == 50) searchMenu(concert);
	if (key == 51) userProfile(user, concert, login, ticket);

	} while (key != 48);

}