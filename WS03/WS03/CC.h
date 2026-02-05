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

#ifndef SENECA_CC_H
#define SENECA_CC_H

namespace seneca {

    class CC {
        char* m_name{};
        short m_cvv{};
        short m_expMon{};
        short m_expYear{};
        unsigned long long m_number{};

        void aloCopy(const char* name);
        void deallocate();

        void display(const char* name,
            unsigned long long number,
            short expYear,
            short expMon,
            short cvv) const;

        bool validate(const char* name,
            unsigned long long cardNo,
            short cvv,
            short expMon,
            short expYear) const;

        void prnNumber(unsigned long long CCnum) const;

    public:
        CC();
        CC(const char* cc_name,
            unsigned long long cc_no,
            short cvv,
            short expMon = 12,
            short expYear = 26);

        CC(const CC& src);
        CC& operator=(const CC& src);
        ~CC();

        void set();
        bool isEmpty() const;

        void set(const char* cc_name,
            unsigned long long cc_no,
            short cvv,
            short expMon,
            short expYear);

        void display() const;
    };

}

#endif