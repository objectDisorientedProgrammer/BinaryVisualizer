/*
 * mainwindow.cpp
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

#include "mainwindow.h"
#include "ui_binvis-MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // initialize strings
    this->author = "Douglas Chidester";
    this->version = "v0.1.0";

    this->sum = 0;
    for(int i = 0; i < SIZE; ++i)
        isOne[i] = false;

    this->base = Decimal;
    this->represent = 0;

    // set shortcut to File->Quit menu item
    ui->fileMenu->setShortcutEnabled(QKeySequence(tr("Alt+F")));
    connect(ui->actionQuit, SIGNAL(triggered()), qApp, SLOT(quit()));
    // set shortcut to Help->About menu item
    ui->menuHelp->setShortcutEnabled(QKeySequence(tr("Alt+H")));
    connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(showAbout()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showAbout()
{
    QMessageBox::information(this, "About", "Created by " + this->author + "\n\nVersion " + this->version);
}

void MainWindow::toggleBitValue(int bitIndex, int value, QPushButton* bitButton)
{
    if(isOne[bitIndex])
    {
        sum -= value;
        bitButton->setText("0");
        isOne[bitIndex] = false;
    }
    else
    {
        sum += value;
        bitButton->setText("1");
        isOne[bitIndex] = true;
    }
}

int MainWindow::collectNonMSBBitValues()
{
    int value = 0;

    if(isOne[bit0])
        value += bit0Value;
    if(isOne[bit1])
        value += bit1Value;
    if(isOne[bit2])
        value += bit2Value;
    if(isOne[bit3])
        value += bit3Value;
    if(isOne[bit4])
        value += bit4Value;
    if(isOne[bit5])
        value += bit5Value;
    if(isOne[bit6])
        value += bit6Value;

    return value;
}

void MainWindow::updateSumLabel()
{
    QString temp;

    switch(represent)
    {
    case Unsigned: // Unsigned values
        sum = collectNonMSBBitValues();
        if(isOne[bit7])
            sum += bit7Value;
        break;
    case OnesComplement:
        // TODO
        compute1sComp();
        break;
    case TwosComplement:
        compute2sComp();
        break;
    default:
        sum = collectNonMSBBitValues();
        if(isOne[bit7])
            sum += bit7Value;
        break;
    }
    ui->sumLabel->setText(temp.setNum(sum, base));
}

void MainWindow::compute1sComp()
{
    sum = collectNonMSBBitValues();
    if(isOne[bit7])
    {
        if(sum == 0)
        {
            QString negativeZero = "-0"; // TODO not working
            ui->sumLabel->setText(negativeZero);
        }
        else
            sum *= -1;
    }
}

void MainWindow::compute2sComp()
{
    sum = collectNonMSBBitValues();
    if(isOne[bit7])
        sum -= bit7Value;
}

void MainWindow::on_bitButton0_clicked()
{
    toggleBitValue(bit0, bit0Value, ui->bitButton0);
    updateSumLabel();
}

void MainWindow::on_bitButton1_clicked()
{
    toggleBitValue(bit1, bit1Value, ui->bitButton1);
    updateSumLabel();
}

void MainWindow::on_bitButton2_clicked()
{
    toggleBitValue(bit2, bit2Value, ui->bitButton2);
    updateSumLabel();
}

void MainWindow::on_bitButton3_clicked()
{
    toggleBitValue(bit3, bit3Value, ui->bitButton3);
    updateSumLabel();
}

void MainWindow::on_bitButton4_clicked()
{
    toggleBitValue(bit4, bit4Value, ui->bitButton4);
    updateSumLabel();
}

void MainWindow::on_bitButton5_clicked()
{
    toggleBitValue(bit5, bit5Value, ui->bitButton5);
    updateSumLabel();
}

void MainWindow::on_bitButton6_clicked()
{
    toggleBitValue(bit6, bit6Value, ui->bitButton6);
    updateSumLabel();
}

void MainWindow::on_bitButton7_clicked()
{
    toggleBitValue(bit7, bit7Value, ui->bitButton7);
    updateSumLabel();
}

void MainWindow::on_baseSelectComboBox_currentIndexChanged(int index)
{
    switch(index)
    {
        case BaseDecimalIndex:
            base = Decimal;
            break;
        case BaseHexIndex:
            base = Hexadecimal;
            break;
        case BaseOctalIndex:
            base = Octal;
            break;
        default:
            base = Decimal;
            break;
    }
    updateSumLabel();
}

void MainWindow::on_binaryRepresentComboBox_currentIndexChanged(int index)
{
    switch(index)
    {
        case Unsigned:
            represent = Unsigned;
            break;
        case OnesComplement:
            represent = OnesComplement;
            break;
        case TwosComplement:
            represent = TwosComplement;
            break;
        default:
            represent = Unsigned;
            break;
    }
    updateSumLabel();
}
