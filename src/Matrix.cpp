/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:37:04 by bmenant           #+#    #+#             */
/*   Updated: 2022/02/04 15:26:14 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Matrix.h"
#include <iostream>
#include <cmath>

using namespace std;

Matrix::Matrix(int i, int j) : row(i), column(j)
{
    for (int i = 0; i < row; i++)
    {
        vector<float> vec;
        for (int j = 0; j < column; j++)
        {
            vec.push_back(0.0f);
        }
        mat.push_back(vec);
    }
}

float Matrix::getRow()
{
    return row;
}

float Matrix::getColumn()
{
    return column;
}

float Matrix::getMatrixElement(int row, int col)
{
    return mat[row][col];
}

void Matrix::setMatrixElement(string operation, int row, int col, float value)
{
    if (operation == "set")
    {
        mat[row][col] = value;
    }
    if (operation == "addition")
    {
        mat[row][col] += value;
    }
    if (operation == "subtraction")
    {
        mat[row][col] -= value;
    }
    if (operation == "multiplication")
    {
        mat[row][col] *= value;
    }
}

void Matrix::displayMatrix(string name)
{
    cout << "Matrix " << name << " = " << endl;
    for (int i = 0; i < (int)mat.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < (int)mat[i].size(); j++)
        {
            cout << mat[i][j];
            if (j + 1 < (int)mat[i].size())
                cout << " , ";
        }
        cout << " ]" << endl;
    }
}

void Matrix::identification()
{
    if (row == column)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (i == j)
                    mat[i][j] = 1.0f;
            }
        }
    }
}