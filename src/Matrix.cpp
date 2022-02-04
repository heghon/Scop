/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:37:04 by bmenant           #+#    #+#             */
/*   Updated: 2022/02/04 22:06:48 by bmenant          ###   ########.fr       */
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
                else
                    mat[i][j] = 0.0f;
            }
        }
    }
}

Matrix Matrix::addition(Matrix const& matrix) const
{
    Matrix finalMat(row, column);
    
    if (row != matrix.row || column != matrix.column)
    {
        cout << "You're trying an addition between two different matrixes (row or column)." << endl
            << "I can't make that operation, please look at the function call." << endl;
        exit(0);
    }
    else
    {
        for (int i = 0; i < finalMat.getRow(); i++)
        {
            for (int j = 0; j < finalMat.getColumn(); j++)
            {
                finalMat.setMatrixElement("addition", i, j, mat[i][j]);
                finalMat.setMatrixElement("addition", i, j, matrix.mat[i][j]);
            }
        }
    }
    return finalMat;
}

Matrix Matrix::substraction(Matrix const& matrix) const
{
    Matrix finalMat(row, column);
    
    if (row != matrix.row || column != matrix.column)
    {
        cout << "You're trying an subtraction between two different matrixes (row or column)." << endl
            << "I can't make that operation, please look at the function call." << endl;
        exit(0);
    }
    else
    {
        for (int i = 0; i < finalMat.getRow(); i++)
        {
            for (int j = 0; j < finalMat.getColumn(); j++)
            {
                finalMat.setMatrixElement("addition", i, j, mat[i][j]);
                finalMat.setMatrixElement("subtraction", i, j, matrix.mat[i][j]);
            }
        }
    }
    return finalMat;
}

Matrix Matrix::multiplication(Matrix const& matrix) const
{
    Matrix finalMat(row, column);

    if (column != matrix.row)
    {
        cout << "You're trying a multiplication between two uncompatible matrixes." << endl
            << "I can't make that operation, please look at the function call." << endl;
        exit(0);
    }
    else 
    {
        for (int i = 0; i < finalMat.getRow(); i++)
        {
            for (int j = 0; j < finalMat.getColumn(); j++)
            {
                float element = 0.0;

                for (int k = 0; k < column; k++)
                {
                    element += mat[i][k] * matrix.mat[k][j];
                }
                finalMat.setMatrixElement("set", i, j, element);
            }
        }
    }
    return finalMat;
}

Matrix operator+(Matrix const& mat1, Matrix const& mat2)
{
    Matrix result = mat1.addition(mat2);

    return result;
}

Matrix operator-(Matrix const& mat1, Matrix const& mat2)
{
    Matrix result = mat1.substraction(mat2);

    return result;
}

Matrix operator*(Matrix const& mat1, Matrix const& mat2)
{
    Matrix result = mat1.multiplication(mat2);

    return result;
}