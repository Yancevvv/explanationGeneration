#ifndef TEST_COLLECTDATA_H
#define TEST_COLLECTDATA_H

#include <QtTest/QtTest>
#include <QObject>

class Test_collectData: public QObject
{
    Q_OBJECT
private slots:
    void typical_test();
    void operation_decrement();
    void operand_tag_present();
    void operand_name_attribute_present();
    void negation_operation();
    void multiplication_operation();
    void mod_operation();
    void logical_multiplication_operation();
    void logical_addition_operation();
    void increment_operation();
    void function_arguments_attribute_present();
    void function_args_attribute_contains_many_elements();
    void division_operation();
    void difference_operation();
    void data_type_attribute_present();
};

#endif // TEST_COLLECTDATA_H
