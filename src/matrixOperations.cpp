/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MatrixOperations.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:13:59 by bmenant           #+#    #+#             */
/*   Updated: 2022/02/04 15:23:42 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Matrix.h"
#include <iostream>
#include <cmath>

using namespace std;

Matrix matrixAddition(Matrix mat1, Matrix mat2, int finalRow, int finalCol)
{
    Matrix finalMat(finalRow, finalCol);
    
    if (mat1.getRow() != mat2.getRow() || mat1.getColumn() != mat2.getColumn() ||
        mat1.getRow() != finalRow || mat2.getRow() != finalRow ||
        mat1.getColumn() != finalCol || mat2.getColumn() != finalCol)
    {
        cout << "You're trying an addition between two different matrixes (row or column)." << endl
            << "I can't make that operation, please look at the function call." << endl;
    }
    else
    {
        for (int i = 0; i < finalMat.getRow(); i++)
        {
            for (int j = 0; j < finalMat.getColumn(); j++)
            {
                finalMat.setMatrixElement("addition", i, j, mat1.getMatrixElement(i, j));
                finalMat.setMatrixElement("addition", i, j, mat2.getMatrixElement(i, j));
            }
        }
    }
    return finalMat;
}

Matrix matrixSubtraction(Matrix mat1, Matrix mat2, int finalRow, int finalCol)
{
    Matrix finalMat(finalRow, finalCol);
    
    if (mat1.getRow() != mat2.getRow() || mat1.getColumn() != mat2.getColumn() ||
        mat1.getRow() != finalRow || mat2.getRow() != finalRow ||
        mat1.getColumn() != finalCol || mat2.getColumn() != finalCol)
    {
        cout << "You're trying an subtraction between two different matrixes (row or column)." << endl
            << "I can't make that operation, please look at the function call." << endl;
    }
    else
    {
        for (int i = 0; i < finalMat.getRow(); i++)
        {
            for (int j = 0; j < finalMat.getColumn(); j++)
            {
                finalMat.setMatrixElement("addition", i, j, mat1.getMatrixElement(i, j));
                finalMat.setMatrixElement("subtraction", i, j, mat2.getMatrixElement(i, j));
            }
        }
    }
    return finalMat;
}

Matrix matrixScaling(Matrix mat, float scale)
{
    Matrix finalMat(mat.getRow(), mat.getColumn());

    for (int i = 0; i < finalMat.getRow(); i++)
    {
        for (int j = 0; j < finalMat.getColumn(); j++)
        {
            finalMat.setMatrixElement("addition", i, j, mat.getMatrixElement(i, j));
            finalMat.setMatrixElement("multiplication", i, j, scale);
        }
    }
    return finalMat;
}

Matrix matrixMultiplication(Matrix mat1, Matrix mat2)
{
    Matrix finalMat(mat1.getRow(), mat2.getColumn());

    if (mat1.getColumn() != mat2.getRow())
    {
        cout << "You're trying an multiplication between two uncompatible matrixes." << endl
            << "I can't make that operation, please look at the function call." << endl;
    }
    else 
    {
        for (int i = 0; i < finalMat.getRow(); i++)
        {
            for (int j = 0; j < finalMat.getColumn(); j++)
            {
                float element = 0.0;

                for (int k = 0; k < mat1.getColumn(); k++)
                {
                    element += mat1.getMatrixElement(i, k) * mat2.getMatrixElement(k, j);
                }
                finalMat.setMatrixElement("set", i, j, element);
            }
        }
    }
    return finalMat;
}