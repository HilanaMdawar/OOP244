/*************************************************************************************
* OOP244 - 2261
*
* Student Name : Hilana Mdawar
* Student Email : hmdawar@myseneca.ca
* Workshop #  : 6
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
#ifndef SENECA_NUMBERS_H
#define SENECA_NUMBERS_H

#include <iostream>

namespace seneca {

    class Numbers {
        double* m_numbers;
        char* m_filename;
        bool m_isOriginal;
        size_t m_numCount;

        bool isEmpty() const;
        void setEmpty();
        void setFilename(const char* filename);
        void sort();

        size_t numberCount() const;
        bool load();
        void save() const;

    public:
        Numbers();
        Numbers(const char* filename);

        ~Numbers();
        Numbers(const Numbers& other);
        Numbers& operator=(const Numbers& other);

        Numbers& operator+=(double value);

        double average() const;
        double max() const;
        double min() const;

        std::ostream& display(std::ostream& ostr) const;
    };

    std::ostream& operator<<(std::ostream& os, const Numbers& N);
    std::istream& operator>>(std::istream& istr, Numbers& N);

}

#endif
