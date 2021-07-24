#ifndef UNSUPPORTEDSHAPEEXCEPTION_H
#define UNSUPPORTEDSHAPEEXCEPTION_H

#include <QException>

class UnsupportedShapeException : QException
{
    void raise() const override
    {
        throw *this;
    }

    UnsupportedShapeException *clone() const override
    {
        return new UnsupportedShapeException(*this);
    }
};

#endif // UNSUPPORTEDSHAPEEXCEPTION_H
