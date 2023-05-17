#include "test_preorder.h"
#include "header.h"
#include "testapi.h"
#include <QtXml>

void Test_preorder::typical_test() {
    QDomDocument doc;
    QFile file("./tests/xml files for tests/preposition_on_division_operation.xml");
    QVector<QString> realResult;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        if(doc.setContent(&file)) {
            QDomElement element = doc.documentElement();
            preorder(element, realResult);
        }
        file.close();
    }
    QVector<QString> expectedResult = {"сумма", "целое число a", "и", "вещественное определитель d"};
    assertArrayEqual(realResult, expectedResult, realResult.length());
}

void Test_preorder::unary_decrement_operation() {
    QDomDocument doc;
    QFile file("./tests/xml files for tests/unary_decrement_operation.xml");
    QVector<QString> realResult;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        if(doc.setContent(&file)) {
            QDomElement element = doc.documentElement();
            preorder(element, realResult);
        }
        file.close();
    }
    QVector<QString> expectedResult = {"декремент", "целое число a"};
    assertArrayEqual(realResult, expectedResult, realResult.length());
}

void Test_preorder::unary_increment_operation() {
    QDomDocument doc;
    QFile file("./tests/xml files for tests/unary_increment_operation.xml");
    QVector<QString> realResult;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        if(doc.setContent(&file)) {
            QDomElement element = doc.documentElement();
            preorder(element, realResult);
        }
        file.close();
    }
    QVector<QString> expectedResult = {"инкремент", "целое число a"};
    assertArrayEqual(realResult, expectedResult, realResult.length());
}

void Test_preorder::unary_operation_negation() {
    QDomDocument doc;
    QFile file("./tests/xml files for tests/unary_operation_negation.xml");
    QVector<QString> realResult;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        if(doc.setContent(&file)) {
            QDomElement element = doc.documentElement();
            preorder(element, realResult);
        }
        file.close();
    }
    QVector<QString> expectedResult = {"отрицание", "целое число a"};
    assertArrayEqual(realResult, expectedResult, realResult.length());
}

void Test_preorder::right_subtree_is_larger_relative_to_the_left_one() {
    QDomDocument doc;
    QFile file("./tests/xml files for tests/right_subtree_is_larger_relative_to_the_left_one.xml");
    QVector<QString> realResult;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        if(doc.setContent(&file)) {
            QDomElement element = doc.documentElement();
            preorder(element, realResult);
        }
        file.close();
    }
    QVector<QString> expectedResult = {"произведение", "сумма", "целое число a", "и", "целое число столбцов b", "и", "вещественное определитель d"};
    assertArrayEqual(realResult, expectedResult, realResult.length());
}

void Test_preorder::preposition_on_division_operation() {
    QDomDocument doc;
    QFile file("./tests/xml files for tests/preposition_on_division_operation.xml");
    QVector<QString> realResult;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        if(doc.setContent(&file)) {
            QDomElement element = doc.documentElement();
            preorder(element, realResult);
        }
        file.close();
    }
    QVector<QString> expectedResult = {"деление", "целое число a", "на", "вещественное определитель d"};
    assertArrayEqual(realResult, expectedResult, realResult.length());
}

void Test_preorder::operation_mod() {
    QDomDocument doc;
    QFile file("./tests/xml files for tests/operation_mod.xml");
    QVector<QString> realResult;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        if(doc.setContent(&file)) {
            QDomElement element = doc.documentElement();
            preorder(element, realResult);
        }
        file.close();
    }
    QVector<QString> expectedResult = {"остаток от целочисленного деления", "целое число a", "на", "вещественное определитель d"};
    assertArrayEqual(realResult, expectedResult, realResult.length());
}

void Test_preorder::operation_logical_multiplication() {
    QDomDocument doc;
    QFile file("./tests/xml files for tests/operation_logical_multiplication.xml");
    QVector<QString> realResult;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        if(doc.setContent(&file)) {
            QDomElement element = doc.documentElement();
            preorder(element, realResult);
        }
        file.close();
    }
    QVector<QString> expectedResult = {"логическое умножение", "целое число a", "и", "вещественное определитель d"};
    assertArrayEqual(realResult, expectedResult, realResult.length());
}

