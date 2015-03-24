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
    this->sum = 0;

    for(int i = 0; i < SIZE; ++i)
        isOne[i] = false;

    this->base = 10;
}

MainWindow::~MainWindow()
{
    delete ui;
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
    ui->sumLabel->setText(temp.setNum(sum, base));
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
