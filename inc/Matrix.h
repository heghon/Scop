/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:34:51 by bmenant           #+#    #+#             */
/*   Updated: 2022/02/05 13:57:31 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
#define MATRIX_H

#include <string>
#include <vector>
#include "../inc/Vektor.h"

class Matrix
{
private:

    int row;
    int column;
    std::vector<std::vector<float> > mat; 

public:

    Matrix(Vektor vek);
    Matrix(int i, int j);
    float getRow();
    float getColumn();
    float getMatrixElement(int row, int col);
    void setMatrixElement(std::string operation, int row, int col, float value);
    void displayMatrix(std::string name);
    void identification();
    void scalification(float sX, float sY, float sZ);
    void translatification(float tX, float tY, float tZ);
    void Rotatification(char rot, float angle);
    Matrix addition(Matrix const& mat) const;
    Matrix substraction(Matrix const& mat) const;
    Matrix multiplication(Matrix const& matrix) const;
};
  
#endif