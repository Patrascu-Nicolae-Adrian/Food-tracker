#include "Produs.h"
#include "FoodTracker.h"
#include <string>
#include <iostream>
FoodTracker f;
using namespace std;

void Produs::setAmount(double a) { amount = a; }
double Produs::getAmount() { return amount; }
void Produs::setPortie(double p) { portie = p; }
double Produs::getPortie() { return portie; }
int trans(char*& token, char*& next_token)
{

	const char progres_delim[4] = { "," };
	double a = atof(token);
	token = strtok_s(NULL, progres_delim, &next_token);
	return a;
}
Produs::Produs(char line[]) {
	
	char* next_token = NULL;
	const char progres_delim[4] = { "," };
	char* token = strtok_s(line, progres_delim, &next_token);
	this->alim.setName(token); 
	token = strtok_s(NULL, progres_delim, &next_token);
	this->amount = trans(token, next_token);
	this->portie = trans(token, next_token);
}
Produs::Produs(){ }
Produs::Produs(std::string name, double amount, double portie) {
	this->alim.setName(name);
	this->amount = amount;
	this->portie = portie;
}
ostream& operator<<(ostream& out, Produs p) {
	out << "Aliment: " << p.alim.getName() << endl;
	out << "Portion: " << p.getPortie() << endl;
	out << "Amount: " << p.getAmount() << endl;
	return out;
}