#pragma once
#include "Aliment.h"
#include <iostream>
class Produs
{
private:
	double amount;
	double portie;
	friend std::ostream& operator<<(std::ostream&, Produs);
public:
	Aliment alim;
	void setAmount(double );
	double getAmount();
	void setPortie(double );
	double getPortie();
	Produs(char s[]);
	Produs();
	Produs(std::string, double, double);
};

