#ifndef TEST_PREORDER_H
#define TEST_PREORDER_H

#include <QtTest/QtTest>
#include <QObject>

class Test_preorder: public QObject
{
    Q_OBJECT
private slots:
    void typical_test();
    void preposition_on_division_operation();
    void right_subtree_is_larger_relative_to_the_left_one();
    void unary_decrement_operation();
    void unary_increment_operation();
    void unary_operation_negation();
    void operation_mod();
    void operation_logical_multiplication();
    void operation_logical_addition();
    void operation_difference();
    void operand_name_attribute_is_missing();
    void multiplication_operation();
    void missing_data_type_attribute();
    void left_subtree_is_larger_relative_to_the_right_one();
    void left_and_right_subtrees_are_balanced();
    void function();
};

#endif // TEST_PREORDER_H
