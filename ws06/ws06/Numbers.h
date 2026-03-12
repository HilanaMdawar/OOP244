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
