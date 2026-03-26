#include <iostream>
#include "Professor.h"
#include "Utils.h"

using namespace std;
namespace seneca {

    double Professor::devPay() const {
        // 1% of salary multiplied by number of sections 
        return (salary() * 0.01) * m_sections;
    }

    Professor::Professor() : Employee() {}

    Professor::Professor(const char* name, const char* subject, int sections, size_t empNo, double salary)
        : Employee(name, empNo, salary), m_sections(sections) {
        if (subject) m_subject = ut.alocpy(subject); // Use Utils for allocation [cite: 3, 4]
    }

    Professor::~Professor() {
        delete[] m_subject;
    }

    ostream& Professor::title(ostream& ostr) const {
        Employee::title(ostr); // Call base title 
        ostr << " Teaching Subject     | Sec # | $Dev Pay |";
        return ostr;
    }

    istream& Professor::read(istream& istr) {
        char buffer[1024];

        // 1. Read base data: Name, EmpNo, Salary [cite: 6, 8]
        Employee::read(istr);

        // 2. Clear the comma left in the buffer after salary 
        istr.ignore();

        // 3. Read subject name up to the next comma 
        istr.getline(buffer, 1024, ',');
        ut.alocpy(m_subject, buffer);

        // 4. Read number of sections 
        istr >> m_sections;

        return istr;
    }

    ostream& Professor::write(ostream& ostr) const {
        // 1. Starts with a leading space 
        ostr << " ";

        // 2. Base Employee output [cite: 6, 8]
        Employee::write(ostr);

        // 3. Subject: first 20 chars, left-justified 
        char subPrint[21]{};
        if (m_subject) ut.strcpy(subPrint, m_subject, 20);
        ostr.width(20);
        ostr.setf(ios::left);
        ostr << subPrint << " | ";
        ostr.unsetf(ios::left);

        // 4. Sections: 5 spaces, right-justified 
        ostr.width(5);
        ostr.setf(ios::right);
        ostr << m_sections << " | ";

        // 5. DevPay: 8 spaces, 2 decimal places 
        ostr.width(8);
        ostr.setf(ios::fixed);
        ostr.precision(2);
        ostr << devPay() << " |";
        ostr.unsetf(ios::right);

        return ostr;
    }

    ostream& operator<<(ostream& ostr, const Professor& P) {
        return P.write(ostr);
    }

    istream& operator>>(istream& istr, Professor& P) {
        return P.read(istr);
    }
}