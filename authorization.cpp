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
			cout << "Введите логин: \n";
			cout << "От 5 до 15 символов. Буквы латинского алфавита + символы/цифры.\n";
			
			cin >> login;
			if ((login.size() > 15 || login.size() < 5) || !isLoginValid(login)) {
				errorMessage();
				flag = false;
			}
			else flag = true;
		}
		for(int i = 0; i < amountOfUsers; i++) {
			if (login == user[i].login) {
				cout << "Пользователь с таким логином уже существует.\n";
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
			cout << "Введите пароль (от 7 до 20 символов (цифры, символы и буквы латинского алфавита): ";
			password = hiddenPassword();
			if ((password.size() > 15 || password.size() < 7) || !isPasswordValid(password)) {
				errorMessage();
				flag = false;
			}
			else {
				cout << "Введите пароль для подтверждения ещё раз: ";
				passwordConfirm = hiddenPassword();
				if (password != passwordConfirm) {
					cout << "Пароли не совпадают!";
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

string enterSurname() { //сделать проверку на русском
	string surname;
	bool flag;
	do {
		flag = false;
		while (!flag) {
			cout << "Введите фамилию: ";
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

string enterName() { //проверка на русском
	string name;
	bool flag;
	do {
		flag = false;
		while (!flag) {
			cout << "Введите имя: ";
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
			cout << "Введите email в формате email@domainName.com(.ru/.by): ";
			cin >> email;
			if ((email.size() > 20 || email.size() < 1) || !isEmailValid(email)) {
				errorMessage();
				flag = false;
			}
			else flag = true;
		}
		for (int i = 0; i < amountOfUsers; i++) {
			if (email == user[i].email) {
				cout << "Пользователь с таким email'ом уже существует.\n";
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
			cout << "Введите свой номер телефона, содержащий 8029, или 8033 или 8044 + 7 цифр: ";
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

	cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t———————————————————————————————————————\n";
	cout << "\t\t\t\t\t|                                     |\n";
	cout << "\t\t\t\t\t|   Зарегистрироваться в качестве:    |\n";
	cout << "\t\t\t\t\t|                                     |\n";
	cout << "\t\t\t\t\t|   1. администратора                 |" << endl
		<< "\t\t\t\t\t|   2. пользователя                   |" << endl
		<< "\t\t\t\t\t|   0. Выход                          |" << endl;
	cout << "\t\t\t\t\t|                                     |\n";
	cout << "\t\t\t\t\t———————————————————————————————————————\n";

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
	cout << "Аккаунт был успешно создан!";

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
		cout << "Введите логин: ";
		cin >> login;

		for (int i = 0; i < numberOfUsers; i++) {
			if (user[i].login == login) {
				existing++;
				while (!flagPassword) {
					cout << "Введите пароль: ";
					password = hiddenPassword();
					if (user[i].password != md5hash_to_string(MD5(&password[0], password.size()))) {
						cout << "Пароль от учетной записи введен неверно. Попробуйте ещё раз!\n";
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
			cout << "Пользователя с таким логином не существует. Проверьте правильность ввода!\n";
		}
	} while (!flagLogin);
	cout << "Вход выполнен успешно!\n";

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