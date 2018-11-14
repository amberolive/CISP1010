/*
Name: Amber Rivera
Chapter: 10
Exercise: 1

This program:

*/

#include <cctype>
#include <iostream>
#include <iomanip>
#include <string>
#include "Planet.h"

using namespace std;

void DisplayPlanets();
double GetWeight();
double CalculateWeightOnPlanet(Planet, double);
Planet GetPlanet();

int main() {
	DisplayPlanets();
	double weight = GetWeight();
	Planet planet = GetPlanet();
	cout << fixed << setprecision(2);
	cout << endl << endl << "Your weight would be " << CalculateWeightOnPlanet(planet, weight) << ".";
	cin.get();
	cin.get();
}

void DisplayPlanets() {
	cout << "Mercury: 0" << endl;
	cout << "Venus: 1" << endl;
	cout << "Earth: 2" << endl;
	cout << "Moon: 3" << endl;
	cout << "Mars: 4" << endl;
	cout << "Jupiter: 5" << endl;
	cout << "Saturn: 6" << endl;
	cout << "Uranus: 7" << endl;
	cout << "Neptune: 8" << endl;
	cout << "Pluto: 9" << endl << endl;
}

double GetWeight() {
	double weight;
	cout << "Please enter your weight: ";
	cin >> weight;
	return weight;
}

double CalculateWeightOnPlanet(Planet planet, double weight) {
	switch (planet) {
	case Mercury:
		weight *= 0.4155;
		break;
	case Venus:
		weight *= 0.8975;
		break;
	case Earth:
		weight *= 1.0;
		break;
	case Moon:
		weight *= 0.166;
		break;
	case Mars:
		weight *= 0.3507;
		break;
	case Jupiter:
		weight *= 2.5374;
		break;
	case Saturn:
		weight *= 1.0677;
		break;
	case Uranus:
		weight *= 0.8947;
		break;
	case Neptune:
		weight *= 1.1794;
		break;
	case Pluto:
		weight *= 0.0899;
		break;
	default:
		break;
	}
	return weight;
}

Planet GetPlanet() {
	int planetId = 0;
	do {
		cout << "Please enter the id of the planet you would like to calculate your weight for (ex. 0 for Mercury): ";
		cin >> planetId;
	} while (planetId < 0 || planetId > 9);
	return Planet(planetId);
}