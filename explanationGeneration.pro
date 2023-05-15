QT -= gui

CONFIG += c++17 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
        tests/test_collectData.cpp \
        tests/test_formSentence.cpp \
        tests/test_getGivenWordForm.cpp \
        tests/test_preorder.cpp \
        tests/testapi.cpp \
        tests/tests.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    header.h \
    tests/test_collectData.h \
    tests/test_formSentence.h \
    tests/test_getGivenWordForm.h \
    tests/test_preorder.h \
    tests/testapi.h \
    tests/tests.h
