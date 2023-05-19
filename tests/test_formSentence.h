#ifndef TEST_FORMSENTENCE_H
#define TEST_FORMSENTENCE_H

#include <QtTest/QtTest>
#include <QObject>

class Test_formSentence: public QObject
{
    Q_OBJECT
private slots:
    void typical_test();
    void operandsAreCombinedWithOn();
    void operandIsDescribedBySeveralWords();
    void setOfWordsContainsLatinCharacters();
    void oneOperand();
    void moreThanTwoOperands();
    void moreThanTwoOperations();
};

#endif // TEST_FORMSENTENCE_H
