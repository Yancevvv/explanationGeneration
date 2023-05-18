#include "test_collectData.h"
#include "header.h"
#include "testapi.h"
#include <QtXml>

void Test_collectData::typical_test() {
    QDomDocument doc;
    QFile file("./tests/xml_files_for_tests_collectData/typical_test.xml");
    QVector<QString> realResult;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        if(doc.setContent(&file)) {
            QDomElement element = doc.documentElement();
            element = element.toElement();
            collectData(element, realResult);
        }
        file.close();
    }
    QVector<QString> expectedResult = {"сумма"};
    assertArrayEqual(realResult, expectedResult, realResult.length());
}

void Test_collectData::operation_decrement() {
    QDomDocument doc;
    QFile file("./tests/xml_files_for_tests_collectData/operation_decrement.xml");
    QVector<QString> realResult;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        if(doc.setContent(&file)) {
            QDomElement element = doc.documentElement();
            element = element.toElement();
            collectData(element, realResult);
        }
        file.close();
    }
    QVector<QString> expectedResult = {"декремент"};
    assertArrayEqual(realResult, expectedResult, realResult.length());
}

void Test_collectData::operand_tag_present() {
    QDomDocument doc;
    QFile file("./tests/xml_files_for_tests_collectData/operand_tag_present.xml");
    QVector<QString> realResult;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        if(doc.setContent(&file)) {
            QDomElement element = doc.documentElement();
            element = element.toElement();
            collectData(element, realResult);
        }
        file.close();
    }
    QVector<QString> expectedResult = {"d"};
    assertArrayEqual(realResult, expectedResult, realResult.length());
}

void Test_collectData::operand_name_attribute_present() {
    QDomDocument doc;
    QFile file("./tests/xml_files_for_tests_collectData/operand_name_attribute_present.xml");
    QVector<QString> realResult;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        if(doc.setContent(&file)) {
            QDomElement element = doc.documentElement();
            element = element.toElement();
            collectData(element, realResult);
        }
        file.close();
    }
    QVector<QString> expectedResult = {"вещественный определитель d"};
    assertArrayEqual(realResult, expectedResult, realResult.length());
}

void Test_collectData::negation_operation() {
    QDomDocument doc;
    QFile file("./tests/xml_files_for_tests_collectData/negation_operation.xml");
    QVector<QString> realResult;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        if(doc.setContent(&file)) {
            QDomElement element = doc.documentElement();
            element = element.toElement();
            collectData(element, realResult);
        }
        file.close();
    }
    QVector<QString> expectedResult = {"отрицание"};
    assertArrayEqual(realResult, expectedResult, realResult.length());
}

void Test_collectData::multiplication_operation() {
    QDomDocument doc;
    QFile file("./tests/xml_files_for_tests_collectData/multiplication_operation.xml");
    QVector<QString> realResult;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        if(doc.setContent(&file)) {
            QDomElement element = doc.documentElement();
            element = element.toElement();
            collectData(element, realResult);
        }
        file.close();
    }
    QVector<QString> expectedResult = {"произведение"};
    assertArrayEqual(realResult, expectedResult, realResult.length());
}

void Test_collectData::mod_operation() {
    QDomDocument doc;
    QFile file("./tests/xml_files_for_tests_collectData/mod_operation.xml");
    QVector<QString> realResult;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        if(doc.setContent(&file)) {
            QDomElement element = doc.documentElement();
            element = element.toElement();
            collectData(element, realResult);
        }
        file.close();
    }
    QVector<QString> expectedResult = {"остаток от целочисленного деления"};
    assertArrayEqual(realResult, expectedResult, realResult.length());
}

