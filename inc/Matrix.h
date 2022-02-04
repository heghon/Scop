/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:34:51 by bmenant           #+#    #+#             */
/*   Updated: 2022/02/04 15:24:04 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
#define MATRIX_H

#include <string>
#include <vector>

class Matrix
{
private:

    int row;
    int column;
    std::vector<std::vector<float> > mat; 

public:

    Matrix(int i, int j);
    float getRow();
    float getColumn();
    float getMatrixElement(int row, int col);
    void setMatrixElement(std::string operation, int row, int col, float value);
    void displayMatrix(std::string name);
    void identification();
};
  
#endif