void Test_preorder::operation_logical_addition() {
    QDomDocument doc;
    QFile file("./tests/xml files for tests/operation_logical_addition.xml");
    QVector<QString> realResult;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        if(doc.setContent(&file)) {
            QDomElement element = doc.documentElement();
            preorder(element, realResult);
        }
        file.close();
    }
    QVector<QString> expectedResult = {"логическое сложение", "целое число a", "и", "вещественное определитель d"};
    assertArrayEqual(realResult, expectedResult, realResult.length());
}

void Test_preorder::operation_difference() {
    QDomDocument doc;
    QFile file("./tests/xml files for tests/operation_difference.xml");
    QVector<QString> realResult;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        if(doc.setContent(&file)) {
            QDomElement element = doc.documentElement();
            preorder(element, realResult);
        }
        file.close();
    }
    QVector<QString> expectedResult = {"разность", "целое число a", "и", "вещественное определитель d"};
    assertArrayEqual(realResult, expectedResult, realResult.length());
}

void Test_preorder::operand_name_attribute_is_missing() {
    QDomDocument doc;
    QFile file("./tests/xml files for tests/operand_name_attribute_is_missing.xml");
    QVector<QString> realResult;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        if(doc.setContent(&file)) {
            QDomElement element = doc.documentElement();
            preorder(element, realResult);
        }
        file.close();
    }
    QVector<QString> expectedResult = {"сумма", "целое a", "и", "вещественное d"};
    assertArrayEqual(realResult, expectedResult, realResult.length());
}

void Test_preorder::multiplication_operation() {
    QDomDocument doc;
    QFile file("./tests/xml files for tests/multiplication_operation.xml");
    QVector<QString> realResult;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        if(doc.setContent(&file)) {
            QDomElement element = doc.documentElement();
            preorder(element, realResult);
        }
        file.close();
    }
    QVector<QString> expectedResult = {"произведение", "целое число a", "и", "вещественное определитель d"};
    assertArrayEqual(realResult, expectedResult, realResult.length());
}

void Test_preorder::missing_data_type_attribute() {
    QDomDocument doc;
    QFile file("./tests/xml files for tests/missing_data_type_attribute.xml");
    QVector<QString> realResult;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        if(doc.setContent(&file)) {
            QDomElement element = doc.documentElement();
            preorder(element, realResult);
        }
        file.close();
    }
    QVector<QString> expectedResult = {"сумма", "число a", "и", "определитель d"};
    assertArrayEqual(realResult, expectedResult, realResult.length());
}

void Test_preorder::left_subtree_is_larger_relative_to_the_right_one() {
    QDomDocument doc;
    QFile file("./tests/xml files for tests/left_subtree_is_larger_relative_to_the_right_one.xml");
    QVector<QString> realResult;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        if(doc.setContent(&file)) {
            QDomElement element = doc.documentElement();
            preorder(element, realResult);
        }
        file.close();
    }
    QVector<QString> expectedResult = {"произведение", "целое число a", "и", "разность", "вещественное среднее значение x,y averageValue", "и", "инеремент", "вещественное определитель d"};
    assertArrayEqual(realResult, expectedResult, realResult.length());
}

void Test_preorder::left_and_right_subtrees_are_balanced() {
    QDomDocument doc;
    QFile file("./tests/xml files for tests/left_and_right_subtrees_are_balanced.xml");
    QVector<QString> realResult;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        if(doc.setContent(&file)) {
            QDomElement element = doc.documentElement();
            preorder(element, realResult);
        }
        file.close();
    }
    QVector<QString> expectedResult = {"произведение", "сумма", "целое число a", "и", "целое число столбцов b", "и", "разность", "вещественное среднее значение x,y averageValue", "и", "инеремент", "вещественное определитель d"};
    assertArrayEqual(realResult, expectedResult, realResult.length());
}

void Test_preorder::function() {
    QDomDocument doc;
    QFile file("./tests/xml files for tests/function.xml");
    QVector<QString> realResult;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        if(doc.setContent(&file)) {
            QDomElement element = doc.documentElement();
            preorder(element, realResult);
        }
        file.close();
    }
    QVector<QString> expectedResult = {"сумма", "вещественное среднее значение x,y averageValue", "и", "вещественное определитель d"};
    assertArrayEqual(realResult, expectedResult, realResult.length());
}
