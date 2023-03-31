#pragma once

#include "authorization.h"
#include "files.h"
#include "validation.h"

void userMenu(users*& user, concerts*& concert, string& login, tickets*& ticket);
void viewAllConcerts(concerts*& concert, string& login);
void searchMenu(concerts*& concert);
void searchByName(concerts*& concert);
void searchByPlace(concerts*& concert);
void searchByPrice(concerts*& concert);
void userProfile(users*& user, string& login, tickets*& ticket);

void bookingTickets(concerts*& concert, string& login, tickets*& ticket);
