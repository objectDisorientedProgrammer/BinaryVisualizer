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

    this->base = 10;
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

void MainWindow::updateSumLabel()
{
    QString temp;
    switch(represent)
    {
    case 1: // 1's comp
        // TODO
        compute1sComp();
        break;
    case 2: // 2's comp
        compute2sComp();
        break;
    default:
        break;
    }
    ui->sumLabel->setText(temp.setNum(sum, base));
}

void MainWindow::compute1sComp()
{
    if(isOne[SIZE - 1])
        sum *= -1;
}

void MainWindow::compute2sComp()
{
    sum = 0;
    if(isOne[SIZE - 1])
        sum = -128;
    if(isOne[0])
        sum += 1;
    if(isOne[1])
        sum += 2;
    if(isOne[2])
        sum += 4;
    if(isOne[3])
        sum += 8;
    if(isOne[4])
        sum += 16;
    if(isOne[5])
        sum += 32;
    if(isOne[6])
        sum += 64;
}

void MainWindow::on_bitButton0_clicked()
{
    toggleBitValue(0, 1, ui->bitButton0);
    updateSumLabel();
}

void MainWindow::on_bitButton1_clicked()
{
    toggleBitValue(1, 2, ui->bitButton1);
    updateSumLabel();
}

void MainWindow::on_bitButton2_clicked()
{
    toggleBitValue(2, 4, ui->bitButton2);
    updateSumLabel();
}

void MainWindow::on_bitButton3_clicked()
{
    toggleBitValue(3, 8, ui->bitButton3);
    updateSumLabel();
}

void MainWindow::on_bitButton4_clicked()
{
    toggleBitValue(4, 16, ui->bitButton4);
    updateSumLabel();
}

void MainWindow::on_bitButton5_clicked()
{
    toggleBitValue(5, 32, ui->bitButton5);
    updateSumLabel();
}

void MainWindow::on_bitButton6_clicked()
{
    toggleBitValue(6, 64, ui->bitButton6);
    updateSumLabel();
}

void MainWindow::on_bitButton7_clicked()
{
    toggleBitValue(7, 128, ui->bitButton7);
    updateSumLabel();
}

void MainWindow::on_baseSelectComboBox_currentIndexChanged(int index)
{
    switch(index)
    {
        case 0: base = 10; break;
        case 1: base = 16; break;
        case 2: base = 8; break;
        default:
            break;
    }
    updateSumLabel();
}

void MainWindow::on_binaryRepresentComboBox_currentIndexChanged(int index)
{
    switch(index)
    {
    case 0: represent = 0; break;
    case 1: represent = 1; break;
    case 2: represent = 2; break;
    default:
        break;
    }
    updateSumLabel();
}
