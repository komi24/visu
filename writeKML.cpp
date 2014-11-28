#include "writeKML.h"

using namespace std;


void writeKMLfile(const float North, const float South, const float West, const float East, const string name){


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
}
