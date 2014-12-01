#include "hardy.h"
#include </home/valouche/Téléchargements/eigen-eigen-1306d75b4a21/Eigen/Dense>

using namespace std;
using namespace Eigen;

static float ComputeMeanValues(std::vector<Station> &stations){
  float res=0;
  for (vector<Station>::iterator it = stations.begin(); it != stations.end();) {
  float longitude = it->longitude;
  float latitude = it->latitude;
  it++;
  res += sqrt( pow((it->longitude -longitude),2) + pow((it->latitude- latitude),2));
 
 }

 return res/(float)stations.size();
}
static Vector3f ComptuteHardyCoefficient(std::vector<Station> &stations, float R){

 Matrix3f A(stations.size(),stations.size());
 Vector3f b(stations.size());
 int i =0;
 for (vector<Station>::iterator it1 = stations.begin(); it1 != stations.end(); it1++) {
  
   b(i) = it1->value;
   int j = 0;
   for (vector<Station>::iterator it2 = stations.begin(); it2 != stations.end(); it2++) {
      
     A(i,j) = sqrt(R + pow((it1->longitude - it2->longitude),2) + pow((it1->latitude - it2->latitude),2));
     j++;
   }
   i++;
   } 
return A.colPivHouseholderQr().solve(b);

}
 

static float ComputeHardyInterpolation(const float longitude, const float latitude,  std::vector<Station> &stations,float R, Vector3f x) {

 float res = 0;




 int i = 0;

for (vector<Station>::iterator it = stations.begin(); it != stations.end(); it++) {
  res += x(i) *  sqrt(R + pow((it->longitude - longitude),2) + pow((it->latitude - latitude),2));
  i++;

  }



 
 return res;
}

// erkan : pour lancer le parsing
//  - tu déclares un parser "Parser p;"
//  - puis "p.parseFile(Jour désiré, Heure désirée);" avec
//      1 <= jour <= 11 et 0 <= heure <= 23
//  - et après p.stations suffit pour avoir la liste des stations
int main( int argc, const char* argv[] )
{
  /*  Station *station1 = new Station(10.0,10.0,1.50);
   Station *station2 = new Station(20.0,20.0,2.0);
   std::list<Station> stations;
stations.push_back(*station1); 
stations.push_back(*station2); 
// float R = 0.815*ComputeMeanValues(stations);
float 
   cout << ComputeHardyInterpolation(15.0,15.0,stations) << endl;
 
  */

    
}
