#ifndef DEF_KMLFACTORY
#define DEF_KML_FACTORY

#include "Parser.h"
#include "Point.h"
#include "Segment.h"
#include "isocontour.h"

class kmlFactory {
  private :
    float limitW,limitE,limitN,limitS;
    float domainMin,domainMax;
    Parser parser;
    std::vector<Point> values;
    std::vector<Segment> isocont;
    float(*interp)(float, float);

  public :
    kmlFactory();
    //parse le fichier et initialise les limites W,E,N,S et domainMax et Min
    //parser non NULL après appel
    void parseData(int day, int hour);
    void setInterp(float(*f)(float,float));
    void interpolate(float step);//Define limits before truely interpolate, create png and kml
    void updateIsocont(float val);
}
#endif
