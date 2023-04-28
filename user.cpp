#include "user.h"


void bookingTickets(concerts*& concert, string& login, tickets*& ticket) {
	string concertID;
	int counter = 0, amount = 0;
	bool flag, flagT = false;
	char key;
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
						cout << "Ââåäåííîå êîëè÷åñòâî áèëåòîâ íå ìîæåò áûòü çàáðîíèðîâàíî!" << endl;
						cout << "0. Âûõîä";
						do {
							key = _getch();
						} while (key != 48);
						return;
					}
					else flagT = true;
				} while (!flagT);
				addTickets(login, concertID, amount);
				concert[i].amount -= amount;
				rewriteConcerts(concert);
				break;
			}
		}
		if (counter == 0) cout << "Êîíöåðòà ñ òàêèì ID íåò â àêòóàëüíîì ñïèñêå.\n";
	} while (!flag);
}

string currentDateTime() {
	time_t now = time(nullptr);

	tm localtime;
	localtime_s(&localtime, &now);

	stringstream ss;
	ss << put_time(&localtime, "%Y/%m/%d");

	return ss.str();
}

void currentList(concerts*& concert, string& login, tickets*& ticket) {
	system("cls");
	string currDate = currentDateTime();
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
			if (concert[i].date >= currDate) {
				if (concert[i].amount != 0) {
					cout << "| " << setw(8) << left << concert[i].id << " | "
						<< setw(25) << left << concert[i].name << " | "
						<< setw(12) << left << concert[i].date << " | "
						<< setw(10) << left << concert[i].priceForUnit << " | "
						<< setw(20) << left << concert[i].place << " | " << endl;
					cout << " —————————————————————————————————————————————————————————————————————————————————————————\n";
				}
			}
		}

		cout << "1. Çàáðîíèðîâàòü áèëåòû;" << endl
			<< "0. Âûõîä";
		do {
			key = _getch();
		} while (key != 48 && key != 49 && key != 50);

		if (key == 49) bookingTickets(concert, login, ticket);
	}
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

			cout << "1. Ïðîñìîòðåòü ñïèñîê àêòóàëüíûõ êîíöåðòîâ;" << endl
			<< "0. Âûõîä";
		do {
			key = _getch();
		} while (key != 48 && key != 49 && key != 50);

		if (key == 49) currentList(concert, login, ticket);
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

