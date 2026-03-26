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
* i have also used chat gpt and co pilot in some sections because i was having a hard time understanding the requirements and how to implement them, but i have made sure to understand the code and how it works, and i have also made some modifications to the code to fit the requirements of the assignment.
*
**************************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Numbers.h"

using namespace std;

namespace seneca {

    Numbers::~Numbers() {
        save();
        delete[] m_numbers;
        delete[] m_filename;
    }

    Numbers::Numbers(const Numbers& src) {
        setEmpty();
        m_isOriginal = false;

        if (!src.isEmpty()) {
            m_numCount = src.m_numCount;
            m_numbers = new double[m_numCount];

            for (int i = 0; i < m_numCount; i++) {
                m_numbers[i] = src.m_numbers[i];
            }
        }
    }

    Numbers& Numbers::operator=(const Numbers& src) {

        if (this != &src) {

            delete[] m_numbers;

            if (!src.isEmpty()) {

                m_numCount = src.m_numCount;
                m_numbers = new double[m_numCount];

                for (int i = 0; i < m_numCount; i++) {
                    m_numbers[i] = src.m_numbers[i];
                }
            }
            else {
                setEmpty();
            }
        }

        return *this;
    }

    int Numbers::numberCount() const {

        ifstream file(m_filename);
        int count = 0;
        char ch;

        while (file.get(ch)) {
            if (ch == '\n') count++;
        }

        return count;
    }

    bool Numbers::load() {

        if (m_numCount == 0) return false;

        ifstream file(m_filename);
        m_numbers = new double[m_numCount];

        int i = 0;

        while (file >> m_numbers[i]) {
            i++;
            if (i == m_numCount) break;
        }

        if (i != m_numCount) {
            delete[] m_numbers;
            setEmpty();
            return false;
        }

        return true;
    }

    void Numbers::save() const {

        if (m_isOriginal && !isEmpty()) {

            ofstream file(m_filename);

            for (int i = 0; i < m_numCount; i++) {
                file << m_numbers[i] << endl;
            }
        }
    }

    Numbers& Numbers::operator+=(double value) {

        if (!isEmpty()) {

            double* temp = new double[m_numCount + 1];

            for (int i = 0; i < m_numCount; i++) {
                temp[i] = m_numbers[i];
            }

            temp[m_numCount] = value;
            m_numCount++;

            delete[] m_numbers;
            m_numbers = temp;

            sort();
        }

        return *this;
    }

    ostream& Numbers::display(ostream& ostr) const {

        if (isEmpty()) {

            ostr << "Empty list";

        }
        else {

            ostr << "=========================" << endl;

            if (m_isOriginal)
                ostr << m_filename << endl;
            else
                ostr << "*** COPY ***" << endl;

            ostr.setf(ios::fixed);
            ostr.precision(2);

            for (int i = 0; i < m_numCount; i++) {

                ostr << m_numbers[i];

                if (i != m_numCount - 1)
                    ostr << ", ";
            }

            ostr << endl;

            ostr << "-------------------------" << endl;

            ostr << "Total of " << m_numCount << " number(s)" << endl;

            ostr << "Largest number:  " << max() << endl;
            ostr << "Smallest number: " << min() << endl;
            ostr << "Average:         " << average() << endl;

            ostr << "=========================";
        }

        return ostr;
    }

    ostream& operator<<(ostream& os, const Numbers& N) {
        return N.display(os);
    }

    istream& operator>>(istream& istr, Numbers& N) {

        double value;

        istr >> value;

        if (istr) {
            N += value;
        }

        return istr;
    }

}