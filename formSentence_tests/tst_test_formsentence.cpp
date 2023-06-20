#include <QtTest>
#include "../header.h"

class Test_formSentence : public QObject
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

void Test_formSentence::typical_test() {
    QVector<QString> information = {"сумма", "число", "и", "определитель"};
    QString realResult;
    QString expectedResult = "сумма числа и определителя";
    formSentence(information, realResult);
    QCOMPARE(realResult, expectedResult);
}

void Test_formSentence::operandsAreCombinedWithOn() {
    QVector<QString> information = {"деление", "число", "на", "определитель"};
    QString realResult;
    QString expectedResult = "деление числа на определитель";
    formSentence(information, realResult);
    QCOMPARE(realResult, expectedResult);
}

void Test_formSentence::operandIsDescribedBySeveralWords() {
    QVector<QString> information = {"деление", "целое число", "на", "вещественное математическое ожидание"};
    QString realResult;
    QString expectedResult = "деление целого числа на вещественное математическое ожидание";
    formSentence(information, realResult);
    QCOMPARE(realResult, expectedResult);
}

void Test_formSentence::setOfWordsContainsLatinCharacters() {
    QVector<QString> information = {"деление", "целое число", "на", "вещественное математическое ожидание m"};
    QString realResult;
    QString expectedResult = "деление целого числа на вещественное математическое ожидание m";
    formSentence(information, realResult);
    QCOMPARE(realResult, expectedResult);
}

void Test_formSentence::oneOperand() {
    QVector<QString> information = {"инкремент", "целое число x"};
    QString realResult;
    QString expectedResult = "инкремент целого числа x";
    formSentence(information, realResult);
    QCOMPARE(realResult, expectedResult);
}

void Test_formSentence::moreThanTwoOperands() {
    QVector<QString> information = {"произведение", "сумма", "целое число a", "и", "целое число столбцов b", "и", "вещественное определитель d"};
    QString realResult;
    QString expectedResult = "произведение суммы целого числа a и целого числа столбцов b и вещественного определителя d";
    formSentence(information, realResult);
    QCOMPARE(realResult, expectedResult);
}

void Test_formSentence::moreThanTwoOperations() {
    QVector<QString> information = {"произведение", "сумма", "целое число a", "и", "целое число столбцов b", "и", "разность", "вещественное среднее значение x,y averageValue", "и", "инкремент", "вещественное определитель d"};
    QString realResult;
    QString expectedResult = "произведение суммы целого числа a и целого числа столбцов b и разности вещественного среднего значения x,y averageValue и инкремента вещественного определителя d";
    formSentence(information, realResult);
    QCOMPARE(realResult, expectedResult);
}

QTEST_APPLESS_MAIN(Test_formSentence)

#include "tst_test_formsentence.moc"
