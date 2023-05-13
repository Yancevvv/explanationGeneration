#include "tests.h"

void runTests(){
    QTest::qExec(new Test_preorder);
    QTest::qExec(new Test_collectData);
    QTest::qExec(new Test_formSentence);
    QTest::qExec(new Test_getGivenWordForm);
}
