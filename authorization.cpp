#include "authorization.h"
#include "validation.h"
#include "files.h"
#include "md5.h"
#include "admin.h"

string enterLogin(users*& user) {
	system("cls");
	string login;
	bool flag;
	int amountOfUsers = usersData(user);
	do {
		flag = false;
		while (!flag) {
			cout << "������� �����: \n";
			cout << "�� 5 �� 15 ��������. ����� ���������� �������� + �������/�����.\n";
			
			cin >> login;
			if ((login.size() > 15 || login.size() < 5) || !isLoginValid(login)) {
				errorMessage();
				flag = false;
			}
			else flag = true;
		}
		for(int i = 0; i < amountOfUsers; i++) {
			if (login == user[i].login) {
				cout << "������������ � ����� ������� ��� ����������.\n";
				flag = false;
				break;
			}
		}
	} while (!flag);
	return login;
}

string enterPassword() {
	string password, passwordConfirm;
	bool flag;
	do {
		flag = false;
		while (!flag) {
			cout << "������� ������ (�� 7 �� 20 �������� (�����, ������� � ����� ���������� ��������): ";
			password = hiddenPassword();
			if ((password.size() > 15 || password.size() < 7) || !isPasswordValid(password)) {
				errorMessage();
				flag = false;
			}
			else {
				cout << "������� ������ ��� ������������� ��� ���: ";
				passwordConfirm = hiddenPassword();
				if (password != passwordConfirm) {
					cout << "������ �� ���������!";
					flag = false;
				}
				else {
					flag = true;
				}
			}
		}
	} while (!flag);
	return password;
}

string enterSurname() { //������� �������� �� �������
	string surname;
	bool flag;
	do {
		flag = false;
		while (!flag) {
			cout << "������� �������: ";
			cin >> surname;
			if ((surname.size() > 17 || surname.size() < 1) || !isNameValid(surname)) {
				errorMessage();
				flag = false;
			}
			else flag = true;
		}
	} while (!flag);
	return surname;
}

string enterName() { //�������� �� �������
	string name;
	bool flag;
	do {
		flag = false;
		while (!flag) {
			cout << "������� ���: ";
			cin >> name;
			if ((name.size() > 17 || name.size() < 1) || !isNameValid(name)) {
				errorMessage();
				flag = false;
			}
			else flag = true;
		}
	} while (!flag);
	return name;
}

string enterEmail(users*& user) {
	string email;
	bool flag;
	int amountOfUsers = usersData(user);
	do {
		flag = false;
		while (!flag) {
			cout << "������� email � ������� email@domainName.com(.ru/.by): ";
			cin >> email;
			if ((email.size() > 20 || email.size() < 1) || !isEmailValid(email)) {
				errorMessage();
				flag = false;
			}
			else flag = true;
		}
		for (int i = 0; i < amountOfUsers; i++) {
			if (email == user[i].email) {
				cout << "������������ � ����� email'�� ��� ����������.\n";
				flag = false;
				break;
			}
		}
	} while (!flag);
	return email;
}

string enterPhone() {
	string phone;
	bool flag;
	do {
		flag = false;
		while (!flag) {
			cout << "������� ���� ����� ��������, ���������� 8029, ��� 8033 ��� 8044 + 7 ����: ";
			cin >> phone;
			if ((phone.size() > 11 || phone.size() < 1) || !isPhoneValid(phone)) {
				errorMessage();
				flag = false;
			}
			else flag = true;
		}
	} while (!flag);
	return phone;
}

void registration(users*& user)
{
	system("cls");
	int key, role;
	string login, surname, name, password, passwordConfirm, email, phoneNumber;

	cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t���������������������������������������\n";
	cout << "\t\t\t\t\t|                                     |\n";
	cout << "\t\t\t\t\t|   ������������������ � ��������:    |\n";
	cout << "\t\t\t\t\t|                                     |\n";
	cout << "\t\t\t\t\t|   1. ��������������                 |" << endl
		<< "\t\t\t\t\t|   2. ������������                   |" << endl
		<< "\t\t\t\t\t|   0. �����                          |" << endl;
	cout << "\t\t\t\t\t|                                     |\n";
	cout << "\t\t\t\t\t���������������������������������������\n";

	do {
		key = _getch();
	} while (key != 48 && key != 49 && key != 50);

	if (key == 49) {
		role = 1;
	}
	else if (key == 50) {
		role = 2;
	}
	else return;

	login = enterLogin(user);
	password = enterPassword();
	surname = enterSurname();
	name = enterName();
	email = enterEmail(user);
	phoneNumber = enterPhone();

	addUser(login, md5hash_to_string(MD5(&password[0], password.size())), surname, name, email, phoneNumber, role);

	system("cls");
	cout << "������� ��� ������� ������!";

	Sleep(1000);
	system("cls");
}

pair <string, int> signIn(users*& user) {
	system("cls");
	string login, password;
	int existing = 0, role;
	bool flagPassword, flagLogin;

	int numberOfUsers = usersData(user);

	do {
		flagLogin = flagPassword = false;
		cout << "������� �����: ";
		cin >> login;

		for (int i = 0; i < numberOfUsers; i++) {
			if (user[i].login == login) {
				existing++;
				while (!flagPassword) {
					cout << "������� ������: ";
					password = hiddenPassword();
					if (user[i].password != md5hash_to_string(MD5(&password[0], password.size()))) {
						cout << "������ �� ������� ������ ������ �������. ���������� ��� ���!\n";
					}
					else {
						role = user[i].role;
						flagPassword = true;
					}
				}
				break;
			}
		}
		if (existing != 0) {
			flagLogin = true;
		}
		else {
			cout << "������������ � ����� ������� �� ����������. ��������� ������������ �����!\n";
		}
	} while (!flagLogin);
	cout << "���� �������� �������!\n";

	Sleep(1000);
	system("cls");

	return make_pair(login, role);
}

void entrance(users* user, concerts*& concert, tickets*& ticket) {
	int role = 0;
	pair<string, int> ret = signIn(user);
	role = ret.second;
	string login = ret.first;
	if (role == 1) {
		adminMenu(user, concert, login, ticket);
		system("cls");
	}
	else if (role == 2) {
		userMenu(user, concert, login, ticket);
	}
}