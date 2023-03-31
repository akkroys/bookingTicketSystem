#include "files.h"

int usersData(users*& user) {
	ifstream usersFile(USERS_INFO, ios::in);
	char buffer[120];
	int counter;
	for (counter = 0; usersFile.getline(buffer, 120); counter++);
	usersFile.close();
	usersFile.open(USERS_INFO, ios::in);
	user = new users[counter];
	for (int i = 0; i < counter; i++)
	{
		usersFile >> user[i].login;
		usersFile >> user[i].password;
		usersFile >> user[i].surname;
		usersFile >> user[i].name;
		usersFile >> user[i].email;
		usersFile >> user[i].phoneNumber;
		usersFile >> user[i].role;
	}
	usersFile.close();
	return counter;
}

void addUser(string login, string password, string surname, string name, string email, string phone, int role) {
	ofstream addUsersData(USERS_INFO, ios::app);
	addUsersData << setw(15) << left << login
		<< setw(35) << left << password 
		<< setw(17) << left << surname 
		<< setw(17) << left << name 
		<< setw(20) << left << email 
		<< setw(12) << left << phone 
		<< setw(3) << left << role << endl;
	addUsersData.close();
}

void rewriteUsers(users*& user) {
	ifstream usersFile(USERS_INFO, ios::in);
	char buffer[120];
	int counter;
	for (counter = 0; usersFile.getline(buffer, 120); counter++);
	usersFile.close();
	ofstream userFile (USERS_INFO, ios::trunc);
	user = new users[counter];
	for (int i = 0; i < counter; i++)
	{
		userFile << setw(15) << left << user[i].login
			<< setw(35) << left << user[i].password
			<< setw(17) << left << user[i].surname
			<< setw(17) << left << user[i].name
			<< setw(20) << left << user[i].email
			<< setw(12) << left << user[i].phoneNumber
			<< setw(3) << left << user[i].role << endl;
	}
	usersFile.close();
}

int concertData(concerts*& concert) {
	ifstream concertFile(CONCERTS_INFO, ios::in);
	char buffer[90];
	int counter;
	for (counter = 0; concertFile.getline(buffer, 90); counter++);
	concertFile.close();
	concertFile.open(CONCERTS_INFO, ios::in);
	concert = new concerts[counter];
	for (int i = 0; i < counter; i++)
	{
		concertFile >> concert[i].id;
		concertFile >> concert[i].name;
		concertFile >> concert[i].date;
		concertFile >> concert[i].priceForUnit;
		concertFile >> concert[i].place;
		concertFile >> concert[i].amount;
	}
	concertFile.close();
	return counter;
}

void addConcert(string id, string name, string date, string priceForUnit, string place, int amount) {
	ofstream addConcertsData(CONCERTS_INFO, ios::app);
	addConcertsData << setw(8) << left << id
		<< setw(25) << left << name
		<< setw(12) << left << date
		<< setw(10) << left << priceForUnit
		<< setw(20) << left << place
		<< setw(8) << left << amount << endl;
	addConcertsData.close();
}

void rewriteConcerts(concerts*& concert) {
	ifstream concertFile(CONCERTS_INFO, ios::in);
	char buffer[90];
	int counter;
	for (counter = 0; concertFile.getline(buffer, 90); counter++);
	concertFile.close();
	ofstream concertsFile (CONCERTS_INFO, ios::trunc);
	concert = new concerts[counter];

	for (int i = 0; i < counter; i++) {
		concertsFile << setw(8) << left << concert[i].id
			<< setw(25) << left << concert[i].name
			<< setw(12) << left << concert[i].date
			<< setw(10) << left << concert[i].priceForUnit
			<< setw(20) << left << concert[i].place
			<< setw(8) << left << concert[i].amount << endl;
	}
	concertsFile.close();
}

int tickectsData(tickets*& ticket) {
	ifstream ticketsFile(BOOKING_INFO, ios::in);
	char buffer[120];
	int counter;
	for (counter = 0; ticketsFile.getline(buffer, 120); counter++);
	ticketsFile.close();
	ticketsFile.open(BOOKING_INFO, ios::in);
	ticket = new tickets[counter];
	for (int i = 0; i < counter; i++)
	{
		ticketsFile >> ticket[i].login;
		ticketsFile >> ticket[i].concertID;
		ticketsFile >> ticket[i].amount;
	}
	ticketsFile.close();
	return counter;
}

void addTickets(string login, string concertID, int amount) {
	ofstream addTicketsData(BOOKING_INFO, ios::app);
	addTicketsData << setw(15) << left << login
		<< setw(8) << left << concertID
		<< setw(8) << left << amount << endl;
	addTicketsData.close();
}