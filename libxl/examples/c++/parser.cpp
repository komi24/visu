#include <iostream>
#include "libxl/include_cpp/libxl.h"

using namespace libxl;

int main() 
{
    Book* book = xlCreateBook();
    if(book) 
    {                
        if(book->load("ParticulePM10Aout2012.xls"))
        {
            Sheet* sheet = book->getSheet(0);
            if(sheet) 
            {   
                double d = sheet->readNum(16, 2);
                std::cout << d << std::endl;
            }
        }

        book->release();   
    }

    return 0;
}

