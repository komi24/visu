#include "KmlFactory.h"

#include <iostream>
#include <string>

using namespace std;

int main() {

	int day;
	int hour;
	float isovalue; 

	// gestion du jour
	cout << "Veuillez entrer un jour entre 1 et 11 :" << endl;
	cin >> day;

	while (day < 1 || day > 11) {
		cout << "Veuillez entrer un jour entre 1 et 11 :" << endl;
		cin >> day;
	}

	// gestion de l'heure
	if (day < 11) {
		cout << "Veuillez entrer une heure entre 0 et 23 :" << endl;
		cin >> hour;

		while (hour < 0 || hour > 23) {
			cout << "Veuillez entrer une heure entre 0 et 23 :" << endl;
			cin >> hour;
		}
	} else {
		cout << "Veuillez entrer une heure entre 0 et 14 :" << endl;
		cin >> hour;

		while (hour < 0 || hour  > 14) {
			cout << "Veuillez entrer une heure entre 0 et 14 :" << endl;
			cin >> hour;
		}
	}


	// gestion de l'isovaleur
	cout << "Veuillez entrer l'isovaleur (float entre 0 et 300) :" << endl;
	cin >> isovalue;

	while (isovalue < 0 || isovalue > 11) {
		cout << "Veuillez entrer l'isovaleur (float entre 0 et 300) :" << endl;
		cin >> isovalue;
	}
	


	cout << "day : " << day << " hour : " << hour << " isovalue : " << isovalue << endl;

	KmlFactory *factory =  new KmlFactory;
	factory->parseData(day, hour);
	
	return 0;
}