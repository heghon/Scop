/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:37:04 by bmenant           #+#    #+#             */
/*   Updated: 2022/02/05 15:32:26 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/scop.h"
#include <iostream>
#include <cmath>

using namespace std;

Matrix::Matrix(Vektor vek) : row(4), column(1)
{
    for (int i = 0; i < row; i++)
    {
        vector<float> vec;
        if (i == 0)
            vec.push_back(vek.getX());
        else if (i == 1)
            vec.push_back(vek.getY());
        else if (i == 2)
            vec.push_back(vek.getZ());
        else if (i == 3)
            vec.push_back(vek.getW());
        mat.push_back(vec);
    }
}

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
    if (row != column)
    {
        cout << "You're trying an indentificarion on an unfit matrix (you need rows = columns)." << endl
            << "I can't make that operation, please look at the function call." << endl;
        exit(0);
    }

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

void Matrix::scalification(float sX, float sY, float sZ)
{
    if (row != 4 || column != 4)
    {
        cout << "You're trying an scalification on an unfit matrix (you need 4 rows and 4 columns)." << endl
            << "I can't make that operation, please look at the function call." << endl;
        exit(0);
    }
    mat[0][0] = sX;
    mat[1][1] = sY;
    mat[2][2] = sZ;
}

void Matrix::translatification(float tX, float tY, float tZ)
{
    if (row != 4 || column != 4)
    {
        cout << "You're trying an translatification on an unfit matrix (you need 4 rows and 4 columns)." << endl
            << "I can't make that operation, please look at the function call." << endl;
        exit(0);
    }
    mat[0][3] = tX;
    mat[1][3] = tY;
    mat[2][3] = tZ;
}

void Matrix::Rotatification(char rot, float angle)
{
    if (row != 4 || column != 4)
    {
        cout << "You're trying an rotatification on an unfit matrix (you need 4 rows and 4 columns)." << endl
            << "I can't make that operation, please look at the function call." << endl;
        exit(0);
    }
    angle *= (M_PI / 180);
    if (rot == 'X')
    {
        mat[1][1] = cos(angle);
        mat[1][2] = -sin(angle);
        mat[2][1] = sin(angle);
        mat[2][2] = cos(angle);
    }
    else if (rot == 'Y')
    {
        mat[0][0] = cos(angle);
        mat[0][2] = sin(angle);
        mat[2][0] = -sin(angle);
        mat[2][2] = cos(angle);
    }
    else if (rot == 'Z')
    {
        mat[0][0] = cos(angle);
        mat[0][1] = -sin(angle);
        mat[1][0] = sin(angle);
        mat[1][1] = cos(angle);
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
    Matrix finalMat(row, matrix.column);

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