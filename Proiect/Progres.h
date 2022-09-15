#pragma once
#include <iostream>
class Progres
{
public:
	void setConsume(double );
	double getConsume();
	void setProtein(double );
	double getProtein();
	void setCarbohydrate(double );
	double getCarbohydrate();
	void setFat(double );
	double getFat();
	Progres(char s[]);
	Progres();
	Progres(double, double, double, double);
	friend std::ostream& operator<<(std::ostream&, Progres);
	Progres operator+(Progres);
	Progres operator%(int);
private:
	double consume;
	double protein;
	double carbohydrate;
	double fat;
};

