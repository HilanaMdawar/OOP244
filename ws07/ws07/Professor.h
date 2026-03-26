#ifndef SENECA_PROFESSOR_H
#define SENECA_PROFESSOR_H
#include "Employee.h"

namespace seneca {
    class Professor : public Employee {
        char* m_subject{};
        int m_sections{};
        double devPay() const; // Private helper for calculation 

    public:
        Professor();
        Professor(const char* name, const char* subject, int sections, size_t empNo, double salary);
        ~Professor();

        // Shadowing/Overriding base class methods 
        std::ostream& title(std::ostream& ostr = std::cout) const;
        std::ostream& write(std::ostream& ostr = std::cout) const;
        std::istream& read(std::istream& istr = std::cin);

        // Disable copying to manage dynamic memory safely [cite: 5]
        Professor(const Professor&) = delete;
        Professor& operator=(const Professor&) = delete;
    };

    // Helper operators 
    std::ostream& operator<<(std::ostream& ostr, const Professor& P);
    std::istream& operator>>(std::istream& istr, Professor& P);
}
#endif