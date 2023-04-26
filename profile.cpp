#include "user.h"

void personalInformation(users*& user, string& login) {
	system("cls");
	int numberOfUsers = usersData(user);
	char key;
	for (int i = 0; i < numberOfUsers; i++) {
		if (login == user[i].login) {
			cout << " 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧予n"
				<< "|      ﾋ�肛�      |      ﾔ瑟齏��      |        ﾈ��        |        Email         | ﾍ��褞 �褄襁. |\n"
				<< " 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧予n";
			cout << "| " << setw(15) << left << user[i].login << " | "
				<< setw(17) << left << user[i].surname << " | "
				<< setw(17) << left << user[i].name << " | "
				<< setw(20) << left << user[i].email << " | "
				<< setw(12) << left << user[i].phoneNumber << " | " << endl;
			cout << " 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧予n";
			break;
		}
	}
	cout << "0. ﾂ����";
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

	cout << " 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧予n"
		<< "|    ID    |          ﾍ珸籵�韃         |     ﾄ瑣�     | ﾁ齏褪� (��)|   ﾃ���� ���粢蒟���   |\n"
		<< " 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧\n";

	for (int i = 0; i < numberOfBookings; i++) {
		if (login == ticket[i].login) {
			for (int j = 0; j < numberOfConcerts; j++) {
				if (ticket[i].concertID == concert[j].id) {
					cout << "| " << setw(8) << left << concert[j].id << " | "
						<< setw(25) << left << concert[j].name << " | "
						<< setw(12) << left << concert[j].date << " | "
						<< setw(10) << left << ticket[i].amount << " | "
						<< setw(20) << left << concert[j].place << " | " << endl;
					cout << " 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧\n";
					break;
				}
			}
		}
	}
	cout << "ﾂ粢蒻�� ID ����褞��, 碣��� 礪�褪�� �� ������� ���頸� ���褊頸�: ";
	cin >> ID;
	
	for (int i = 0; i < numberOfBookings; i++) {
		if (login == ticket[i].login) {
			if (ID == ticket[i].concertID) {
				counter++;
				cout << "ﾂ粢蒻�� ���顆褥�粽 礪�褪�� 蓁� ������ 碣���: ";
				do {
					amount = checkInt(amount);
					if (amount > ticket[i].amount || amount <= 0) {
						cout << "ﾏ��粢���� ��珞齏������ 粐裝褊��� 萵����!" << endl;
					}
					else flagAmount = true;
				} while (!flagAmount);
				ticket[i].amount -= amount;
				cout << "ﾁ���� " << amount << " 礪�褪�� �� ����褞� " << ticket[i].concertID << " 磊�� ���褊褊�!" << endl;
				editStrConcert(concert[i].id, concert[i].amount + amount);
			}
		}
	}
	if (!counter) cout << "ﾊ���褞�� � �瑕韲 ID �� �琺蒟��!" << endl;
	else {
		cout << "0. ﾂ����";
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
	cout << "ﾏ���鉋籵�褄�: " << login << endl;

	cout << " 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧予n"
		<< "|    ID    |          ﾍ珸籵�韃         |     ﾄ瑣�     | ﾁ齏褪� (��)|   ﾃ���� ���粢蒟���   |\n"
		<< " 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧\n";

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
					cout << " 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧\n";
					break;
				}
			}
		}
	}
	if (!counter) cout << "ﾇ珮���頏�籵���� 礪�褪� �������糒��!" << endl;
	else {
		cout << "1. ﾎ��褊頸� 碣��頏�籵�韃;" << endl;
		cout << "0. ﾂ����";
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
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧予n";
		cout << "\t\t\t\t\t|                                     |\n";
		cout << "\t\t\t\t\t|             ﾌﾎﾉ ﾏﾐﾎﾔﾈﾋﾜ             |\n";
		cout << "\t\t\t\t\t|                                     |\n";
		cout << "\t\t\t\t\t|   1. ﾋ顆��� 竟����璋��              |" << endl
			<< "\t\t\t\t\t|   2. ﾇ珮���頏�籵���� 礪�褪�         |" << endl
			<< "\t\t\t\t\t|   3. ﾈ銕褊頸� �瑩���                |" << endl
			<< "\t\t\t\t\t|   0. ﾂ����                          |" << endl;
		cout << "\t\t\t\t\t|                                     |\n";
		cout << "\t\t\t\t\t覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧予n\n\n\n\n\n\n\n\n\n\n";

		do {
			key = _getch();
		} while (key != 48 && key != 49 && key != 50 && key != 51);

		if (key == 49) personalInformation(user, login);
		if (key == 50) boockedTickets(user, concert, login, ticket);
		if (key == 51) changePassword(user, login);

	} while (key != 48);
}