/*!
 * \file
 * \brief Основные исключения, необходимые для работы программы
 */

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

class InvalidOperandCountException : public Exception {
public:
    InvalidOperandCountException(QString message);
};

class InvalidOperationException : public Exception {
public:
    InvalidOperationException(QString message);
};

class InvalidTagException : public Exception {
public:
    InvalidTagException(QString message);
};

#endif // EXCEPTION_H
