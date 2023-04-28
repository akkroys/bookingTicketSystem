#pragma once

#include "authorization.h"
#include <fstream>
#include <sstream>
#include <vector>

const string USERS_INFO = "users.txt";
const string CONCERTS_INFO = "concerts.txt";
const string BOOKING_INFO = "tickects.txt";

int usersData(users*& user);
int concertData(concerts*& concert);
int tickectsData(tickets*& ticket);

void rewriteConcerts(concerts*& concert);
void rewriteTickets(tickets*& ticket);

void editStrConcert(string concertID, int newAmount);
void editStrPassword(string userPassword, string newPassword, users*& user, string login);

void addUser(string login, string password, string surname, string name, string email, string phone, int role);
void addConcert(string id, string name, string date, string priceForUnit, string place, int amount);
void addTickets(string login, string concertID, int amount);
