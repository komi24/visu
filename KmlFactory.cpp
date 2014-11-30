#include "KmlFactory.h"

using namespace std;

void KmlFactory::parseData(int day, int hour){
  this->parser = new Parser();
  this->parser->parseFile(day,hour);
  limitW = parser->stations.begin().longitude;
  limitE = limitE;
  limitN = parser->stations.begin().latitude;
  limitS = limitN;
  domainMin = parser->stations.begin().value;
  domainMax = domainMin;

  for(vector<Station>::iterator it = parser->stations.begin();
      it != parser->stations.end(); it++){
    if(limitW > it->longitude)
      limitW = it->longitude;
    if(limitE < it->longitude)
      limitE = it->longitude;
    if(limitN < it->latitude)
      limitN = it->latitude;
    if(limitS > it->latitude)
      limitS = it->latitude;
    if(domainMin > it->value)
      dmainMin = it->value;
    if(domainMax > it->value)
      domainMax = it->value;
  }

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
