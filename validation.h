#pragma once
#include "authorization.h"
#include <algorithm>
#include <regex>

bool isRussianCapitalLetter(char letter);
string fixFirstLetter(string input);
bool isLoginValid(string& login);
bool isNameValid(string& name);
bool isPasswordValid(string& password);
bool isEmailValid(string& email);
bool isPhoneValid(string& phone);
bool isIdValid(string& id);
int checkInt(int a);
bool isDateValid(string& date);
bool isPriceValid(string& price);
extern void errorMessage();
string hiddenPassword();
string containsOnlyLetters(string str);