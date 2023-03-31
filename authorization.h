#pragma once

#include <iostream>
#include <clocale>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
using namespace std;


struct users {
    string login,
        password,
        surname,
        name,
        email,
        phoneNumber;
    int role;
};

struct concerts {
    string id,
        name,
        date,
        priceForUnit,
        place;
    int amount;
};

struct tickets {
    string login,
        concertID,
        amount;
};

string enterLogin(users*& user);
string enterPassword();
string enterSurname();
string enterName();
string enterEmail(users*& user);
string enterPhone();
void registration(users*& user);
pair <string, int> signIn(users*& user);
string entrance(users* user, concerts*& concert, tickets*& ticket);