#ifndef SENECA_RECTANGLE_H
#define SENECA_RECTANGLE_H
#include "LblShape.h"

namespace seneca {

    class Rectangle : public LblShape {
        int m_width{};
        int m_height{};
    public:
        Rectangle();
        Rectangle(const char* label, int width, int height);

        void draw(std::ostream& os) const;
        void getSpecs(std::istream& is);
    };

}
#endif