/********************************************************************************
** Form generated from reading UI file 'binvis-MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BINVIS_2D_MAINWINDOW_H
#define UI_BINVIS_2D_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QWidget *centralwidget;
    QPushButton *bitButton7;
    QPushButton *bitButton6;
    QPushButton *bitButton5;
    QPushButton *bitButton4;
    QPushButton *bitButton3;
    QPushButton *bitButton2;
    QPushButton *bitButton1;
    QPushButton *bitButton0;
    QComboBox *baseSelectComboBox;
    QLabel *sumLabel;
    QLabel *equalsLabel;
    QMenuBar *menubar;
    QMenu *fileMenu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(642, 393);
        QFont font;
        font.setPointSize(10);
        MainWindow->setFont(font);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionQuit->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        bitButton7 = new QPushButton(centralwidget);
        bitButton7->setObjectName(QString::fromUtf8("bitButton7"));
        bitButton7->setGeometry(QRect(50, 107, 41, 27));
        bitButton6 = new QPushButton(centralwidget);
        bitButton6->setObjectName(QString::fromUtf8("bitButton6"));
        bitButton6->setGeometry(QRect(100, 107, 41, 27));
        bitButton5 = new QPushButton(centralwidget);
        bitButton5->setObjectName(QString::fromUtf8("bitButton5"));
        bitButton5->setGeometry(QRect(150, 107, 41, 27));
        bitButton4 = new QPushButton(centralwidget);
        bitButton4->setObjectName(QString::fromUtf8("bitButton4"));
        bitButton4->setGeometry(QRect(200, 107, 41, 27));
        bitButton3 = new QPushButton(centralwidget);
        bitButton3->setObjectName(QString::fromUtf8("bitButton3"));
        bitButton3->setGeometry(QRect(250, 107, 41, 27));
        bitButton2 = new QPushButton(centralwidget);
        bitButton2->setObjectName(QString::fromUtf8("bitButton2"));
        bitButton2->setGeometry(QRect(300, 107, 41, 27));
        bitButton1 = new QPushButton(centralwidget);
        bitButton1->setObjectName(QString::fromUtf8("bitButton1"));
        bitButton1->setGeometry(QRect(350, 107, 41, 27));
        bitButton0 = new QPushButton(centralwidget);
        bitButton0->setObjectName(QString::fromUtf8("bitButton0"));
        bitButton0->setGeometry(QRect(400, 107, 41, 27));
        baseSelectComboBox = new QComboBox(centralwidget);
        baseSelectComboBox->setObjectName(QString::fromUtf8("baseSelectComboBox"));
        baseSelectComboBox->setGeometry(QRect(50, 30, 131, 24));
        baseSelectComboBox->setEditable(false);
        sumLabel = new QLabel(centralwidget);
        sumLabel->setObjectName(QString::fromUtf8("sumLabel"));
        sumLabel->setGeometry(QRect(537, 110, 71, 21));
        sumLabel->setFont(font);
        sumLabel->setAlignment(Qt::AlignCenter);
        equalsLabel = new QLabel(centralwidget);
        equalsLabel->setObjectName(QString::fromUtf8("equalsLabel"));
        equalsLabel->setGeometry(QRect(460, 110, 58, 21));
        equalsLabel->setFont(font);
        equalsLabel->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 642, 21));
        fileMenu = new QMenu(menubar);
        fileMenu->setObjectName(QString::fromUtf8("fileMenu"));
        fileMenu->setFont(font);
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(fileMenu->menuAction());
        fileMenu->addAction(actionQuit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        bitButton7->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        bitButton6->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        bitButton5->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        bitButton4->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        bitButton3->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        bitButton2->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        bitButton1->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        bitButton0->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        baseSelectComboBox->clear();
        baseSelectComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Decimal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Hexadecimal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Octal", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        baseSelectComboBox->setToolTip(QApplication::translate("MainWindow", "Convert to this base.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        sumLabel->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        equalsLabel->setText(QApplication::translate("MainWindow", "=", 0, QApplication::UnicodeUTF8));
        fileMenu->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BINVIS_2D_MAINWINDOW_H
