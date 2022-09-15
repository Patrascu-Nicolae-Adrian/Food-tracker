

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include <time.h>
#include "FoodTracker.h"
#include "Mic_dejun.h"

using namespace std;
#define CREATE_USER 1
#define ACCESS_USER 2
#define EDIT_USER   3

#define USER 1
#define LOG  2
#define DATA 3

#define procent 10

int MENU_STATE = USER;
void menu();
void user_menu();
void createUser();
void edit_user();
void log_menu();
void access_user();
void data_menu();
void print_list_food();
void prev_view_progress(int);
void prev_view_food(int);
void prev_enter_food(int);
Meal view_progress(Meal);
void view_food(Meal);
Meal enter_food(Meal);
double convert_char_to_double(char*);
Aliment calc(Aliment, int, int);
Progres new_progres(Produs);
Progres calc_progress_exp(User);
Meal selectare_alimente(std::vector<Aliment>, int);

FoodTracker foodtracker;
int main()
{
	menu();
}
void menu() {
	while (true) {
		switch (MENU_STATE)
		{
		case USER:
			user_menu();
			break;
		case LOG:
			log_menu();
			break;
		case DATA:
			data_menu();
			break;
		}
	}
}
void user_menu() {
	char s[100];
	ifstream f("User.txt");
	system("cls");
	int nr = 0;
	while (f >> s) {
		nr++;
	}
	f.close();
	if (nr != 0) {
		ifstream f("User.txt");
		f.getline(s, 100);
		User aux(s);
		foodtracker.user = aux;
		f.close();
	}
	cout << "Please enter the corresponding number to advance in the menu:" << endl;
	cout << CREATE_USER << ". Create user" << endl;
	cout << ACCESS_USER << ". Access user" << endl;
	cout << EDIT_USER << ". Edit user" << endl;
	int STATE_USER;
	cin >> STATE_USER;
	switch (STATE_USER)
	{
	case CREATE_USER:
		createUser();
		MENU_STATE = USER;
		break;

	case ACCESS_USER:
		system("cls");
		access_user();
		MENU_STATE = LOG;
		break;
	case EDIT_USER:
		edit_user();
		MENU_STATE = LOG;
		break;
	default:
		MENU_STATE = USER;
		break;
	}
}

