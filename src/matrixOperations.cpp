/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MatrixOperations.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:13:59 by bmenant           #+#    #+#             */
/*   Updated: 2022/02/09 20:04:53 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Matrix.h"
#include <iostream>
#include <cmath>

using namespace std;


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