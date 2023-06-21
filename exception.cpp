/*!
 * \file
 * \brief Файл с реализацией исключений, необходимых для программы
 */

#include "Exception.h"

Exception::Exception(QString message)
{
    this->message = message;
}

QString Exception::getMessage() {
    return this->message;
}

InvalidOperandCountException::InvalidOperandCountException(QString message) : Exception(message) {}

InvalidOperationException::InvalidOperationException(QString message) : Exception(message) {}

InvalidTagException::InvalidTagException(QString message) : Exception(message) {}
