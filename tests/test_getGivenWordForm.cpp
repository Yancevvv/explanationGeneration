#include "test_getGivenWordForm.h"
#include "header.h"

void Test_getGivenWordForm::nominativeCase() {
    QString setGivenWords = "число";
    QString expectedResult = "число";
    QString realResult = getGivenWordForm(setGivenWords, "nomn");
    QCOMPARE(realResult, expectedResult);
}

void Test_getGivenWordForm::genitive() {
    QString setGivenWords = "число";
    QString expectedResult = "числа";
    QString realResult = getGivenWordForm(setGivenWords, "gent");
    QCOMPARE(realResult, expectedResult);
}

void Test_getGivenWordForm::dative() {
    QString setGivenWords = "число";
    QString expectedResult = "числу";
    QString realResult = getGivenWordForm(setGivenWords, "datv");
    QCOMPARE(realResult, expectedResult);
}

void Test_getGivenWordForm::accusative() {
    QString setGivenWords = "число";
    QString expectedResult = "число";
    QString realResult = getGivenWordForm(setGivenWords, "accs");
    QCOMPARE(realResult, expectedResult);
}

void Test_getGivenWordForm::ablative() {
    QString setGivenWords = "число";
    QString expectedResult = "числом";
    QString realResult = getGivenWordForm(setGivenWords, "ablt");
    QCOMPARE(realResult, expectedResult);
}

void Test_getGivenWordForm::prepositional() {
    QString setGivenWords = "число";
    QString expectedResult = "числе";
    QString realResult = getGivenWordForm(setGivenWords, "loct");
    QCOMPARE(realResult, expectedResult);
}
