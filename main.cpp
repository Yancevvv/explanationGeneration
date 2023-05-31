#include <QCoreApplication>
#include <QtXml>
#include "tests/tests.h"
#include <QDebug>
#include <exception.h>
#include <QTextStream>

void preorder(const QDomNode &node, QVector<QString> &nodeInformation);
void collectData(const QDomElement &domElement, QVector<QString> &nodeInformation);
void formSentence(QVector<QString> vectorStr, QString &expressionInformation);
QString getGivenWordForm(QString setGivenWords, QString Case);

int main(int argc, char *argv[])
{
    QString inputArgsError("Input or output files are not specified.");
    QString inputFileError("The input data file is specified incorrectly.");
    QString outputFileError("The output data file is specified incorrectly.");
    QTextStream error(stdout);
    try {
        if (argc < 3) {
            error << inputArgsError;
            return 1;
        }
        else {
            QString fileName(argv[1]);
            QFile inputFile(fileName);
            if (inputFile.exists()) {
                QDomDocument doc;
                QVector<QString> nodeInformation;
                QString Result;
                if(inputFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
                    if(doc.setContent(&inputFile)) {
                        QDomElement element = doc.documentElement();
                        preorder(element, nodeInformation);
                    }
                    inputFile.close();
                }
                formSentence(nodeInformation, Result);
                QFile outFile(argv[2]);
                if (outFile.open(QIODevice::WriteOnly)) {
                    QTextStream out(&outFile);
                    out << Result;
                }
                else {
                    error << outputFileError;
                    return 1;
                }
                //runTests();
                return 0;
            }
            else {
                error << inputFileError;
                return 1;
            }
        }
    }
    catch (Exception exception) {
        error << exception.getMessage();
        return 1;
    }
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
    for (int i = 1; i < nodeInformation.size(); i++) {
        if (nodeInformation[i-1] != "на") {
            // Добавить в строку элементы вектора в родительном падеже, если встречен союз «и»...
            QString genitive = getGivenWordForm(nodeInformation[i], "gent");
            expressionInformation.append(genitive + " ");
        }
        else if (nodeInformation[i-1] == "на") {
            // Иначе если встречен предлог «на», добавить в строку элемент вектора
            // в Р.П. слева от предлога и в В.П. справа от предлога...
            QString accs = getGivenWordForm(nodeInformation[i], "accs");
            expressionInformation.append(accs + " ");
        }
    }
    expressionInformation.chop(1);
}

QString getGivenWordForm(QString setGivenWords, QString Case) {
    // Разбить строку на слова, пропустив разделители
    QStringList lstStr = setGivenWords.split(" ");
    lstStr.insert(0, Case);
    // Запустить процесс выполнения скрипта, разработанного с использованием языка программирования python и библиотеки pymorphy2
    QProcess proc;
    proc.start("main.exe", lstStr);
    proc.waitForFinished();
    // Прочитать полученную строку из консоли
    QByteArray output = proc.readAllStandardOutput();
    // Завершить процесс
    proc.close();
    // Возвратить строку, содержащую набор слов в заданном падеже
    return QString::fromLocal8Bit(output);
}
