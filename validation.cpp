#include "validation.h"

extern void errorMessage() {
    cout << "”бедитесь, что введенные вами данные соответствуют требовани€м, и попробуйте ещЄ раз!\n";
}

bool isRussianCapitalLetter(char letter) {
    return (letter >= 'ј' && letter <= 'я');
}

string fixFirstLetter(string input) {
    if (input.empty()) {
        return input;
    }

    if (!isRussianCapitalLetter(input[0])) {
        input[0] = toupper(input[0]);
    }

    return input;
}

bool isLoginValid(string& login) {
    regex statement("^[a-zA-Z0-9(_)?]+$");
    bool check = regex_match(login, statement);
    return check;
}

bool isNameValid(string& name) {
    regex statement("[a-zA-Z]");
    bool check = regex_match(name, statement);
    check = true;
    return check;
}

bool isEmailValid(string& email) {
    string sub_statement = "[0-9a-zA-Z._]+";
    regex statement(sub_statement + "[@]" + sub_statement + "((.com)|(.ru)|(.by))");
    bool check = regex_match(email, statement);
    return check;
}

bool isPhoneValid(string& phone) {
    regex statement("((8029)|(8033)|(8044))[0-9]{7}");
    bool check = regex_match(phone, statement);
    return check;
}

bool isIdValid(string& id) {
    regex statement("[0-9]+");
    bool check = regex_match(id, statement);
    return check;
}

int checkInt(int a) {
    while (true) {
        cin >> a;
        if (cin.fail()) {
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            errorMessage();
            continue;
        }
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        if (cin.gcount() > 1) {
            errorMessage();
            continue;
        }
        break;
    }
    return a;
}

string containsOnlyLetters(string str) {
    while (true) {
        cin >> str;
        if (str.find_first_not_of("абвгдеЄжзийклмнопрстуфхцчшщъыьэю€јЅ¬√ƒ≈®∆«»… ЋћЌќѕ–—“”‘’÷„ЎўЏџ№Ёёя-") ==
            string::npos) {
            break;
        }
        else {
            errorMessage();
            continue;
        }
    }
    return str;
}

bool isDateValid(string& date) {
    regex statement{ R"((19|20)\d\d[- /.](0[1-9]|1[012])[- /.](0[1-9]|[12][0-9]|3[01]))" };
    bool check = regex_match(date, statement);
    return check;
}

bool isPriceValid(string& price) {
    regex statement("([0-9]*[.])?[0-9]+");
    bool check = regex_match(price, statement);
    return check;
}

bool isPasswordValid(string& password) {
    regex statement{R"(^(?=.*\d)(?=.*[a-z])(?=.*[A-Z])[a-zA-Z\d\S]{7,20}$)"};
    bool check = regex_match(password, statement);
    return check;
}

string hiddenPassword() {
    char c;
    string password = "";
    while (true) {
        c = _getch();
        if (c == 13) {
            break;
        }
        else if (c == 8 && password.size()) {
            password.pop_back();
            wcout << '\b' << ' ' << '\b';
        }
        else if (c != 8) {
            cout << '*';
            password.push_back(c);
        }
    }
    cout << '\n';
    return password;
}