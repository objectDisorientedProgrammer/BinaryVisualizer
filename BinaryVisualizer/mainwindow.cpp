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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bitButton0_clicked()
{
    QString temp;
    if(isOne[0])
    {
        sum -= 1;
        ui->bitButton0->setText("0");
        isOne[0] = false;
    }
    else
    {
        sum += 1;
        ui->bitButton0->setText("1");
        isOne[0] = true;
    }
    ui->sumLabel->setText(temp.setNum(sum));
}

void MainWindow::on_bitButton1_clicked()
{
    QString temp;
    if(isOne[1])
    {
        sum -= 2;
        ui->bitButton1->setText("0");
        isOne[1] = false;
    }
    else
    {
        sum += 2;
        ui->bitButton1->setText("1");
        isOne[1] = true;
    }
    ui->sumLabel->setText(temp.setNum(sum));
}
