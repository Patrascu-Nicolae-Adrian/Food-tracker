#pragma once
#include <string>
class Aliment
{
public:
	void setName(std::string );
	std::string getName();
	void setEnergetic_value(double );
	double getEnergetic_value();
	void setFat(double );
	double getFat();
	void setGlucide(double );
	double getGlucide();
	void setProtein(double );
	double getProtein();
	Aliment(char s[]);
	Aliment();
	Aliment operator+(Aliment );
	Aliment operator*(int );
	Aliment operator%(int);
private:
	std::string name;
	double energetic_value;
	double fat;
	double glucide;
	double protein;
};

