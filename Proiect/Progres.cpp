#include "Progres.h"
#include <string>
#include <iostream>
using namespace std;

void Progres::setConsume(double consum) { consume = consum; }
double Progres::getConsume() { return consume; }
void Progres::setProtein(double pro) { protein = pro; }
double Progres::getProtein() { return protein; }
void Progres::setCarbohydrate(double carbo) { carbohydrate = carbo; }
double Progres::getCarbohydrate() { return carbohydrate; }
void Progres::setFat(double f) { fat = f; }
double Progres::getFat() { return fat; }
Progres::Progres(double consume, double protein, double carbohydrate, double fat) {
	this->consume = consume;
	this->protein = protein;
	this->carbohydrate = carbohydrate;
	this->fat = fat;
}
int transform1(char*& token, char*& next_token)
{

	const char progres_delim[4] = { ",><" };
	double a = atof(token);
	token = strtok_s(NULL, progres_delim, &next_token);
	return a;
}
Progres::Progres(char line[]) {
	char* next_token = NULL;
	const char progres_delim[4] = { ",><" };
	char* token = strtok_s(line, progres_delim, &next_token);
	consume = transform1(token, next_token);
	protein = transform1(token, next_token);
	carbohydrate = transform1(token, next_token);
	fat = transform1(token, next_token);
}
Progres::Progres() {
	consume = 0;
	protein = 0;
	carbohydrate = 0;
	fat = 0;
}

std::ostream& operator<<(std::ostream& out, Progres p) {
	out << "Consume: " << p.getConsume() << endl;
	out << "Protein: " << p.getProtein() << endl;
	out << "Carbohydrate: " << p.getCarbohydrate() << endl;
	out << "Fat: " << p.getFat() << endl;
	return out;
}
Progres Progres::operator+(Progres p)
{
	Progres k;
	k.setConsume(getConsume() + p.getConsume());
	k.setProtein(getProtein() + p.getProtein());
	k.setCarbohydrate(getCarbohydrate() + p.getCarbohydrate());
	k.setFat(getFat() + p.getFat());
	return k;
}
Progres Progres::operator%(int p)
{
	Progres k;
	k.setConsume(getConsume() * p / 100);
	k.setProtein(getProtein() * p / 100);
	k.setCarbohydrate(getCarbohydrate() * p / 100);
	k.setFat(getFat() * p / 100);
	return k;
}
