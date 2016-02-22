/*
 * mainwindow.h
 * created: October 9, 2014
 *
 * {one line to give the program's name and a brief idea of what it does.}
 * Copyright (C) 2014 Douglas Chidester
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QtGui/QMessageBox>
#include <QRect>
#include <QWidget>

#define SIZE 8
#define ONES_COMPLEMENT 1
#define TWOS_COMPLEMENT 2

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_bitButton0_clicked();
    void on_bitButton1_clicked();
    void on_bitButton2_clicked();
    void on_bitButton3_clicked();
    void on_bitButton4_clicked();
    void on_bitButton5_clicked();
    void on_bitButton6_clicked();
    void on_bitButton7_clicked();

    void on_baseSelectComboBox_currentIndexChanged(int index);
    void on_binaryRepresentComboBox_currentIndexChanged(int index);
    void showAbout();

private:
    Ui::MainWindow *ui;
    enum Representation { Unsigned = 0, OnesComplement = 1, TwosComplement = 2 };
    enum BitNumber { bit0 = 0, bit1 = 1, bit2 = 2, bit3 = 3, bit4 = 4, bit5 = 5, bit6 = 6, bit7 = 7 };
    enum BitValue { bit0Value = 1, bit1Value = 2, bit2Value = 4, bit3Value = 8,
                    bit4Value = 16, bit5Value = 32, bit6Value = 64, bit7Value = 128 };
    enum Base { Octal = 8, Decimal = 10, Hexadecimal = 16 };
    int sum;
    bool isOne[SIZE];
    int base;
    int represent;
    QString author;
    QString version;

    void toggleBitValue(int bitIndex, int value, QPushButton* bitButton);
    void updateSumLabel();
    int collectNonMSBBitValues();

    void compute1sComp();
    void compute2sComp();
};

#endif // MAINWINDOW_H
