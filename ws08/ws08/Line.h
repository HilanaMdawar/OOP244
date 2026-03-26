
/*************************************************************************************
* OOP244 - 2261
*
* Student Name :hilana mdawar
* Student Email : hmdawar@myseneca.ca
* Workshop #  :8
* Course/Section: OOP244/NRA
*
* I declare that this assignment is my own work in accordance with the Seneca Academic
* Policy. No part of this assignment has been copied manually or electronically from/to
* any other source (including web sites) or distributed to other students.
*
* I have done all the coding by myself and only copied the code that my professor
* provided to complete my workshops and assignments.
*
**************************************************************************************/#ifndef SENECA_LINE_H
#define SENECA_LINE_H
#include "LblShape.h"

namespace seneca {

    class Line : public LblShape {
        int m_length{};
    public:
        Line();
        Line(const char* label, int length);

        void draw(std::ostream& os) const;
        void getSpecs(std::istream& is);
    };

}
#endif