double string_to_double(const string& s)
{
	istringstream i(s);
	double x;
	if (!(i >> x))
		return 0;
	return x;
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
			cout << "Ââåäèòå ìàêñèìàëüíóþ æåëàåìóþ ñòîèìîñòü: ";
			cin >> maxPrice;
			if ((maxPrice.size() > 17 || maxPrice.size() < 1) || !isIdValid(maxPrice)) {
				errorMessage();
				flag = false;
			}
			else flag = true;
		}
	} while (!flag);

	for (int i = 0; i < numberOfConcerts; i++) {
		if (string_to_double(concert[i].priceForUnit) <= string_to_double(maxPrice) 
			&& string_to_double(concert[i].priceForUnit) >= string_to_double(minPrice)) {
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
	if (!counter) cout << "Íè÷åãî íå íàéäåíî!" << endl;

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

void sortByPrice(concerts*& concert) {
	system("cls");
	int numberOfConcerts = concertData(concert);
	char key;
	string temp;
	concerts* temporary = new concerts[numberOfConcerts];
	for (int i = 0; i < numberOfConcerts; i++) {
		temporary[i] = concert[i];
	}
	cout << " —————————————————————————————————————————————————————————————————————————————————————————\n"
		<< "|    ID    |          Íàçâàíèå         |     Äàòà     | Öåíà (BYN) |   Ãîðîä ïðîâåäåíèÿ   |\n"
		<< " —————————————————————————————————————————————————————————————————————————————————————————\n";
	for (int i = 0; i < numberOfConcerts; i++) {
		int j = i;
		while (j > 0 && string_to_double(temporary[j].priceForUnit) < string_to_double(temporary[j - 1].priceForUnit)) {
			swap(temporary[j], temporary[j - 1]);
			j--;
		}
	}
	for (int i = 0; i < numberOfConcerts; i++) {
		cout << "| " << setw(8) << left << temporary[i].id << " | "
			<< setw(25) << left << temporary[i].name << " | "
			<< setw(12) << left << temporary[i].date << " | "
			<< setw(10) << left << temporary[i].priceForUnit << " | "
			<< setw(20) << left << temporary[i].place << " | " << endl;
		cout << " —————————————————————————————————————————————————————————————————————————————————————————\n";
	}
	cout << "0. Âûõîä";
	do {
		key = _getch();
	} while (key != 48);
}

void sortByAlphabet(concerts*& concert) {
	system("cls");
	int numberOfConcerts = concertData(concert);
	char key;
	string temp;
	concerts* temporary = new concerts[numberOfConcerts];
	for (int i = 0; i < numberOfConcerts; i++) {
		temporary[i] = concert[i];
	}
	cout << " —————————————————————————————————————————————————————————————————————————————————————————\n"
		<< "|    ID    |          Íàçâàíèå         |     Äàòà     | Öåíà (BYN) |   Ãîðîä ïðîâåäåíèÿ   |\n"
		<< " —————————————————————————————————————————————————————————————————————————————————————————\n";
	for (int i = 0; i < numberOfConcerts; i++) {
		int j = i;
		while (j > 0 && temporary[j].name < temporary[j - 1].name) {
			swap(temporary[j], temporary[j - 1]);
			j--;
		}
	}
	for (int i = 0; i < numberOfConcerts; i++) {
		cout << "| " << setw(8) << left << temporary[i].id << " | "
			<< setw(25) << left << temporary[i].name << " | "
			<< setw(12) << left << temporary[i].date << " | "
			<< setw(10) << left << temporary[i].priceForUnit << " | "
			<< setw(20) << left << temporary[i].place << " | " << endl;
		cout << " —————————————————————————————————————————————————————————————————————————————————————————\n";
	}
	cout << "0. Âûõîä";
	do {
		key = _getch();
	} while (key != 48);
}

void sortByDate(concerts*& concert) {
	system("cls");
	int numberOfConcerts = concertData(concert);
	char key;
	string temp;
	concerts* temporary = new concerts[numberOfConcerts];
	for (int i = 0; i < numberOfConcerts; i++) {
		temporary[i] = concert[i];
	}
	cout << " —————————————————————————————————————————————————————————————————————————————————————————\n"
		<< "|    ID    |          Íàçâàíèå         |     Äàòà     | Öåíà (BYN) |   Ãîðîä ïðîâåäåíèÿ   |\n"
		<< " —————————————————————————————————————————————————————————————————————————————————————————\n";
	for (int i = 0; i < numberOfConcerts; i++) {
		int j = i;
		while (j > 0 && temporary[j].date < temporary[j - 1].date) {
			swap(temporary[j], temporary[j - 1]);
			j--;
		}
	}
	for (int i = 0; i < numberOfConcerts; i++) {
		cout << "| " << setw(8) << left << temporary[i].id << " | "
			<< setw(25) << left << temporary[i].name << " | "
			<< setw(12) << left << temporary[i].date << " | "
			<< setw(10) << left << temporary[i].priceForUnit << " | "
			<< setw(20) << left << temporary[i].place << " | " << endl;
		cout << " —————————————————————————————————————————————————————————————————————————————————————————\n";
	}
	cout << "0. Âûõîä";
	do {
		key = _getch();
	} while (key != 48);
}

void sortMenu(concerts*& concert) {
	char key;

	do {
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t———————————————————————————————————————\n";
		cout << "\t\t\t\t\t|                                     |\n";
		cout << "\t\t\t\t\t|             ÑÎÐÒÈÐÎÂÊÀ              |\n";
		cout << "\t\t\t\t\t|                                     |\n";
		cout << "\t\t\t\t\t|   1. Â àëôàâèòíîì ïîðÿäêå           |" << endl
			<< "\t\t\t\t\t|   2. Ïî äàòå ïðîâåäåíèÿ             |" << endl
			<< "\t\t\t\t\t|   3. Ïî öåíå                        |" << endl
			<< "\t\t\t\t\t|   0. Âûõîä                          |" << endl;
		cout << "\t\t\t\t\t|                                     |\n";
		cout << "\t\t\t\t\t———————————————————————————————————————\n\n\n\n\n\n\n\n\n\n\n";

		do {
			key = _getch();
		} while (key != 48 && key != 49 && key != 50 && key!= 51);

		if (key == 49) sortByAlphabet(concert);
		if (key == 50) sortByDate(concert);
		if (key == 51) sortByPrice(concert);

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
		<< "\t\t\t\t\t|   3. Ñîðòèðîâêà ñïèñêà êîíöåðòîâ    |" << endl
		<< "\t\t\t\t\t|   4. Ìîé ïðîôèëü                    |" << endl
		<< "\t\t\t\t\t|   0. Âûõîä                          |" << endl;
	cout << "\t\t\t\t\t|                                     |\n";
	cout << "\t\t\t\t\t———————————————————————————————————————\n\n\n\n\n\n\n\n\n\n\n";

	do {
		key = _getch();
	} while (key != 48 && key != 49 && key != 50 && key != 51 && key!= 52);

	if (key == 49) viewAllConcerts(concert, login, ticket);
	if (key == 50) searchMenu(concert);
	if (key == 51) sortMenu(concert);
	if (key == 52) userProfile(user, concert, login, ticket);

	} while (key != 48);

}