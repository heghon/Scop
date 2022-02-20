/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matriksOperations.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:13:59 by bmenant           #+#    #+#             */
/*   Updated: 2022/02/20 14:22:34 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Matriks.h"
#include <iostream>
#include <cmath>

using namespace std;

GLfloat *giveMatriksList()
{
    static GLfloat tab[] = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
    
    return tab;
}

Matriks MatriksScaling(Matriks mat, float scale)
{
    Matriks finalMat(mat.getRow(), mat.getColumn());

    for (int i = 0; i < finalMat.getRow(); i++)
    {
        for (int j = 0; j < finalMat.getColumn(); j++)
        {
            finalMat.setMatriksElement("addition", i, j, mat.getMatriksElement(i, j));
            finalMat.setMatriksElement("multiplication", i, j, scale);
        }
    }
    return finalMat;
}