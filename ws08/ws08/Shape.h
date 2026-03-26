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
**************************************************************************************/
#ifndef SENECA_SHAPE_H
#define SENECA_SHAPE_H
#include <iostream>

namespace seneca {

    class Shape {
    public:
        virtual void draw(std::ostream& os) const = 0;
        virtual void getSpecs(std::istream& is) = 0;
        virtual ~Shape() {};
    };

    std::ostream& operator<<(std::ostream& os, const Shape& S);
    std::istream& operator>>(std::istream& is, Shape& S);

}
#endif