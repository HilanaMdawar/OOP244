/***********************************************************************
// OOP244 Workshop 7 lab: Professor
//
// File  Professor.cpp
//
// Author: Hilana Mdawar
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Professor.h"
#include "Utils.h"

using namespace std;

namespace seneca {

    Professor::Professor() : Employee() {
        m_subject = nullptr;
        m_section = 0;
        m_devPay = 0;
    }

    void Professor::setDevPay() {
        m_devPay = salary() * 0.01 * m_section;
    }

    Professor::Professor(const char* name, const char* subject, int section, size_t empNo, double sal)
        : Employee(name, empNo, sal) {

        ut.alocpy(m_subject, subject);
        m_section = section;
        setDevPay();
    }

    Professor::~Professor() {
        delete[] m_subject;
    }

    // 🔥 FIXED READ FUNCTION
    istream& Professor::read(istream& istr) {
        char name[1024];
        char subject[1024];

        // name
        istr.getline(name, 1024, ',');
        ut.alocpy(m_name, name);

        // employee number
        istr >> m_employeeNo;
        istr.ignore();

        // salary
        istr >> m_salary;
        istr.ignore();

        // subject
        istr.getline(subject, 1024, ',');
        ut.alocpy(m_subject, subject);

        // section
        istr >> m_section;

        setDevPay();

        return istr;
    }

    ostream& Professor::write(ostream& ostr) const {
        Employee::write(ostr);

        char subject2print[26]{};
        ut.strcpy(subject2print, m_subject, 25);

        ostr << " ";
        ostr.width(25);
        ostr.setf(ios::left);
        ostr << subject2print << " | ";

        ostr.unsetf(ios::left);
        ostr.width(5);
        ostr << m_section << " | ";

        ostr.width(8);
        ostr.setf(ios::fixed);
        ostr.precision(2);
        ostr << m_devPay << " |";

        return ostr;
    }

    ostream& Professor::title(ostream& ostr) const {
        Employee::title(ostr);
        return ostr << " Teaching Subject     | Sec # | $Dev Pay |";
    }

    // operators
    ostream& operator<<(ostream& ostr, const Professor& P) {
        return P.write(ostr);
    }

    istream& operator>>(istream& istr, Professor& P) {
        return P.read(istr);
    }

}