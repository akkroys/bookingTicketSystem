#pragma once

#include "user.h"

void adminMenu(users*& user, concerts*& concert, string& login, tickets*& ticket);
void concertCRUD(concerts*& concert, string& login, tickets*& ticket);
string enterId(concerts*& concert);
string enterConcertName();
string enterDate();
string enterPlace();
string enterPrice();
void addNewConcert(concerts*& concert);