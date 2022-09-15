#include "FoodTracker.h"
#include <iomanip> 
using namespace std;
FoodTracker::FoodTracker(std::string name, int age, std::string sex, double height, double weight, std::string activity, std::string purpose) :user(name, age, sex, height, weight, activity, purpose) {}
FoodTracker::FoodTracker(){}


std::ostream& operator<<(std::ostream& out, FoodTracker f) {
	for (int i = 0; i < f.meals.size(); i++) {
		out << "{" << endl;
		out << f.meals[i].getDate() << endl;
		out << "<" << setprecision(1) << std::fixed << f.meals[i].expected.getConsume() << "," << f.meals[i].expected.getProtein() << "," << f.meals[i].expected.getCarbohydrate() << "," << f.meals[i].expected.getFat() << ">" << endl;
		out << "<" << f.meals[i].real.getConsume() << "," << f.meals[i].real.getProtein() << "," << f.meals[i].real.getCarbohydrate() << "," << f.meals[i].real.getFat() << ">" << endl;
		out << "/" << endl;
		out << "<" << f.meals[i].breakfast.expected.getConsume() << "," << f.meals[i].breakfast.expected.getProtein() << "," << f.meals[i].breakfast.expected.getCarbohydrate() << "," << f.meals[i].breakfast.expected.getFat() << ">" << endl;
		out << "<" << f.meals[i].breakfast.real.getConsume() << "," << f.meals[i].breakfast.real.getProtein() << "," << f.meals[i].breakfast.real.getCarbohydrate() << "," << f.meals[i].breakfast.real.getFat() << ">" << endl;
		out << "*" << endl;
		for (int j = 0; j < f.meals[i].breakfast.v_real.size(); j++) {
			out << f.meals[i].breakfast.v_real[j].alim.getName() << "," << f.meals[i].breakfast.v_real[j].getAmount() << "," << f.meals[i].breakfast.v_real[j].getPortie() << endl;
		}
		out << "*" << endl;
		for (int j = 0; j < f.meals[i].breakfast.v_expected.size(); j++) {
			out << f.meals[i].breakfast.v_expected[j].alim.getName() << "," << f.meals[i].breakfast.v_expected[j].getAmount() << "," << f.meals[i].breakfast.v_expected[j].getPortie() << endl;
		}
		out << "*" << endl;
		out << "/" << endl;
		out << "<" << f.meals[i].lunch.expected.getConsume() << "," << f.meals[i].lunch.expected.getProtein() << "," << f.meals[i].lunch.expected.getCarbohydrate() << "," << f.meals[i].lunch.expected.getFat() << ">" << endl;
		out << "<" << f.meals[i].lunch.real.getConsume() << "," << f.meals[i].lunch.real.getProtein() << "," << f.meals[i].lunch.real.getCarbohydrate() << "," << f.meals[i].lunch.real.getFat() << ">" << endl;
		out << "*" << endl;
		for (int j = 0; j < f.meals[i].lunch.v_real.size(); j++) {
			out << f.meals[i].lunch.v_real[j].alim.getName() << "," << f.meals[i].lunch.v_real[j].getAmount() << "," << f.meals[i].lunch.v_real[j].getPortie() << endl;
		}
		out << "*" << endl;
		for (int j = 0; j < f.meals[i].lunch.v_expected.size(); j++) {
			out << f.meals[i].lunch.v_expected[j].alim.getName() << "," << f.meals[i].lunch.v_expected[j].getAmount() << "," << f.meals[i].lunch.v_expected[j].getPortie() << endl;
		}
		out << "*" << endl;
		out << "/" << endl;
		out << "<" << f.meals[i].dinner.expected.getConsume() << "," << f.meals[i].dinner.expected.getProtein() << "," << f.meals[i].dinner.expected.getCarbohydrate() << "," << f.meals[i].dinner.expected.getFat() << ">" << endl;
		out << "<" << f.meals[i].dinner.real.getConsume() << "," << f.meals[i].dinner.real.getProtein() << "," << f.meals[i].dinner.real.getCarbohydrate() << "," << f.meals[i].dinner.real.getFat() << ">" << endl;
		out << "*" << endl;
		for (int j = 0; j < f.meals[i].dinner.v_real.size(); j++) {
			out << f.meals[i].dinner.v_real[j].alim.getName() << "," << f.meals[i].dinner.v_real[j].getAmount() << "," << f.meals[i].dinner.v_real[j].getPortie() << endl;
		}
		out << "*" << endl;
		for (int j = 0; j < f.meals[i].dinner.v_expected.size(); j++) {
			out << f.meals[i].dinner.v_expected[j].alim.getName() << "," << f.meals[i].dinner.v_expected[j].getAmount() << "," << f.meals[i].dinner.v_expected[j].getPortie() << endl;
		}
		out << "*" << endl;
		out << "/" << endl;
		out << "<" << f.meals[i].snacks.expected.getConsume() << "," << f.meals[i].snacks.expected.getProtein() << "," << f.meals[i].snacks.expected.getCarbohydrate() << "," << f.meals[i].snacks.expected.getFat() << ">" << endl;
		out << "<" << f.meals[i].snacks.real.getConsume() << "," << f.meals[i].snacks.real.getProtein() << "," << f.meals[i].snacks.real.getCarbohydrate() << "," << f.meals[i].snacks.real.getFat() << ">" << endl;
		out << "*" << endl;
		for (int j = 0; j < f.meals[i].snacks.v_real.size(); j++) {
			out << f.meals[i].snacks.v_real[j].alim.getName() << "," << f.meals[i].snacks.v_real[j].getAmount() << "," << f.meals[i].snacks.v_real[j].getPortie() << endl;
		}
		out << "*" << endl;
		for (int j = 0; j < f.meals[i].snacks.v_expected.size(); j++) {
			out << f.meals[i].snacks.v_expected[j].alim.getName() << "," << f.meals[i].snacks.v_expected[j].getAmount() << "," << f.meals[i].snacks.v_expected[j].getPortie() << endl;
		}
		out << "*" << endl;
		out << "/" << endl;
		out << "}" << endl;
	}
	return out;
}