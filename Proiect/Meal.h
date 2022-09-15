#pragma once
#include "Mic_dejun.h"
#include "Pranz.h"
#include "Menu.h"
#include "Progres.h"
#include "Aliment.h"
#include <iostream>
#include <string>
#include <vector>
class Meal
{
private:
	std::string date;

public:
	void setDate(std::string);
	std::string getDate();
	Progres expected;
	Progres real;
	Menu breakfast;
	Menu lunch;
	Menu dinner;
	Menu snacks;
	Menu total;

};

