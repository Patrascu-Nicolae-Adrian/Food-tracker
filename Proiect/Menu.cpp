#include "Menu.h"
#include "Progres.h"
#include <iostream>
using namespace std;
std::ostream& operator<<(std::ostream& out, Menu& m) {
	for (int i = 0; i < m.v_real.size(); i++) {
		out << m.v_real[i] << endl;
	}
	return out;
}

