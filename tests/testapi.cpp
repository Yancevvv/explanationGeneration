#include "tests/testapi.h"
#include <QtTest/QtTest>

void assertArrayEqual(QVector<QString> realArray, QVector<QString> expectedArray, int length) {
    for (int i = 0; i < length; i++) {
        QCOMPARE(realArray[i], expectedArray[i]);
    }
}
