QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add1.cpp \
    building.cpp \
    data.cpp \
    distancebetweenprime.cpp \
    easycity1.cpp \
    easycity2.cpp \
    escape.cpp \
    findfactorial.cpp \
    findperiodofstring.cpp \
    floor.cpp \
    getsignature.cpp \
    getsolution.cpp \
    judge.cpp \
    judgewindow.cpp \
    largefactorical.cpp \
    largestroot.cpp \
    longestcommonsubstring.cpp \
    longestpeekpalindrome.cpp \
    longestshortestdistance.cpp \
    main.cpp \
    mainwindow.cpp \
    manhattandistance.cpp \
    marioojisan.cpp \
    maze.cpp \
    median.cpp \
    minesweeper.cpp \
    mydatabase.cpp \
    myfibfib.cpp \
    mymath.cpp \
    myother.cpp \
    mystring.cpp \
    mytree.cpp \
    people.cpp \
    prime.cpp \
    problemset.cpp \
    scheduler.cpp \
    shortestandlongestpair.cpp \
    shortestsummationdistance.cpp \
    shygame.cpp \
    subtract1.cpp \
    sumoflargehexidecimalinteger.cpp \
    symmetricpairs.cpp \
    treewalk.cpp

HEADERS += \
    add1.h \
    building.h \
    data.h \
    distancebetweenprime.h \
    easycity1.h \
    easycity2.h \
    escape.h \
    findfactorial.h \
    findperiodofstring.h \
    floor.h \
    getsignature.h \
    getsolution.h \
    judge.h \
    judgewindow.h \
    largefactorical.h \
    largestroot.h \
    longestcommonsubstring.h \
    longestpeekpalindrome.h \
    longestshortestdistance.h \
    mainwindow.h \
    manhattandistance.h \
    marioojisan.h \
    maze.h \
    median.h \
    minesweeper.h \
    mydatabase.h \
    myfibfib.h \
    mymath.h \
    myother.h \
    mystring.h \
    mytree.h \
    people.h \
    prime.h \
    problemset.h \
    scheduler.h \
    shortestandlongestpair.h \
    shortestsummationdistance.h \
    shygame.h \
    subtract1.h \
    sumoflargehexidecimalinteger.h \
    symmetricpairs.h \
    treewalk.h

FORMS += \
    judgewindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
