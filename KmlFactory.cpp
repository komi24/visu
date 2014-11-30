#include "KmlFactory.h"

using namespace std;

void KmlFactory::parseData(int day, int hour){
  this->parser = new Parser();
  cerr << "day =" << day << " hour =" << hour << endl;
}

void KmlFactory::setInterp(float(*f)(float,float)){
  this->interp = f;
}

void KmlFactory::interpolate(float step){
  //TODO
  this->interp(0.2,0.3);
}

void KmlFactory::updateIsocont(float val){
  //TODO
}
