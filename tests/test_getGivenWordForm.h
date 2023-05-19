#ifndef TEST_GETGIVENWORDFORM_H
#define TEST_GETGIVENWORDFORM_H

#include <QtTest/QtTest>
#include <QObject>

class Test_getGivenWordForm: public QObject
{
    Q_OBJECT
private slots:
    void nominativeCase();
    void genitive();
    void dative();
    void accusative();
    void ablative();
    void prepositional();
};

#endif // TEST_GETGIVENWORDFORM_H
