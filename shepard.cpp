#include "shepard.h"
using namespace std;

static float ComputeShepardInterpolation(const float longitude, const float latitude,  std::vector<Station> &stations) {
float inv = 0;
 float res = 0;

  for (vector<Station>::iterator it = stations.begin(); it != stations.end(); it++) {
    inv += 1/(pow((latitude - it->latitude),2) + pow((longitude - it->longitude),2));


  }

for (vector<Station>::iterator it = stations.begin(); it != stations.end(); it++) {
  res += (1/(pow((latitude - it->latitude),2) + pow((longitude - it->longitude),2)))*it->value  ;

  }
 res = res/inv ;


 
 return res;
}

// erkan : pour lancer le parsing
//  - tu déclares un parser "Parser p;"
//  - puis "p.parseFile(Jour désiré, Heure désirée);" avec
//      1 <= jour <= 11 et 0 <= heure <= 23
//  - et après p.stations suffit pour avoir la liste des stations
int main( int argc, const char* argv[] )
{
   Station *station1 = new Station(10.0,10.0,1.50);
   Station *station2 = new Station(20.0,20.0,2.0);
   std::list<Station> stations;
stations.push_back(*station1); 
stations.push_back(*station2); 
 cout << ComputeShepardInterpolation(15.0,15.0,stations) << endl;
 


        ofstream fichier("test.kml", ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert
 
        if(fichier)
        {
	  fichier << "<?xml version= \"1.0\" encoding= \"UTF-8\"?> "<< endl;
          fichier << "<kml xmlns=\"http://www.opengis.net/kml/2.2\">" << endl;
	  fichier <<  " <Folder>" <<endl <<
	    " <name>Ground Overlays</name>" << endl <<
	    "  <description>Examples of ground overlays</description>" <<endl <<
	    " <GroundOverlay>" <<endl<<
	    " <name>Large-scale overlay on terrain</name>" <<endl<<
	    " <description>Overlay shows Mount Etna erupting " <<endl<<
	    " on July 13th, 2001.</description>" << endl <<
	    " <Icon>" <<endl <<
	    " <href>http://developers.google.com/kml/documentation/images/etna.jpg</href>" << endl <<
	    "  </Icon>"<< endl<<
     " <LatLonBox>"<< endl <<
       " <north>37.91904192681665</north>"<< endl <<
       " <south>37.46543388598137</south>"<< endl <<
       " <east>15.35832653742206</east>"<< endl <<
       " <west>14.60128369746704</west>"<< endl <<
       " <rotation>-0.1556640799496235</rotation>"<< endl <<
     " </LatLonBox>"<< endl <<
   " </GroundOverlay>"<< endl <<
  "</Folder>"<< endl <<
	    "</kml>"<< endl;





                fichier.close();
        }
        else
                cerr << "Impossible d'ouvrir le fichier !" << endl;

 return 0;
}