void createUser() {
	ifstream f("User.txt");
	f.seekg(0, f.beg);
	system("cls");
	if (f.peek() != EOF) {
		cout << "Existing user. Do you want to change the user?" << endl;
		cout << "1.No" << endl << "2.Yes" << endl;
		int OPTION;
		cin >> OPTION;
		system("cls");
		switch (OPTION)
		{
		case 1: {
			char s[100];
			f.getline(s, 100);
			User aux(s);
			foodtracker.user = aux;
			f.close();
			break;
		}
		case 2: {
			f.close();
			ofstream g("User.txt");
			cout << "Please introduce:" << endl << "Name: ";
			string name, sex, activity, purpose;
			int age;
			double height, weight;
			cin.ignore(256, '\n');
			getline(cin, name);
			g << name << ",";
			cout << "Age: "; cin >> age;
			g << age << ",";
			cout << "Sex(male/female): "; cin >> sex;
			g << sex << ","; 
			cout << "Height: "; cin >> height;
			g << height << ",";
			cout << "Weight: "; cin >> weight;
			g << weight << ",";
			cout << "Activity(sedentary/easy/moderate/high_activity): "; cin >> activity;
			g << activity << ","; 
			cout << "Purpose(weight_loss/weight_gain/weight_maintenance): "; cin >> purpose;
			g << purpose;
			system("cls");
			g.close();
			User aux(name, age,sex, height, weight,activity, purpose);
			foodtracker.user = aux;
			break;
		}
		default:
			break;
		}
	}
	else {
		f.close();
		ofstream g("User.txt");
		cout << "Please introduce:" << endl << "Name: ";
		string name, sex, activity, purpose;
		int age;
		double height, weight;
		cin.ignore(256, '\n');
		getline(cin, name);
		g << name << ",";
		cout << "Age: "; cin >> age;
		g << age << ",";
		cout << "Sex(male/female): "; cin >> sex;
		g << sex << ",";
		cout << "Height: "; cin >> height;
		g << height << ",";
		cout << "Weight: "; cin >> weight;
		g << weight << ",";
		cout << "Activity(sedentary/easy/moderate/high_activity): "; cin >> activity;
		g << activity << ",";
		cout << "Purpose(weight_loss/weight_gain/weight_maintenance): "; cin >> purpose;
		g << purpose;
		system("cls");
		g.close();
		User aux(name, age, sex, height, weight, activity, purpose);
		foodtracker.user = aux;
	}

}
void access_user() {
	log_menu();
}
void log_menu() {
	if (foodtracker.food_list.empty()) {
		ifstream f("Food_list.txt");
		char s[100];
		while (f.getline(s, 100)) {
			Aliment aux(s);
			foodtracker.food_list.push_back(aux);
		}
		f.close();
	}
	cout << "--- LOG[2] --" << endl;
	cout << "Enter the corresponding number to advance in the menu:" << endl;
	cout << "1. View food list" << endl;
	cout << "2. Add a new food in the list" << endl;
	cout << "3. Data view" << endl;
	cout << "4. Exit the application" << endl;

	int STATE_LOG;
	cin >> STATE_LOG;
	switch (STATE_LOG)
	{
	case 1: {
		ifstream f("Food_list.txt");
		string s;
		system("cls");
		while (!f.eof()) {
			getline(f, s);
			cout << s << endl;
		}
		f.close();
		MENU_STATE = LOG;
		break;
	}
	case 2: {
		ofstream f;
		f.open("Food_list.txt", ios::app);
		system("cls");
		print_list_food();
		cout << "Enter food(name, energetic_value, fat, carbohydrate, protein): " << endl;
		string s1;
		cin.ignore(256, '\n');
		getline(cin, s1);
		char s[100];
		strcpy(s, s1.c_str());
		Aliment aux(s);
		foodtracker.food_list.push_back(aux);
		f<<endl << s1;
		f.close();
		system("cls");
		break;
		MENU_STATE = LOG;
	}
	case 3: {
		system("cls");
		data_menu();
		MENU_STATE = LOG;
		break;
	}
	case 4: {
		ofstream f("Log.txt", ios::trunc);
		f << foodtracker;
		f.close();
		exit(0);
		break;
	}
	default:
		MENU_STATE = LOG;
		break;
	}
}
void edit_user() {
	ifstream f("log.txt");
	f.clear();
	f.close();
	ifstream file_information("User.txt");
	system("cls");
	cout << foodtracker.user << endl;
	cout << "Enter the corresponding number for the change you want to make:" << endl << "1. Name" << endl << "2. Age" << endl << "3. Sex" << endl << "4. Height" << endl;
	cout << "5. Weight" << endl << "6. Activity" << endl << "7. Purpose" << endl << "8. Back" << endl;
	int option;
	string name, sex, activity, purpose;
	int age;
	double height, weight;
	char user_information[100];
	file_information.getline(user_information, 100);
	User aux(user_information);
	foodtracker.user = aux;
	cin >> option;
	while (option != 8) {
		switch (option)
		{
		case 1: {
			cout << "Enter new name: "; 
			cin.ignore(256, '\n');
			getline(cin, name);
			foodtracker.user.setName(name);
			break;
		}
		case 2: {
			cout << "Enter new age: "; cin >> age;
			foodtracker.user.setAge(age);
			break;
		}
		case 3: {
			cout << "Enter new sex(male/female): "; cin >> sex;
			foodtracker.user.setSex(sex);
			break;
		}
		case 4: {
			cout << "Enter new height: "; cin >> height;
			foodtracker.user.setHeight(height);
			break;
		}
		case 5: {
			cout << "Enter new weight: "; cin >> weight;
			foodtracker.user.setWeight(weight);
			break;
		}
		case 6: {
			cout << "Enter new activity(sedentary/easy/moderate/high_activity): "; cin >> activity;
			foodtracker.user.setActiv(activity);
			break;
		}
		case 7: {
			cout << "Enter new purpose(weight_loss/weight_gain/weight_maintenance): "; cin >> purpose;
			foodtracker.user.setPurp(purpose);
			break;
		}
		}
		cin >> option;
	}
	system("cls");
	file_information.close();
	ofstream g("User.txt", ios::trunc);
	g << foodtracker.user.getName() << "," << foodtracker.user.getAge() << ",";
	if (foodtracker.user.getSex() == 0) {
		g << "male,";
	}
	else {
		g << "female,";
	}
	g << foodtracker.user.getHeight() << "," << foodtracker.user.getWeight() << ",";
	switch (foodtracker.user.getActivity())
	{
	case 0: {
		g << "sedentary,";
		break;
	}
	case 1: {
		g << "easy,";
		break;
	}
	case 2: {
		g << "moderate,";
		break;
	}
	case 3: {
		g << "high_activity,";
		break;
	}
	default:
		break;
	}
	switch (foodtracker.user.getPurpose())
	{
	case 0: {
		g << "weight_loss";
		break;
	}
	case 1: {
		g << "weight_maintenance";
		break;
	}
	case 2: {
		g << "weight_gain";
		break;
	}
	default:
		break;
	}
	g.close();
}
void data_menu() {
	if (foodtracker.meals.empty()) {
		ifstream f("Log.txt");
		char s[100];
		Meal aux;
		while (f.getline(s, 100)) {
			if (strcmp(s, "{") == 0) {
				f.getline(s, 100);
				aux.setDate(s);
				f.getline(s, 100);
				Progres aux1(s);
				aux.expected = aux1;
				f.getline(s, 100);
				Progres aux2(s);
				aux.real = aux2;
			}
			f.getline(s, 100);
			if (strcmp(s, "/") == 0) {
				f.getline(s, 100);
				Progres aux1(s);
				aux.breakfast.expected = aux1;
				f.getline(s, 100);
				Progres aux2(s);
				aux.breakfast.real = aux2;
				//cout << aux.breakfast.real.getCarbohydrate() << endl;
			}
			f.getline(s, 100);
			if (strcmp(s, "*") == 0) {
				f.getline(s, 100);
				while (strcmp(s, "*") != 0) {
					Produs aux1(s);
					aux.breakfast.v_real.push_back(aux1);
					f.getline(s, 100);
				}
				f.getline(s, 100);
				while (strcmp(s, "*") != 0) {
					Produs aux1(s);
					aux.breakfast.v_expected.push_back(aux1);
					f.getline(s, 100);
				}
			}
			f.getline(s, 100);
			if (strcmp(s, "/") == 0) {
				f.getline(s, 100);
				Progres aux1(s);
				aux.lunch.expected = aux1;
				f.getline(s, 100);
				Progres aux2(s);
				aux.lunch.real = aux2;
			}
			f.getline(s, 100);
			if (strcmp(s, "*") == 0) {
				f.getline(s, 100);
				while (strcmp(s, "*") != 0) {
					Produs aux1(s);
					aux.lunch.v_real.push_back(aux1);
					f.getline(s, 100);
				}
				f.getline(s, 100);
				while (strcmp(s, "*") != 0) {
					Produs aux1(s);
					aux.lunch.v_expected.push_back(aux1);
					f.getline(s, 100);
				}
			}
			f.getline(s, 100);
			if (strcmp(s, "/") == 0) {
				f.getline(s, 100);
				Progres aux1(s);
				aux.dinner.expected = aux1;
				f.getline(s, 100);
				Progres aux2(s);
				aux.dinner.real = aux2;
			}
			f.getline(s, 100);
			if (strcmp(s, "*") == 0) {
				f.getline(s, 100);
				while (strcmp(s, "*") != 0) {
					Produs aux1(s);
					aux.dinner.v_real.push_back(aux1);
					f.getline(s, 100);
				}
				f.getline(s, 100);
				while (strcmp(s, "*") != 0) {
					Produs aux1(s);
					aux.dinner.v_expected.push_back(aux1);
					f.getline(s, 100);
				}
			}
			f.getline(s, 100);
			if (strcmp(s, "/") == 0) {
				f.getline(s, 100);
				Progres aux1(s);
				aux.snacks.expected = aux1;
				f.getline(s, 100);
				Progres aux2(s);
				aux.snacks.real = aux2;
			}
			f.getline(s, 100);
			if (strcmp(s, "*") == 0) {
				f.getline(s, 100);
				while (strcmp(s, "*") != 0) {
					Produs aux1(s);
					aux.snacks.v_real.push_back(aux1);
					f.getline(s, 100);
				}
				f.getline(s, 100);
				while (strcmp(s, "*") != 0) {
					Produs aux1(s);
					aux.snacks.v_expected.push_back(aux1);
					f.getline(s, 100);
				}
			}
			f.getline(s, 100);
			f.getline(s, 100);
			foodtracker.meals.push_back(aux);
			aux.breakfast.v_real.clear();
			aux.breakfast.v_expected.clear();
			aux.lunch.v_real.clear();
			aux.lunch.v_expected.clear();
			aux.dinner.v_real.clear();
			aux.dinner.v_expected.clear();
			aux.snacks.v_real.clear();
			aux.snacks.v_expected.clear();
		}
		f.close();
	}
	Meal aux;
	Meal a;
	cout << "Enter the date: ";
	string date;
	int STATE_DATA = 0, ok = 0, poz;
	cin >> date;
	for (int i = 0; i < foodtracker.meals.size(); i++) {
		if (date == foodtracker.meals[i].getDate()) {
			ok = 1;
			poz = i;
		}
	}
	while (STATE_DATA != 4) {
		cout << "Enter the correspondent number to advance in the menu: " << endl << "1. View progress" << endl << "2. View food" << endl << "3. Enter food" << endl << "4. Back" << endl;
		cin >> STATE_DATA;
		if (ok == 1) {
			switch (STATE_DATA)
			{
			case 1: {
				system("cls");
				prev_view_progress(poz);
				break;
			}
			case 2: {
				system("cls");
				prev_view_food(poz);
				break;
			}
			case 3: {
				system("cls");
				prev_enter_food(poz);
				break;
			}
			default:
				break;
			}
		}
		else {
			aux.setDate(date);
			aux.expected = calc_progress_exp(foodtracker.user);
			aux.breakfast.expected = aux.expected % 40;
			aux.lunch.expected = aux.expected % 30;
			aux.dinner.expected = aux.expected % 20;
			aux.snacks.expected = aux.expected % 20;
			a = selectare_alimente(foodtracker.food_list, aux.breakfast.expected.getConsume());
			for (int i = 0; i < a.breakfast.v_expected.size(); i++) {
				aux.breakfast.v_expected.push_back(a.breakfast.v_expected[i]);
			}
			a = selectare_alimente(foodtracker.food_list, aux.lunch.expected.getConsume());
			for (int i = 0; i < a.breakfast.v_expected.size(); i++) {
				aux.lunch.v_expected.push_back(a.breakfast.v_expected[i]);
			}
			a = selectare_alimente(foodtracker.food_list, aux.dinner.expected.getConsume());
			for (int i = 0; i < a.breakfast.v_expected.size(); i++) {
				aux.dinner.v_expected.push_back(a.breakfast.v_expected[i]);
			}
			a = selectare_alimente(foodtracker.food_list, aux.snacks.expected.getConsume());
			for (int i = 0; i < a.breakfast.v_expected.size(); i++) {
				aux.snacks.v_expected.push_back(a.breakfast.v_expected[i]);
			}
			switch (STATE_DATA)
			{
			case 1: {
				system("cls");
				aux = view_progress(aux);
				break;
			}
			case 2: {
				system("cls");
				view_food(aux);
				break;
			}
			case 3: {
				system("cls");
				aux = enter_food(aux);
				break;
			}
			default:
				break;
			}
			foodtracker.meals.push_back(aux);
			break;
		}
	}
}
Meal selectare_alimente(std::vector<Aliment> vector, int cantitate_totala) {
	std::vector<Aliment> alimente_selectate;

	int cantitate_actuala = 0;

	int min_cant_totala = cantitate_totala - cantitate_totala * procent / 100;
	int max_cant_totala = cantitate_totala;
	Meal a;
	a.breakfast.v_expected.clear();
	do {

		Sleep(100);
		clock_t t = clock();

		srand((unsigned)time(0));
		int rand_index = (rand() * t) % vector.size();

		Aliment aliment = vector[rand_index];

		if (cantitate_actuala + aliment.getEnergetic_value() <= max_cant_totala) {
			alimente_selectate.push_back(aliment);
			cantitate_actuala += aliment.getEnergetic_value();
		}
	} while (!((cantitate_actuala <= max_cant_totala) && (cantitate_actuala >= min_cant_totala)));


	for (size_t idx = 0; idx < alimente_selectate.size(); idx++) {
		Produs p(alimente_selectate[idx].getName(), 100, 1);
		a.breakfast.v_expected.push_back(p);
	}
	return a;
}
Progres calc_progress_exp(User u) {
	Progres p;
	double consume= 0, protein = 0, carbo = 0, fat = 0;
	if (u.getSex() == 0) {
		consume = 66 + 13.7 * u.getWeight() + 5 * u.getHeight()*100 - 6.8 * u.getAge();
	}
	else {
		consume = 655 + 9.5 * u.getWeight() + 1.8 * u.getHeight() * 100 - 4.7 * u.getAge();
	}
	if (u.getActivity() == 0) {
		consume = consume * 1.2;
	}
	if (u.getActivity() == 1) {
		consume = consume * 1.375;
	}
	if (u.getActivity() == 2) {
		consume = consume * 1.55;
	}
	if (u.getActivity() == 3) {
		consume = consume * 1.725;
	}
	if (u.getPurpose() == 0) {
		consume = consume - 500;
	}
	if (u.getPurpose() == 2) {
		consume = consume + 500;
		p.setProtein(u.getWeight() * 2.5);
	}
	p.setConsume(consume);
	if (p.getProtein() == 0) {
		p.setProtein(u.getWeight() * 2);
	}
	p.setFat(30*consume / 900);
	p.setCarbohydrate((consume - p.getProtein() * 4 - p.getFat()*9) / 4);
	return p;
}
void prev_view_progress(int poz) {
	cout << "Enter the corresponding nuber for the type of progress you want to see: " << endl << "1. Real" << endl << "2. Expected" << endl;
	int OP;
	cin >> OP;
	if (OP == 1) {
		system("cls");
		cout << "Enter the corresponding number for the option you want: " << endl << "1. Breakfast" << endl << "2. Lunch" << endl;
		cout << "3. Dinner" << endl << "4. Snacks" << endl << "5. Total" << endl;
		int OPTION;
		cin >> OPTION;
		switch (OPTION)
		{
		case 1: {
			system("cls");
			cout << foodtracker.meals[poz].breakfast.real;
			break;
		}
		case 2: {
			system("cls");
			cout << foodtracker.meals[poz].lunch.real;
			break;
		}
		case 3: {
			system("cls");
			cout << foodtracker.meals[poz].dinner.real;
			break;
		}
		case 4: {
			system("cls");
			cout << foodtracker.meals[poz].snacks.real;
			break;
		}
		case 5: {
			system("cls");
			cout << foodtracker.meals[poz].real;
			break;
		}
		default:
			break;
		}
	}
	else {
		system("cls");
		cout << "Enter the corresponding number for the option you want: " << endl << "1. Breakfast" << endl << "2. Lunch" << endl;
		cout << "3. Dinner" << endl << "4. Snacks" << endl << "5. Total" << endl;
		int OPTION;
		cin >> OPTION;
		switch (OPTION)
		{
		case 1: {
			system("cls");
			cout << foodtracker.meals[poz].breakfast.expected;
			break;
		}
		case 2: {
			system("cls");
			cout << foodtracker.meals[poz].lunch.expected;
			break;
		}
		case 3: {
			system("cls");
			cout << foodtracker.meals[poz].dinner.expected;
			break;
		}
		case 4: {
			system("cls");
			cout << foodtracker.meals[poz].snacks.expected;
			break;
		}
		case 5: {
			system("cls");
			cout << foodtracker.meals[poz].expected;
			break;
		}
		default:
			break;
		}
	}
}
void prev_view_food(int poz) {
	cout << "Enter the corresponding number for the type of food you want to see: " << endl << "1. Real" << endl << "2. Expected" << endl;
	int OP;
	cin >> OP;
	if (OP == 1) {
		system("cls");
		cout << "Enter the corresponding number for the option you want: " << endl << "1. Breakfast" << endl << "2. Lunch" << endl;
		cout << "3. Dinner" << endl << "4. Snacks" << endl << "5. Total" << endl;
		int OPTION;
		cin >> OPTION;
		switch (OPTION)
		{
		case 1: {
			system("cls");
			cout << foodtracker.meals[poz].breakfast;
			break;
		}
		case 2: {
			system("cls");
			cout << foodtracker.meals[poz].lunch;
			break;
		}
		case 3: {
			system("cls");
			cout << foodtracker.meals[poz].dinner;
			break;
		}
		case 4: {
			system("cls");
			cout << foodtracker.meals[poz].snacks;
			break;
		}
		case 5: {
			system("cls");
			cout << foodtracker.meals[poz].breakfast;
			cout << foodtracker.meals[poz].lunch;
			cout << foodtracker.meals[poz].dinner;
			cout << foodtracker.meals[poz].snacks;
			break;
		}
		default:
			break;
		}
	}
	else {
		system("cls");
		cout << "Enter the corresponding number for the option you want: " << endl << "1. Breakfast" << endl << "2. Lunch" << endl;
		cout << "3. Dinner" << endl << "4. Snacks" << endl << "5. Total" << endl;
		int OPTION;
		cin >> OPTION;
		switch (OPTION)
		{
		case 1: {
			system("cls");
			for (int i = 0; i < foodtracker.meals[poz].breakfast.v_expected.size(); i++) {
				cout << foodtracker.meals[poz].breakfast.v_expected[i];
			}
			break;
		}
		case 2: {
			system("cls");
			for (int i = 0; i < foodtracker.meals[poz].lunch.v_expected.size(); i++) {
				cout << foodtracker.meals[poz].lunch.v_expected[i];
			}
			break;
		}
		case 3: {
			system("cls");
			for (int i = 0; i < foodtracker.meals[poz].dinner.v_expected.size(); i++) {
				cout << foodtracker.meals[poz].dinner.v_expected[i];
			}
			break;
		}
		case 4: {
			system("cls");
			for (int i = 0; i < foodtracker.meals[poz].snacks.v_expected.size(); i++) {
				cout << foodtracker.meals[poz].snacks.v_expected[i];
			}
			break;
		}
		case 5: {
			system("cls");
			for (int i = 0; i < foodtracker.meals[poz].breakfast.v_expected.size(); i++) {
				cout << foodtracker.meals[poz].breakfast.v_expected[i];
			}
			for (int i = 0; i < foodtracker.meals[poz].lunch.v_expected.size(); i++) {
				cout << foodtracker.meals[poz].lunch.v_expected[i];
			}
			for (int i = 0; i < foodtracker.meals[poz].dinner.v_expected.size(); i++) {
				cout << foodtracker.meals[poz].dinner.v_expected[i];
			}
			for (int i = 0; i < foodtracker.meals[poz].snacks.v_expected.size(); i++) {
				cout << foodtracker.meals[poz].snacks.v_expected[i];
			}
			break;
		}
		default:
			break;
		}
	}
}
void prev_enter_food(int poz) {
	cout << "Enter the corresponding number for the option you want: " << endl << "1. Breakfast" << endl << "2. Lunch" << endl;
	cout << "3. Dinner" << endl << "4. Snacks" << endl;
	int OPTION;
	string s1;
	char s[100];
	Meal aux;
	cin >> OPTION;
	switch (OPTION)
	{
	case 1: {
		system("cls");
		print_list_food();
		cout << endl << "Enter the food in the following format (name, amount, portion): ";
		cin.ignore(256, '\n');
		getline(cin, s1);
		strcpy(s, s1.c_str());
		Produs aux1(s);
		aux = foodtracker.meals[poz];
		aux.breakfast.v_real.push_back(aux1);
		foodtracker.meals[poz] = aux;
		foodtracker.meals[poz].breakfast.real = foodtracker.meals[poz].breakfast.real + new_progres(aux1);
		foodtracker.meals[poz].real = foodtracker.meals[poz].real + foodtracker.meals[poz].breakfast.real;
		system("cls");
		break;
	}
	case 2: {
		system("cls");
		print_list_food();
		cout << endl << "Enter the food in the following format (name, amount, portion): ";
		cin.ignore(256, '\n');
		getline(cin, s1);
		strcpy(s, s1.c_str());
		Produs aux1(s);
		aux = foodtracker.meals[poz];
		aux.lunch.v_real.push_back(aux1);
		foodtracker.meals[poz] = aux;
		foodtracker.meals[poz].lunch.real = foodtracker.meals[poz].lunch.real + new_progres(aux1);
		foodtracker.meals[poz].real = foodtracker.meals[poz].real + foodtracker.meals[poz].lunch.real;
		system("cls");
		break;
	}
	case 3: {
		system("cls");
		print_list_food();
		cout << endl << "Enter the food in the following format (name, amount, portion): ";
		cin.ignore(256, '\n');
		getline(cin, s1);
		strcpy(s, s1.c_str());
		Produs aux1(s);
		aux = foodtracker.meals[poz];
		aux.dinner.v_real.push_back(aux1);
		foodtracker.meals[poz] = aux;
		foodtracker.meals[poz].dinner.real = foodtracker.meals[poz].dinner.real + new_progres(aux1);
		foodtracker.meals[poz].real = foodtracker.meals[poz].real + foodtracker.meals[poz].dinner.real;
		system("cls");
		break;
	}
	case 4: {
		system("cls");
		print_list_food();
		cout << endl << "Enter the food in the following format (name, amount, portion): ";
		cin.ignore(256, '\n');
		getline(cin, s1);
		strcpy(s, s1.c_str());
		Produs aux1(s);
		aux = foodtracker.meals[poz];
		aux.snacks.v_real.push_back(aux1);
		foodtracker.meals[poz] = aux;
		foodtracker.meals[poz].snacks.real = foodtracker.meals[poz].snacks.real + new_progres(aux1);
		foodtracker.meals[poz].real = foodtracker.meals[poz].real + foodtracker.meals[poz].snacks.real;
		system("cls");
		break;
	}
	default:
		break;
	}
}
Meal view_progress(Meal aux) {
	//Meal m;
	cout << "Enter the corresponding nuber for the type of progress you want to see: " << endl << "1. Real" << endl << "2. Expected" << endl;
	int OP;
	cin >> OP;
	if (OP == 1) {
		system("cls");
		cout << "Enter the corresponding number for the option you want: " << endl << "1. Breakfast" << endl << "2. Lunch" << endl;
		cout << "3. Dinner" << endl << "4. Snacks" << endl << "5. Total" << endl;
		int OPTION;
		cin >> OPTION;
		switch (OPTION)
		{
		case 1: {
			system("cls");
			cout << aux.breakfast.real;
			break;
		}
		case 2: {
			system("cls");
			cout << aux.lunch.real;
			break;
		}
		case 3: {
			system("cls");
			cout << aux.dinner.real;
			break;
		}
		case 4: {
			system("cls");
			cout << aux.snacks.real;
			break;
		}
		case 5: {
			system("cls");
			cout << aux.real;
			break;
		}
		default:
			break;
		}
	}
	else {
		system("cls");
		cout << "Enter the corresponding number for the option you want: " << endl << "1. Breakfast" << endl << "2. Lunch" << endl;
		cout << "3. Dinner" << endl << "4. Snacks" << endl << "5. Total" << endl;
		int OPTION;
		cin >> OPTION;
		switch (OPTION)
		{
		case 1: {
			system("cls");
			cout << aux.breakfast.expected;
			break;
		}
		case 2: {
			system("cls");
			cout << aux.lunch.expected;
			break;
		}
		case 3: {
			system("cls");
			cout << aux.dinner.expected;
			break;
		}
		case 4: {
			system("cls");
			cout << aux.snacks.expected;
			break;
		}
		case 5: {
			system("cls");
			cout << aux.expected;
			break;
		}
		default:
			break;
		}
	}
	return aux;
}
Aliment calc(Aliment a, int cant, int portie) {
	if (cant == 0) {
		a = a * portie;
	}
	else {
		a = a % (cant * portie);
	}
	return a;
}
Progres new_progres(Produs aux) {
	Aliment a;
	Progres p;
	for (int j = 0; j < foodtracker.food_list.size(); j++) {
		if (aux.alim.getName() == foodtracker.food_list[j].getName()) {
			a = calc(foodtracker.food_list[j], aux.getAmount(), aux.getPortie());
			Progres p1(a.getEnergetic_value(), a.getProtein(), a.getGlucide(), a.getFat());
			p = p + p1;
		}
	}
	return p;
}
void view_food(Meal aux) {
	cout << "Enter the corresponding number for the type of food you want to see: " << endl << "1. Real" << endl << "2. Expected" << endl;
	int OP;
	cin >> OP;
	if (OP == 1) {
		system("cls");
		cout << "Enter the corresponding number for the option you want: " << endl << "1. Breakfast" << endl << "2. Lunch" << endl;
		cout << "3. Dinner" << endl << "4. Snacks" << endl << "5. Total" << endl;
		int OPTION;
		cin >> OPTION;
		switch (OPTION)
		{
		case 1: {
			system("cls");
			cout << aux.breakfast;
			break;
		}
		case 2: {
			system("cls");
			cout << aux.lunch;
			break;
		}
		case 3: {
			system("cls");
			cout << aux.dinner;
			break;
		}
		case 4: {
			system("cls");
			cout << aux.snacks;
			break;
		}
		case 5: {
			system("cls");
			cout << aux.breakfast;
			cout << aux.lunch;
			cout << aux.dinner;
			cout << aux.snacks;
			break;
		}
		default:
			break;
		}
	}
	else {
		system("cls");
		cout << "Enter the corresponding number for the option you want: " << endl << "1. Breakfast" << endl << "2. Lunch" << endl;
		cout << "3. Dinner" << endl << "4. Snacks" << endl << "5. Total" << endl;
		int OPTION;
		cin >> OPTION;
		switch (OPTION)
		{
		case 1: {
			system("cls");
			for (int i = 0; i < aux.breakfast.v_expected.size(); i++) {
				cout << aux.breakfast.v_expected[i];
			}
			break;
		}
		case 2: {
			system("cls");
			for (int i = 0; i < aux.lunch.v_expected.size(); i++) {
				cout << aux.lunch.v_expected[i];
			}
			break;
		}
		case 3: {
			system("cls");
			for (int i = 0; i < aux.dinner.v_expected.size(); i++) {
				cout << aux.dinner.v_expected[i];
			}
			break;
		}
		case 4: {
			system("cls");
			for (int i = 0; i < aux.snacks.v_expected.size(); i++) {
				cout << aux.snacks.v_expected[i];
			}
			break;
		}
		case 5: {
			system("cls");
			for (int i = 0; i < aux.breakfast.v_expected.size(); i++) {
				cout << aux.breakfast.v_expected[i];
			}
			for (int i = 0; i < aux.lunch.v_expected.size(); i++) {
				cout << aux.lunch.v_expected[i];
			}
			for (int i = 0; i < aux.dinner.v_expected.size(); i++) {
				cout << aux.dinner.v_expected[i];
			}
			for (int i = 0; i < aux.snacks.v_expected.size(); i++) {
				cout << aux.snacks.v_expected[i];
			}
			break;
		}
		default:
			break;
		}
	}
}
Meal enter_food(Meal aux) {
	cout << "Enter the corresponding number for the option you want: " << endl << "1. Breakfast" << endl << "2. Lunch" << endl;
	cout << "3. Dinner" << endl << "4. Snacks" << endl;
	int OPTION;
	string s1;
	char s[100];
	cin >> OPTION;
	switch (OPTION)
	{
	case 1: {
		system("cls");
		print_list_food();
		cout << endl << "Enter the food in the following format (name, amount, portion): ";
		cin.ignore(256, '\n');
		getline(cin, s1);
		strcpy(s, s1.c_str());
		Produs aux1(s);
		aux.breakfast.v_real.push_back(aux1);
		aux.breakfast.real = aux.breakfast.real + new_progres(aux1);
		aux.real = aux.real + aux.breakfast.real;
		system("cls");
		break;
	}
	case 2: {
		system("cls");
		print_list_food();
		cout << endl << "Enter the food in the following format (name, amount, portion): ";
		cin.ignore(256, '\n');
		getline(cin, s1);
		strcpy(s, s1.c_str());
		Produs aux1(s);
		aux.lunch.v_real.push_back(aux1);
		aux.lunch.real = aux.lunch.real + new_progres(aux1);
		aux.real = aux.real + aux.lunch.real;
		system("cls");
		break;
	}
	case 3: {
		system("cls");
		print_list_food();
		cout << endl << "Enter the food in the following format (name, amount, portion): ";
		cin.ignore(256, '\n');
		getline(cin, s1);
		strcpy(s, s1.c_str());
		Produs aux1(s);
		aux.dinner.v_real.push_back(aux1);
		aux.dinner.real = aux.dinner.real + new_progres(aux1);
		aux.real = aux.real + aux.dinner.real;
		system("cls");
		break;
	}
	case 4: {
		system("cls");
		print_list_food();
		cout << endl << "Enter the food in the following format (name, amount, portion): ";
		cin.ignore(256, '\n');
		getline(cin, s1);
		strcpy(s, s1.c_str());
		Produs aux1(s);
		aux.snacks.v_real.push_back(aux1);
		aux.snacks.real = aux.snacks.real + new_progres(aux1);
		aux.real = aux.real + aux.snacks.real;
		system("cls");
		break;
	}
	default:
		break;
	}
	return aux;
}
void print_list_food() {
	for (int i = 0; i < foodtracker.food_list.size(); i++) {
		cout << foodtracker.food_list[i].getName() << endl;
	}
}

