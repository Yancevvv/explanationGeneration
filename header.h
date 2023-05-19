#ifndef HEADER_H
#define HEADER_H

#include "QVector"
#include <QtXml>

/*! Совершает прямой обход бинарного дерева со сбором данных в формате строк в вектор,
*  а также добавляет союзы и предлоги, в зависимости от операции
* \param[in] node - узел бинарного дерева DOM
* \param[in|out] nodeInformation - вектор строк, содержащий информацию об узлах
*/
void preorder(const QDomNode &node, QVector<QString> &nodeInformation);

/*! Производит сбор данных с узла в формате строки в вектор
* \param[in] domElement - узел бинарного дерева DOM
* \param[in|out] nodeInformation - вектор строк, содержащий информацию об узлах
*/
void collectData(const QDomElement &domElement, QVector<QString> &nodeInformation);

/*! Формирует строку на русском языке, склоняя слова, в зависимости от предлогов или союзов
* \param[in] vectorStr - вектор строк, содержащий информацию об узлах
* \param[out] expressionInformation - сформированная строка с объяснением
*/
void formSentence(QVector<QString> nodeInformation, QString &expressionInformation);

/*! Возвращает слово в заданном падеже
* \param[in] setGivenWords - набор заданных слов
* \param[in] Case – заданный падеж для слов
* \return – строка, содержащая набор слов в заданном падеже
*/
QString getGivenWordForm(QString setGivenWords, QString Case);

#endif // HEADER_H
