#include "Exception.h"

Exception::Exception(QString message)
{
    this->message = message;
}

QString Exception::getMessage() {
    return this->message;
}
