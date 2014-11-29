#include "Station.h"

Station::Station() {

	this->longitude = 0.0;
	this->latitude = 0.0;
	this->value = 0;
}

Station::Station(float longitude, float latitude, int value) {
	
	this->longitude = longitude;
	this->latitude = latitude;
	this->value = value;
}