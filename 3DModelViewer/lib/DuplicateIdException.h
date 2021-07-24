#ifndef DUPLICATEIDEXCEPTION_H
#define DUPLICATEIDEXCEPTION_H

#include <QException>

class DuplicateIdException : QException
{
    void raise() const override
    {
        throw *this;
    }

    DuplicateIdException *clone() const override
    {
        return new DuplicateIdException(*this);
    }
};

#endif // DUPLICATEIDEXCEPTION_H
