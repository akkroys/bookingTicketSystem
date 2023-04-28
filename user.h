#pragma once

#include "authorization.h"
#include "files.h"
#include "validation.h"
#include <sstream>
//#include "md5.h"
#include <ctime>

void userMenu(users*& user, concerts*& concert, string& login, tickets*& ticket);
void viewAllConcerts(concerts*& concert, string& login, tickets*& ticket);
string currentDateTime();
void currentList(concerts*& concert, string& login, tickets*& ticket);
void searchMenu(concerts*& concert);
void searchByName(concerts*& concert);
void searchByPlace(concerts*& concert);
void searchByPrice(concerts*& concert);
void sortMenu(concerts*& concert);
void sortByDate(concerts*& concert);
void sortByAlphabet(concerts*& concert);
void sortByPrice(concerts*& concert);

void userProfile(users*& user, concerts*& concert, string& login, tickets*& ticket);
void personalInformation(users*& user, string& login);
void cancelReservation(concerts*& concert, string& login, tickets*& ticket);

void bookingTickets(concerts*& concert, string& login, tickets*& ticket);
void boockedTickets(users*& user, concerts*& concert, string& login, tickets*& ticket);
