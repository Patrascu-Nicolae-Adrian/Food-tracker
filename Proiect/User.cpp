#include "User.h"
#include <iostream>
using namespace std;
void User::setName(std::string num) { name = num; }
std::string User::getName() { return name; }
void User::setAge(int a) { age = a; }
int User::getAge() { return age; }
User::User(){}
User::User(std::string name, int age, std::string sex, double height, double weight, std::string activity, std::string purpose) {
	this->name = name;
	this->age = age;
	this->height = height;
	this->weight = weight;
	setSex(sex);
	setActiv(activity);
	setPurp(purpose);
	METABOLISM();
	BMI();
}
double convert_char_to_double(char* s) {
	double number = 0;
	int pos = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] != '.') {
			number = number * 10 + (s[i] - '0');
		}
		else pos = i;
	}
	if (pos != 0) {
		for (int i = 0; i < strlen(s) - pos - 1; i++) {
			number = number / 10;
		}
	}
	return number;
}
User::User(char line[]) {
	char* next_token = NULL;
	char* token = strtok_s(line, ",", &next_token);
	this->name = token;
	token = strtok_s(NULL, ",", &next_token);
	int age = atoi(token);
	this->age = age;
	token = strtok_s(NULL, ",", &next_token);
	setSex(token);
	token = strtok_s(NULL, ",", &next_token);
	double height = convert_char_to_double(token);
	this->height = height;
	token = strtok_s(NULL, ",", &next_token);
	double weight = convert_char_to_double(token);
	this->weight = weight;
	token = strtok_s(NULL, ",", &next_token);
	setActiv(token);
	token = strtok_s(NULL, ",", &next_token);
	setPurp(token);
}

void User::setSex(std::string s)
{
	if (s == "male")
		sex = false;
	else if (s == "female")
		sex = true;
}
bool User::getSex() { return sex; }
void User::setHeight(double h) { height = h; }
double User::getHeight() { return height; }
void User::setWeight(double w) { weight = w; }
double User::getWeight() { return weight; }
void User::BMI()
{
	double result;
	std::string bmi;
	result = weight / (height * height);
	if (result < 18.5)
		setBmi(User::underweight);
	else if (result >= 18.5 && result < 25)
		setBmi(User::normalweight);
	else if (result >= 25 && result < 30)
		setBmi(User::overweight);
	else if (result >= 30 && result < 40)
		setBmi(User::obesity);
	else setBmi(User::obesity_extrem);
}
void User::setActiv(std::string s) {
	if (s == "sedentary") {
		setActivity(User::sedentary);
	}
	if (s == "easy") {
		setActivity(User::easy);
	}
	if (s == "moderate") {
		setActivity(User::moderate);
	}
	if (s == "high_activity") {
		setActivity(User::high_activity);
	}
}
void User::setPurp(std::string s) {
	if (s == "weight_loss") {
		setPurpose(User::weight_loss);
	}
	if (s == "weight_gain") {
		setPurpose(User::weight_gain);
	}
	if (s == "weight_maintenance") {
		setPurpose(User::weight_maintenance);
	}

}
void User::setActivity(User::Activity activ) { activity = activ; }
void User::setBmi(User::Bmi b) { bmi = b; }
void User::setPurpose(User::Purpose p) { purpose = p; }
void User::setMetabolism(User::Metabolism m) { metabolism = m; }
void User::METABOLISM()
{
	if (getBmi() == 0 && getActivity() == 0 ) {
		setMetabolism(User::fast_metabolism);
	}
	if (getBmi() == 0 && getActivity() == 1) {
		setMetabolism(User::fast_metabolism);
	}
	if (getBmi() == 0 && getActivity() == 2) {
		setMetabolism(User::fast_metabolism);
	}
	if (getBmi() == 0 && getActivity() == 3) {
		setMetabolism(User::normal_metabolism);
	}
	if (getBmi() == 1 && getActivity() == 0) {
		setMetabolism(User::fast_metabolism);
	}
	if (getBmi() == 1 && getActivity() == 1) {
		setMetabolism(User::normal_metabolism);
	}
	if (getBmi() == 1 && getActivity() == 2) {
		setMetabolism(User::normal_metabolism);
	}
	if (getBmi() == 1 && getActivity() == 3) {
		setMetabolism(User::slow_metabolism);
	}
	if (getBmi() == 2 && getActivity() == 0) {
		setMetabolism(User::normal_metabolism);
	}
	if (getBmi() == 2 && getActivity() == 1) {
		setMetabolism(User::normal_metabolism);
	}
	if (getBmi() == 2 && getActivity() == 2) {
		setMetabolism(User::slow_metabolism);
	}
	if (getBmi() == 2 && getActivity() == 3) {
		setMetabolism(User::slow_metabolism);
	}
	if (getBmi() == 3 && getActivity() == 0) {
		setMetabolism(User::normal_metabolism);
	}
	if (getBmi() == 3 && getActivity() == 1) {
		setMetabolism(User::slow_metabolism);
	}
	if (getBmi() == 3 && getActivity() == 2) {
		setMetabolism(User::slow_metabolism);
	}
	if (getBmi() == 4 && getActivity() == 0) {
		setMetabolism(User::slow_metabolism);
	}
	if (getBmi() == 4 && getActivity() == 1) {
		setMetabolism(User::slow_metabolism);
	}
	if (getBmi() == 4 && getActivity() == 2) {
		setMetabolism(User::slow_metabolism);
	}
	if (getBmi() == 4 && getActivity() == 3) {
		setMetabolism(User::slow_metabolism);
	}
	if (getBmi() == 3 && getActivity() == 3) {
		setMetabolism(User::slow_metabolism);
	}
}
std::ostream& operator<<(std::ostream& o, User u) {
	o << "Name: " << u.getName() << endl;
	o << "Age: " << u.getAge() << endl;
	o << "Sex: ";
	if (u.getSex() == 0) {
		o << "male" << endl;
	}
	else o << "female" << endl;
	o << "Height: " << u.getHeight() << endl;
	o << "Weight: " << u.getWeight() << endl;
	o << "Activity: ";
	int OPTION = u.getActivity();
	switch (OPTION)
	{
	case 0:
		o << "sedentary" << endl;
		break;
	case 1:
		o << "easy" << endl;
		break;
	case 2:
		o << "moderate" << endl;
		break;
	case 3:
		o << "high_activity" << endl;
		break;
	default:
		break;
	}
	o << "Purpose: ";
	OPTION = u.getPurpose();
	switch (OPTION)
	{
	case 0:
		o << "weight_loss" << endl;
		break;
	case 1:
		o << "weight_gain" << endl;
		break;
	case 2:
		o << "weight_maintenance" << endl;
		break;

	default:
		break;
	}
	return o;
}


