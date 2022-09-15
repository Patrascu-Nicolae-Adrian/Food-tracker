#pragma once
#include<string>
class User
{
public:
	void setName(std::string);
	std::string getName();
	void setAge(int );
	int getAge();
	void setSex(std::string);
	bool getSex();
	void setHeight(double);
	double getHeight();
	void setWeight(double);
	double getWeight();
	void BMI();
	void setActivity();
	enum Activity{ sedentary, easy, moderate, high_activity};
	void setActivity(User::Activity );
	User::Activity getActivity() { return activity; }
	enum Bmi{ underweight, normalweight, overweight, obesity, obesity_extrem};
	void setBmi(User::Bmi);
	User::Bmi getBmi() { return bmi; }
	enum Purpose { weight_loss, weight_maintenance, weight_gain,};
	void setPurpose(User::Purpose);
	User::Purpose getPurpose() { return purpose; }
	enum Metabolism { slow_metabolism, normal_metabolism, fast_metabolism};
	void setMetabolism(User::Metabolism);
	User::Metabolism getMetabolism() { return metabolism; }
	void METABOLISM();
	void setActiv(std::string);
	void setPurp(std::string);
	User();
	User(std::string, int, std::string, double, double, std::string, std::string);
	friend std::ostream& operator<<(std::ostream&, User);
	User(char s[]);
private:
	std::string name;
	int age;
	bool sex;
	double height;
	double weight;
	User::Activity activity;
	User::Bmi bmi;
	User::Purpose purpose;
	User::Metabolism metabolism;
};