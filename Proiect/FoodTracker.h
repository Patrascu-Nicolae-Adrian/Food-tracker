#pragma once
#include "User.h"
#include "Meal.h"
#include "Aliment.h"
#include <vector>
#include <iostream>
class FoodTracker
{
	
public:
	FoodTracker();
	FoodTracker(std::string, int, std::string, double, double, std::string, std::string);
	User user;
	std::vector <Meal> meals;
	std::vector <Aliment> food_list;
	friend std::ostream& operator<<(std::ostream&, FoodTracker);
};