void Test_collectData::logical_multiplication_operation() {
    QDomDocument doc;
    QFile file("./tests/xml_files_for_tests_collectData/logical_multiplication_operation.xml");
    QVector<QString> realResult;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        if(doc.setContent(&file)) {
            QDomElement element = doc.documentElement();
            element = element.toElement();
            collectData(element, realResult);
        }
        file.close();
    }
    QVector<QString> expectedResult = {"логическое умножение"};
    assertArrayEqual(realResult, expectedResult, realResult.length());
}

void Test_collectData::logical_addition_operation() {
    QDomDocument doc;
    QFile file("./tests/xml_files_for_tests_collectData/logical_addition_operation.xml");
    QVector<QString> realResult;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        if(doc.setContent(&file)) {
            QDomElement element = doc.documentElement();
            element = element.toElement();
            collectData(element, realResult);
        }
        file.close();
    }
    QVector<QString> expectedResult = {"логическое сложение"};
    assertArrayEqual(realResult, expectedResult, realResult.length());
}

void Test_collectData::increment_operation() {
    QDomDocument doc;
    QFile file("./tests/xml_files_for_tests_collectData/increment_operation.xml");
    QVector<QString> realResult;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        if(doc.setContent(&file)) {
            QDomElement element = doc.documentElement();
            element = element.toElement();
            collectData(element, realResult);
        }
        file.close();
    }
    QVector<QString> expectedResult = {"инкремент"};
    assertArrayEqual(realResult, expectedResult, realResult.length());
}

void Test_collectData::function_arguments_attribute_present() {
    QDomDocument doc;
    QFile file("./tests/xml_files_for_tests_collectData/function_arguments_attribute_present.xml");
    QVector<QString> realResult;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        if(doc.setContent(&file)) {
            QDomElement element = doc.documentElement();
            element = element.toElement();
            collectData(element, realResult);
        }
        file.close();
    }
    QVector<QString> expectedResult = {"вещественное среднее значение x, y averageValue"};
    assertArrayEqual(realResult, expectedResult, realResult.length());
}

void Test_collectData::function_args_attribute_contains_many_elements() {
    QDomDocument doc;
    QFile file("./tests/xml_files_for_tests_collectData/function_args_attribute_contains_many_elements.xml");
    QVector<QString> realResult;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        if(doc.setContent(&file)) {
            QDomElement element = doc.documentElement();
            element = element.toElement();
            collectData(element, realResult);
        }
        file.close();
    }
    QVector<QString> expectedResult = {"вещественное математическое ожидание x1,x2,x3,x4,x5,x6,x7 expectedValue"};
    assertArrayEqual(realResult, expectedResult, realResult.length());
}

void Test_collectData::division_operation() {
    QDomDocument doc;
    QFile file("./tests/xml_files_for_tests_collectData/division_operation.xml");
    QVector<QString> realResult;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        if(doc.setContent(&file)) {
            QDomElement element = doc.documentElement();
            element = element.toElement();
            collectData(element, realResult);
        }
        file.close();
    }
    QVector<QString> expectedResult = {"деление"};
    assertArrayEqual(realResult, expectedResult, realResult.length());
}

void Test_collectData::difference_operation() {
    QDomDocument doc;
    QFile file("./tests/xml_files_for_tests_collectData/difference_operation.xml");
    QVector<QString> realResult;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        if(doc.setContent(&file)) {
            QDomElement element = doc.documentElement();
            element = element.toElement();
            collectData(element, realResult);
        }
        file.close();
    }
    QVector<QString> expectedResult = {"разность"};
    assertArrayEqual(realResult, expectedResult, realResult.length());
}

void Test_collectData::data_type_attribute_present() {
    QDomDocument doc;
    QFile file("./tests/xml_files_for_tests_collectData/data_type_attribute_present.xml");
    QVector<QString> realResult;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        if(doc.setContent(&file)) {
            QDomElement element = doc.documentElement();
            element = element.toElement();
            collectData(element, realResult);
        }
        file.close();
    }
    QVector<QString> expectedResult = {"вещественный d"};
    assertArrayEqual(realResult, expectedResult, realResult.length());
}
