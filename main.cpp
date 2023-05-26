#include <QCoreApplication>
#include <QtXml>
#include "tests/tests.h"
#include <QDebug>

void preorder(const QDomNode &node, QVector<QString> &nodeInformation);
void collectData(const QDomElement &domElement, QVector<QString> &nodeInformation);
void formSentence(QVector<QString> vectorStr, QString &expressionInformation);
QString getGivenWordForm(QString setGivenWords, QString Case);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    runTests();
    return 0;
}

void preorder(const QDomNode &node, QVector<QString> &nodeInformation) {
    QDomElement domElement = node.toElement();
    if(domElement.isNull()) return;
    // Произвести сбор данных в вектор с узла...
    collectData(domElement, nodeInformation);
    // Посетить левый дочерний узел...
    preorder(node.firstChild(), nodeInformation);
    // Добавить в вектор союз или предлог, соответствующий операции (родительскому узлу)
    if (node.parentNode().toElement().tagName() == "operation" and node.parentNode().toElement().attribute("operType") == "/" and !(node.nextSibling().isNull()))
        nodeInformation.append("на");
    else if (node.parentNode().toElement().tagName() == "operation" and !(node.nextSibling().isNull()))
        nodeInformation.append("и");
    // Посетить правый дочерний узел...
    preorder(node.nextSibling(), nodeInformation);
}

void collectData(const QDomElement &domElement, QVector<QString> &nodeInformation) {
    QMap<QString, QString> mapOperation;
    mapOperation["+"] = "сумма";
    mapOperation["-"] = "разность";
    mapOperation["*"] = "произведение";
    mapOperation["/"] = "деление";
    mapOperation["%"] = "остаток от целочисленного деления";
    mapOperation["++"] = "инкремент";
    mapOperation["--"] = "декремент";
    mapOperation["!"] = "отрицание";
    mapOperation["&&"] = "логическое умножение";
    mapOperation["||"] = "логическое сложение";
    // Если элемент узла определен
    if (!domElement.isNull()) {
        if(domElement.tagName() == "operation")
            // Добавить в вектор значение атрибута типа операции, если тег определен, как операция
            nodeInformation.append(mapOperation[domElement.attribute("operType")]);
        // Иначе если тег определен, как операнд
        else if (domElement.tagName() == "operand") {
            // Сформировать строку, содержащую тип данных, название и аргументы тега операнда, если они имеются
            QString operand;
            if (domElement.hasAttribute("dataType"))
                operand.append(domElement.attribute("dataType"));
            if (domElement.hasAttribute("name"))
                operand.append(" " + domElement.attribute("name"));
            if (domElement.hasAttribute("argument"))
                operand.append(" " + domElement.attribute("argument"));
            // Добавить в строку содержимое тега операнда
            operand.append(" " + domElement.text());
            // Добавить сформированную строку в вектор
            nodeInformation.append(operand);
        }
    }
}

void formSentence(QVector<QString> nodeInformation, QString &expressionInformation) {
    // Добавить в строку первое слово из вектора
    expressionInformation.append(nodeInformation[0] + " ");
    // Для каждого элемента вектора, начиная со второго
    for (int i = 1; i < vectorStr.size(); i++) {
        if (vectorStr[i-1] != "на") {
            // Добавить в строку элементы вектора в родительном падеже, если встречен союз «и»...
            QString genitive = getGivenWordForm(vectorStr[i], "gent");
            expressionInformation.append(genitive + " ");
        }
        else if (vectorStr[i-1] == "на") {
            // Иначе если встречен предлог «на», добавить в строку элемент вектора
            // в Р.П. слева от предлога и в В.П. справа от предлога...
            QString accs = getGivenWordForm(vectorStr[i], "accs");
            expressionInformation.append(accs + " ");
        }
    }
}

QString getGivenWordForm(QString setGivenWords, QString Case) {
    return "";
}
