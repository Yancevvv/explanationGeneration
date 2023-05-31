#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <QString>

class Exception
{
public:
    Exception(QString message);
    QString getMessage();
protected:
    QString message;
};

#endif // EXCEPTION_H
