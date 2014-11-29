#include "Parser.h"

using namespace libxl;

Parser::Parser() {
}

void Parser::parseFile(int day, int hour) {

    this->stations.clear();
    Station s;
    Book* book1 = xlCreateBook();


    if(book1) {              

        if(book1->load("mesures.xls")) {

            Sheet* sheet1 = book1->getSheet(0);
            if(sheet1) {   

                for (int i = 0; i < 25; i++) {
                    float longitude = sheet1->readNum(i, 0);
                    float latitude = sheet1->readNum(i, 1);
                    float value  = sheet1->readNum(i, 3 + (day - 1)*24 + hour);
                    s = Station(longitude, latitude, value);
                    this->stations.push_back(s);

                    std::cout << "Longitude : " << longitude << " Latitude : " << latitude << " Résultat : " <<  value << std::endl;
                }
            }
        }

        book1->release();   
    }

    Book* book2 = xlCreateBook();

    if(book2) {              

        if(book2->load("mesures.xls")) {

            Sheet* sheet2 = book2->getSheet(0);
            if(sheet2) {   

                for (int i = 25; i < 49; i++) {
                    float longitude = sheet2->readNum(i, 0);
                    float latitude = sheet2->readNum(i, 1);
                    float value  = sheet2->readNum(i, 3 + (day - 1)*24 + hour);
                    s = Station(longitude, latitude, value);
                    this->stations.push_back(s);

                    std::cout << "Longitude : " << longitude << " Latitude : " << latitude << " Résultat : " <<  value << std::endl;
                }
            }
        }

        book2->release();   
    }
}


