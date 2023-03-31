#pragma once

#include "user.h"

void adminMenu(users*& user, concerts*& concert, string& login);
void concertCRUD(concerts*& concert);
string enterId(concerts*& concert);
string enterConcertName();
string enterDate();
string enterPlace();
string enterPrice();
void addNewConcert(concerts*& concert);