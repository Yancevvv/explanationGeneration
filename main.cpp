#include <QCoreApplication>
#include <QtXml/qdom.h>

void preorder(const QDomNode &node, QVector<QString> &nodeInformation);
void collectData(const QDomElement &domElement, QVector<QString> &nodeInformation);
void formSentence(QVector<QString> vectorStr, QString &expressionInformation);
QString getGivenWordForm(QString setGivenWords, QString Case);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}

void preorder(const QDomNode &node, QVector<QString> &nodeInformation) {

}

void collectData(const QDomElement &domElement, QVector<QString> &nodeInformation) {

}

void formSentence(QVector<QString> vectorStr, QString &expressionInformation) {

}

QString getGivenWordForm(QString setGivenWords, QString Case) {
    return "";
}
