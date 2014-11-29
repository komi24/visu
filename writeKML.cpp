#include "writeKML.h"

using namespace std;


//void writeKMLfile(const float North, const float South, const float West, const float East, const string name){
int main (int argc, char **argv){

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
            " <href>img.png</href>" << endl <<
            " <refreshMode>onInterval</refreshMode>" << endl <<
            " <refreshInterval>1</refreshInterval>" << endl <<
            "  </Icon>"<< endl<<
            " <LatLonBox>"<< endl <<
            " <north>37.91904192681665</north>"<< endl <<
            " <south>37.46543388598137</south>"<< endl <<
            " <east>15.35832653742206</east>"<< endl <<
            " <west>14.60128369746704</west>"<< endl <<
            " <rotation>-0.1556640799496235</rotation>"<< endl <<
            " </LatLonBox>"<< endl;


            fichier <<" </GroundOverlay>"<< endl <<
            "</Folder>"<< endl <<
            "</kml>" << endl;


                fichier.close();
        }
        else
                cerr << "Impossible d'ouvrir le fichier !" << endl;

        //
        //Ligne Iso-valeur
        //

        ofstream fichier2("test1.kml", ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier2 ouvert

        if(fichier2)
        {
          fichier2 << "<?xml version= \"1.0\" encoding= \"UTF-8\"?> "<< endl;
          fichier2 << "<kml xmlns=\"http://www.opengis.net/kml/2.2\">" << endl;
          fichier2 <<  " <Document>" <<endl <<
            " <name>Isovaleurs</name>" << endl <<
            "  <description>Affichage des isovaleurs de pollutions</description>" <<endl <<
            " <open>1</open>" << endl <<

            fichier2 << "<LineString>" << endl
            << "<extrude>1</extrude>" << endl
            << "<tessellate>1</tessellate>" << endl
            << "<altitudeMode>relativeToGround</altitudeMode>" << endl
            << "<coordinates>15.35832653742206,37.46543388598137,500 14.60128369746704,37.91904192681665,500 </coordinates>" << endl
            << "</LineString>" << endl;

          fichier2 <<" </Document>"<< endl <<
            "</kml>" << endl;

          fichier2.close();
        }
        else
          cerr << "Impossible d'ouvrir le fichier2 !" << endl;
        //Ligne isovaleur for (int k=0; k<2; k++) {
}
