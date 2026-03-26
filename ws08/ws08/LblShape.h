#ifndef SENECA_LABELEDSHAPE_H
#define SENECA_LABELEDSHAPE_H
#include "Shape.h"

namespace seneca {

    class LblShape : public Shape {
        char* m_label{};
    protected:
        const char* label() const;
    public:
        LblShape();
        LblShape(const char* label);
        virtual ~LblShape();

        LblShape(const LblShape&) = delete;
        LblShape& operator=(const LblShape&) = delete;

        void getSpecs(std::istream& is);
    };
}
#endif