/*!
 * \file Файл с точкой входа в программу
 * \brief Содержит главную функцию main, в которой производится чтение входного файла, генерация "объяснения" выражения и запись в выходной файл или вывод ошибки в консоль
 */

#include <QtXml>
#include <QTextStream>
#include "header.h"
#include "exception.h"

int main(int argc, char *argv[])
{
    QString inputArgsError("Input or output files are not specified.");
    QString inputFileError("The input data file is specified incorrectly.");
    QString outputFileError("The output data file is specified incorrectly.");
    QString syntaxXmlError("Error in the syntax of the xml file.");
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
                if (nodeInformation.size() != 0)
                    formSentence(nodeInformation, Result);
                else {
                    error << syntaxXmlError;
                    return 1;
                }
                QFile outFile(argv[2]);
                if (outFile.open(QIODevice::WriteOnly)) {
                    QTextStream out(&outFile);
                    out << Result;
                }
                else {
                    error << outputFileError;
                    return 1;
                }
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
