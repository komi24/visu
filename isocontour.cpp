#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
  // Valeur de l'isocontour
  float p=0.5;
  // Sommets du carré en cours
  // ATTENTION les sommets sont un a un adjacents
  float coorx[4];
  float coory[4];
  float val[4];
  int i1,i2;

  //Initialisation pour test
  coorx[0]=0;
  coorx[1]=1;
  coorx[2]=1;
  coorx[3]=0;
  coory[0]=0;
  coory[1]=0;
  coory[2]=1;
  coory[3]=1;
  cin >> val[0];
  cin >> val[1];
  cin >> val[2];
  cin >> val[3];
  cout <<endl;
  // Résultats
  float resx[4];
  float resy[4];
  int k; // Index du résultat
  //initialisation du résultat
  for (k=0; k<4; k++)
  {
    resx[k]=-1;
    resy[k]=-1;
  }

  //Calcul du resultat pour un élément carré
  k=0;
  for (i1=0; i1<4; i1++)
  {
    i2=(i1+1)%4;
    if (val[i1]<p)
    {
      if (val[i2]>=p)
      {
        //Il y a un point entre i1 et i2
        resx[k] = (coorx[i1]+coorx[i2])/2;
        resy[k] = (coory[i1]+coory[i2])/2;
        k++; // Un résultat a été trouvé
      }
    }else
    {
      if (val[i2]<p)
      {
        //Il y a un point entre i1 et i2
        resx[k] = (coorx[i1]+coorx[i2])/2;
        resy[k] = (coory[i1]+coory[i2])/2;
        k++; // Un résultat a été trouvé
      }
    }
  }
  if (k==4)
  {
    float m = (val[0]+val[1]+val[2]+val[3])/4;
    if ((val[0]-p)*(m-p)<0){
      float tmpx = resx[0];
      float tmpy = resy[0];
      for (k=0; k<3; k++)
      {
        resx[k]=resx[k+1];
        resy[k]=resy[k+1];
      }
      k++;
      resx[3]=tmpx;
      resy[3]=tmpy;
    }
  }
  for (k=0; k<4; k++)
    cout << resx[k] << "  " << resy[k] << endl;
}
