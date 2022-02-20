/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matriks.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:37:04 by bmenant           #+#    #+#             */
/*   Updated: 2022/02/20 13:33:17 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/scop.h"
#include <iostream>
#include <cmath>

using namespace std;

Matriks::Matriks(Vektor vek) : row(4), column(1)
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

Matriks::Matriks(int i, int j) : row(i), column(j)
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

float Matriks::getRow()
{
    return row;
}

float Matriks::getColumn()
{
    return column;
}

float Matriks::getMatriksElement(int row, int col)
{
    return mat[row][col];
}

void Matriks::setMatriksElement(string operation, int row, int col, float value)
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

void Matriks::displayMatriks(string name)
{
    cout << "Matriks " << name << " = " << endl;
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

void Matriks::identification()
{
    if (row != column)
    {
        cout << "You're trying an indentificarion on an unfit Matriks (you need rows = columns)." << endl
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

void Matriks::scalification(float sX, float sY, float sZ)
{
    if (row != 4 || column != 4)
    {
        cout << "You're trying an scalification on an unfit Matriks (you need 4 rows and 4 columns)." << endl
            << "I can't make that operation, please look at the function call." << endl;
        exit(0);
    }
    mat[0][0] = sX;
    mat[1][1] = sY;
    mat[2][2] = sZ;
}

void Matriks::translatification(float tX, float tY, float tZ)
{
    if (row != 4 || column != 4)
    {
        cout << "You're trying an translatification on an unfit Matriks (you need 4 rows and 4 columns)." << endl
            << "I can't make that operation, please look at the function call." << endl;
        exit(0);
    }
    mat[0][3] = tX;
    mat[1][3] = tY;
    mat[2][3] = tZ;
}

void Matriks::rotatification(char rot, float angle)
{
    if (row != 4 || column != 4)
    {
        cout << "You're trying an rotatification on an unfit Matriks (you need 4 rows and 4 columns)." << endl
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

Matriks Matriks::addition(Matriks const& Matriks) const
{
    class Matriks finalMat(row, column);
    
    if (row != Matriks.row || column != Matriks.column)
    {
        cout << "You're trying an addition between two different Matrikses (row or column)." << endl
            << "I can't make that operation, please look at the function call." << endl;
        exit(0);
    }
    else
    {
        for (int i = 0; i < finalMat.getRow(); i++)
        {
            for (int j = 0; j < finalMat.getColumn(); j++)
            {
                finalMat.setMatriksElement("addition", i, j, mat[i][j]);
                finalMat.setMatriksElement("addition", i, j, Matriks.mat[i][j]);
            }
        }
    }
    return finalMat;
}

Matriks Matriks::substraction(Matriks const& Matriks) const
{
    class Matriks finalMat(row, column);
    
    if (row != Matriks.row || column != Matriks.column)
    {
        cout << "You're trying an subtraction between two different Matrikses (row or column)." << endl
            << "I can't make that operation, please look at the function call." << endl;
        exit(0);
    }
    else
    {
        for (int i = 0; i < finalMat.getRow(); i++)
        {
            for (int j = 0; j < finalMat.getColumn(); j++)
            {
                finalMat.setMatriksElement("addition", i, j, mat[i][j]);
                finalMat.setMatriksElement("subtraction", i, j, Matriks.mat[i][j]);
            }
        }
    }
    return finalMat;
}

Matriks Matriks::multiplication(Matriks const& Matriks) const
{
    class Matriks finalMat(row, Matriks.column);

    if (column != Matriks.row)
    {
        cout << "You're trying a multiplication between two uncompatible Matrikses." << endl
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
                    element += mat[i][k] * Matriks.mat[k][j];
                }
                finalMat.setMatriksElement("set", i, j, element);
            }
        }
    }
    return finalMat;
}

void Matriks::toArray(GLfloat *tab)
{
    if (row != 4 || column != 4)
    {
        cout << "You're trying to make an array with a Matriks that is not 4 x 4." << endl
            << "I can't make that operation, please look at the function call." << endl;
        exit(0);
    }
    // GLfloat result[] = {
    //     getMatriksElement(0, 0), getMatriksElement(1, 0), getMatriksElement(2, 0), getMatriksElement(3, 0),
    //     getMatriksElement(0, 1), getMatriksElement(1 ,1), getMatriksElement(2, 1), getMatriksElement(3, 1),
    //     getMatriksElement(0, 2), getMatriksElement(1, 2), getMatriksElement(2, 2), getMatriksElement(3, 2),
    //     getMatriksElement(0, 3), getMatriksElement(1, 3), getMatriksElement(2, 3), getMatriksElement(3, 3)
    // };

    // GLfloat *tab = result;

    // GLfloat tab[16];

    tab[0] = getMatriksElement(0, 0);
    tab[1] = getMatriksElement(1, 0);
    tab[2] = getMatriksElement(2, 0);
    tab[3] = getMatriksElement(3, 0);
    tab[4] = getMatriksElement(0, 1);
    tab[5] = getMatriksElement(1, 1);
    tab[6] = getMatriksElement(2, 1);
    tab[7] = getMatriksElement(3, 1);
    tab[8] = getMatriksElement(0, 2);
    tab[9] = getMatriksElement(1, 2);
    tab[10] = getMatriksElement(2, 2);
    tab[11] = getMatriksElement(3, 2);
    tab[12] = getMatriksElement(0, 3);
    tab[13] = getMatriksElement(1, 3);
    tab[14] = getMatriksElement(2, 3);
    tab[15] = getMatriksElement(3, 3);

    // return tab;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  END OF THE CLASS FUNCTIONS
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Matriks operator+(Matriks const& mat1, Matriks const& mat2)
{
    Matriks result = mat1.addition(mat2);

    return result;
}

Matriks operator-(Matriks const& mat1, Matriks const& mat2)
{
    Matriks result = mat1.substraction(mat2);

    return result;
}

Matriks operator*(Matriks const& mat1, Matriks const& mat2)
{
    Matriks result = mat1.multiplication(mat2);

    return result;
}