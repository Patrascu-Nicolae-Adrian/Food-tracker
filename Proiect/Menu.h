#pragma once
#include "Progres.h"
#include "Produs.h"
#include <vector>
#include <iostream>
class Menu
{
public:
	Progres real;
	Progres expected;
	std::vector<Produs> v_real;
	std::vector<Produs> v_expected;
	friend std::ostream& operator<<(std::ostream&, Menu&);

};

