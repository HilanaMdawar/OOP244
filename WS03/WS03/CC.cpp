/*************************************************************************************
* OOP244 - 2261
*
* Student Name : Hilana Mdawar
* Student Email : hmdawar@myseneca.ca
* Workshop #  : 3
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

#include <iostream>
#include "CC.h"
#include "cstr.h"

using namespace std;

namespace seneca {

    void CC::deallocate() {
        delete[] m_name;
        m_name = nullptr;
    }

    void CC::aloCopy(const char* name) {
        int len = strLen(name);
        m_name = new char[len + 1];
        strCpy(m_name, name);
    }

    void CC::display(const char* name, unsigned long long number,
        short expYear, short expMon, short cvv) const {

        char lname[31]{};
        strcpy(lname, name, 30);

        cout << "| ";
        cout.width(30);
        cout.fill(' ');
        cout.setf(ios::left);
        cout << lname << " | ";
        prnNumber(number);
        cout << " | " << cvv << " | ";
        cout.unsetf(ios::left);
        cout.setf(ios::right);
        cout.width(2);
        cout << expMon << "/" << expYear << " |" << endl;
        cout.unsetf(ios::right);
    }

    bool CC::validate(const char* name,
        unsigned long long cardNo,
        short cvv,
        short expMon,
        short expYear) const {

        if (!name || strLen(name) <= 2) return false;
        if (cardNo < 4000000000000000ull || cardNo > 4099999999999999ull) return false;
        if (cvv < 100 || cvv > 999) return false;
        if (expMon < 1 || expMon > 12) return false;
        if (expYear < 24 || expYear > 32) return false;

        return true;
    }

    void CC::prnNumber(unsigned long long CCnum) const {
        unsigned long long p1 = CCnum / 1000000000000ull;
        unsigned long long r1 = CCnum % 1000000000000ull;
        unsigned long long p2 = r1 / 100000000ull;
        unsigned long long r2 = r1 % 100000000ull;
        unsigned long long p3 = r2 / 10000ull;
        unsigned long long p4 = r2 % 10000ull;

        cout << p1 << ' ';
		cout.setf(ios::right);
        cout.width(4); cout.fill('0'); cout << p2 << ' ';
        cout.width(4); cout.fill('0'); cout << p3 << ' ';
        cout.width(4); cout.fill('0'); cout << p4;
        cout.fill(' ');
		cout.unsetf(ios::right);
    }

    void CC::set() {
        deallocate();
        m_number = 0;
        m_cvv = 0;
        m_expMon = 0;
        m_expYear = 0;
    }

    bool CC::isEmpty() const {
        return m_name == nullptr;
    }

    void CC::set(const char* cc_name,
        unsigned long long cc_no,
        short cvv,
        short expMon,
        short expYear) {

        set();

        if (validate(cc_name, cc_no, cvv, expMon, expYear)) {
            aloCopy(cc_name);
            m_number = cc_no;
            m_cvv = cvv;
            m_expMon = expMon;
            m_expYear = expYear;
        }
    }

    void CC::display() const {
        if (isEmpty()) {
            cout << "Invalid Credit Card Record" << endl;
        }
        else {
            display(m_name, m_number, m_expYear, m_expMon, m_cvv);
        }
    }

    CC::CC() {
        m_name = nullptr;
        set();
    }

    CC::CC(const char* cc_name,
        unsigned long long cc_no,
        short cvv,
        short expMon,
        short expYear) {

        m_name = nullptr;
        set();

        if (validate(cc_name, cc_no, cvv, expMon, expYear)) {
            aloCopy(cc_name);
            m_number = cc_no;
            m_cvv = cvv;
            m_expMon = expMon;
            m_expYear = expYear;
        }
    }

    CC::CC(const CC& src) {
        m_name = nullptr;
        *this = src;
    }

    CC& CC::operator=(const CC& src) {
        if (this != &src) {
            set();
            if (!src.isEmpty()) {
                aloCopy(src.m_name);
                m_number = src.m_number;
                m_cvv = src.m_cvv;
                m_expMon = src.m_expMon;
                m_expYear = src.m_expYear;
            }
        }
        return *this;
    }

    CC::~CC() {
        deallocate();
    }

}