#include "Aliment.h"
#include <string>
#include <iostream>
void Aliment::setName(std::string n) { name = n; }
std::string Aliment::getName() { return name; }
void Aliment::setEnergetic_value(double energetic) { energetic_value = energetic; }
double Aliment::getEnergetic_value() { return energetic_value; }
void Aliment::setFat(double f) { fat = f; }
double Aliment::getFat() { return fat; }
void Aliment::setGlucide(double g) { glucide = g; }
double Aliment::getGlucide() { return glucide; }
void Aliment::setProtein(double p) { protein = p; }
double Aliment::getProtein() { return protein; }
Aliment::Aliment(){
	this->energetic_value = 0;
	this->protein = 0;
	this->glucide = 0;
	this->fat = 0;
}
int transform2(char*& token, char*& next_token)
{

	const char progres_delim[4] = { ",><" };
	double a = atof(token);
	token = strtok_s(NULL, progres_delim, &next_token);
	return a;
}
Aliment::Aliment(char line[]) {
	char* next_token = NULL;
	const char progres_delim[4] = { "," };
	char* token = strtok_s(line, progres_delim, &next_token);
	name = token;
	token = strtok_s(NULL, progres_delim, &next_token);
	energetic_value = transform2(token, next_token);
	protein = transform2(token, next_token);
	glucide = transform2(token, next_token);
	fat = transform2(token, next_token);
}
Aliment Aliment::operator+(Aliment p)
{
	Aliment k;
	k.setEnergetic_value(getEnergetic_value() + p.getEnergetic_value());
	k.setProtein(getProtein() + p.getProtein());
	k.setGlucide(getGlucide() + p.getGlucide());
	k.setFat(getFat() + p.getFat());
	return k;
}
Aliment Aliment::operator*(int p) {
	Aliment k;
	k.setEnergetic_value(getEnergetic_value() * p);
	k.setProtein(getProtein() * p);
	k.setGlucide(getGlucide() * p);
	k.setFat(getFat() * p);
	return k;
}
Aliment Aliment::operator%(int p) {
	Aliment k;
	k.setEnergetic_value(getEnergetic_value() * p / 100);
	k.setProtein(getProtein() * p / 100);
	k.setGlucide(getGlucide() * p / 100);
	k.setFat(getFat() * p / 100);
	return k;
}

