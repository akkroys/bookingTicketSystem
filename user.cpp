#include "user.h"


void bookingTickets(concerts*& concert, string& login, tickets*& ticket) {
	string concertID, amount;
	int counter = 0;
	bool flag;
	int NumberOfConcerts = concertData(concert);
	do {
		flag = false;
		while (!flag) {
			cout << "Āāåäčņå ID ģåšīļšč’ņč’, įčėåņū ķą źīņīšīå õīņčņå ēąįšīķčšīāąņü: ";
			cin >> concertID;
			if ((concertID.size() != 5) || !isIdValid(concertID)) {
				errorMessage();
			}
			else flag = true;
		}
		for (int i = 0; i < NumberOfConcerts; i++) {
			if (concertID == concert[i].id) {
				counter++;
				cout << "Äīńņóļķīå źīėč÷åńņāī įčėåņīā äė’ įšīķč: " << concert[i].amount;
				cout << "Āāåäčņå ęåėąåģīå źīėč÷åńņāī įčėåņīā: ";
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

	cout << " \n"
		<< "|    ID    |          Ķąēāąķčå         |     Äąņą     | Öåķą (BYN) |   Ćīšīä ļšīāåäåķč’   |\n"
		<< " \n";

	if (numberOfConcerts <= 0) {
		cout << "Ńļčńīź źīķöåšņīā ļóńņ!" << endl;
		cout << "0. Āūõīä";
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
			cout << " \n";
		}

		cout << "1. Ēąįšīķčšīāąņü įčėåņū;" << endl << "0. Āūõīä";
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
	cout << "Āāåäčņå čńļīėķčņåė’, źīķöåšņū źīņīšīćī õīņčņå ķąéņč: ";
	cin >> name;

	for (int i = 0; i < numberOfConcerts; i++) {
		if (concert[i].name == name) {
			counter++;
			if (counter == 1) {
				cout << " \n"
					<< "|    ID    |          Ķąēāąķčå         |     Äąņą     | Öåķą (BYN) |   Ćīšīä ļšīāåäåķč’   |\n"
					<< " \n";
			}
			cout << "| " << setw(8) << left << concert[i].id << " | "
				<< setw(25) << left << concert[i].name << " | "
				<< setw(12) << left << concert[i].date << " | "
				<< setw(10) << left << concert[i].priceForUnit << " | "
				<< setw(20) << left << concert[i].place << " | " << endl;
			cout << " \n";
		}
	}
	if (!counter) cout << "Ķč÷åćī ķå ķąéäåķī!";

	cout << "0. Āūõīä";
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
	cout << "Āāåäčņå ćīšīä, źīķöåšņū ā źīņīšīģ õīņčņå ķąéņč: ";
	cin >> place;

	for (int i = 0; i < numberOfConcerts; i++) {
		if (concert[i].place == place) {
			counter++;
			if (counter == 1) {
				cout << " \n"
					<< "|    ID    |          Ķąēāąķčå         |     Äąņą     | Öåķą (BYN) |   Ćīšīä ļšīāåäåķč’   |\n"
					<< " \n";
			}
			cout << "| " << setw(8) << left << concert[i].id << " | "
				<< setw(25) << left << concert[i].name << " | "
				<< setw(12) << left << concert[i].date << " | "
				<< setw(10) << left << concert[i].priceForUnit << " | "
				<< setw(20) << left << concert[i].place << " | " << endl;
			cout << " \n";
		}
	}
	if (!counter) cout << "Ķč÷åćī ķå ķąéäåķī!";

	cout << "0. Āūõīä";
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
			cout << "Āāåäčņå ģčķčģąėüķóž ęåėąåģóž ńņīčģīńņü: ";
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
			cout << "Āāåäčņå ģčķčģąėüķóž ęåėąåģóž ńņīčģīńņü: ";
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
				cout << " \n"
					<< "|    ID    |          Ķąēāąķčå         |     Äąņą     | Öåķą (BYN) |   Ćīšīä ļšīāåäåķč’   |\n"
					<< " \n";
			}
			cout << "| " << setw(8) << left << concert[i].id << " | "
				<< setw(25) << left << concert[i].name << " | "
				<< setw(12) << left << concert[i].date << " | "
				<< setw(10) << left << concert[i].priceForUnit << " | "
				<< setw(20) << left << concert[i].place << " | " << endl;
			cout << " \n";
		}
	}
	if (!counter) cout << "Ķč÷åćī ķå ķąéäåķī!";

	cout << "0. Āūõīä";
	do {
		key = _getch();
	} while (key != 48);
}

void searchMenu(concerts*& concert) {
	char key;

	do {
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\n";
		cout << "\t\t\t\t\t|                                     |\n";
		cout << "\t\t\t\t\t|      ĻĪČŃŹ ĻĪ ŃĻČŃŹÓ ŹĪĶÖÅŠŅĪĀ      |\n";
		cout << "\t\t\t\t\t|                                     |\n";
		cout << "\t\t\t\t\t|   1. Ļī čńļīėķčņåėž                 |" << endl
			<< "\t\t\t\t\t|   2. Ļī ćīšīäó ļšīāåäåķč’           |" << endl
			<< "\t\t\t\t\t|   3. Ļī öåķīāīģó äčąļąēīķó          |" << endl
			<< "\t\t\t\t\t|   0. Āūõīä                          |" << endl;
		cout << "\t\t\t\t\t|                                     |\n";
		cout << "\t\t\t\t\t\n\n\n\n\n\n\n\n\n\n\n";

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
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\n";
		cout << "\t\t\t\t\t|                                     |\n";
		cout << "\t\t\t\t\t|             ĢĪÉ ĻŠĪŌČĖÜ             |\n";
		cout << "\t\t\t\t\t|                                     |\n";
		cout << "\t\t\t\t\t|   1. Ėč÷ķą’ čķōīšģąöč’              |" << endl
			<< "\t\t\t\t\t|   2. Ēąįšīķčšīāąķķūå įčėåņū         |" << endl
			<< "\t\t\t\t\t|   3. Čēģåķčņü ļąšīėü                |" << endl
			<< "\t\t\t\t\t|   0. Āūõīä                          |" << endl;
		cout << "\t\t\t\t\t|                                     |\n";
		cout << "\t\t\t\t\t\n\n\n\n\n\n\n\n\n\n\n";

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
	cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\n";
	cout << "\t\t\t\t\t|                                     |\n";
	cout << "\t\t\t\t\t|   ĮŠĪĶČŠĪĀĄĶČÅ ĮČĖÅŅĪĀ ĶĄ ŹĪĶÖÅŠŅ   |\n";
	cout << "\t\t\t\t\t|                                     |\n";
	cout << "\t\t\t\t\t|   1. Ļšīńģīņšåņü ńļčńīź źīķöåšņīā   |" << endl
		<< "\t\t\t\t\t|   2. Ļīčńź ļī ńļčńźó źīķöåšņīā      |" << endl
		<< "\t\t\t\t\t|   3. Ģīé ļšīōčėü                    |" << endl
		<< "\t\t\t\t\t|   0. Āūõīä                          |" << endl;
	cout << "\t\t\t\t\t|                                     |\n";
	cout << "\t\t\t\t\t\n\n\n\n\n\n\n\n\n\n\n";

	do {
		key = _getch();
	} while (key != 48 && key != 49 && key != 50 && key != 51);

	if (key == 49) viewAllConcerts(concert, login, ticket);
	if (key == 50) searchMenu(concert);
	if (key == 51) userProfile(user, login, ticket);

	} while (key != 48);

}