#include "KmlFactory.h"

using namespace std;

void KmlFactory::parseData(int day, int hour){
  this->parser = new Parser();
  this->parser->parseFile(day,hour);
}

void KmlFactory::setInterp(float(*f)(float,float)){
  this->interp = f;
}

void KmlFactory::interpolate(float step){
  //TODO generate the list of points step by step
}

void KmlFactory::updateIsocont(float val){
  //TODO
}
