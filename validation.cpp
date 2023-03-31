#include "validation.h"

extern void errorMessage() {
    cout << "Убедитесь, что введенные вами данные соответствуют требованиям, и попробуйте ещё раз!\n";
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

bool isDateValid(string& date) {
    regex statement("/(?:(?:31(\/|-|\.)(?:0?[13578]|1[02]))\1|(?:(?:29|30)(\/|-|\.)(?:0?[13-9]|1[0-2])\2))(?:(?:1[6-9]|[2-9]\d)?\d{2})$|^(?:29(\/|-|\.)0?2\3(?:(?:(?:1[6-9]|[2-9]\d)?(?:0[48]|[2468][048]|[13579][26])|(?:(?:16|[2468][048]|[3579][26])00))))$|^(?:0?[1-9]|1\d|2[0-8])(\/|-|\.)(?:(?:0?[1-9])|(?:1[0-2]))\4(?:(?:1[6-9]|[2-9]\d)?\d{2})/");
    bool check = regex_match(date, statement);
    return check;
}

bool isPriceValid(string& price) {
    regex statement("[+-]?([0-9]*[.])?[0-9]+");
    bool check = regex_match(price, statement);
    return check;
}

bool isPasswordValid(string& password) {
    regex statement("^.*(?=.{7,20})(?=.*[a-zA-Z])(?=.*\d)(?=.*[!#$%&?_]).*$");
    bool check = regex_match(password, statement);
    check = true;
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