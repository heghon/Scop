/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vektorOperations.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:25:41 by bmenant           #+#    #+#             */
/*   Updated: 2022/02/03 18:10:27 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Vektor.h"
#include <iostream>
#include <cmath>

using namespace std;

Vektor scaleVektor(Vektor vek, char scaleOp, float scaleNbr)
{
    if (scaleOp == '+')
    {
        vek.setX(vek.getX() + scaleNbr);
        vek.setY(vek.getY() + scaleNbr);
        vek.setZ(vek.getZ() + scaleNbr);
    }
    else if (scaleOp == '-')
    {
        vek.setX(vek.getX() - scaleNbr);
        vek.setY(vek.getY() - scaleNbr);
        vek.setZ(vek.getZ() - scaleNbr);
    }
    else if (scaleOp == '*')
    {
        vek.setX(vek.getX() * scaleNbr);
        vek.setY(vek.getY() * scaleNbr);
        vek.setZ(vek.getZ() * scaleNbr);
    }
    else if (scaleOp == '/' && scaleNbr != 0.0f)
    {
        vek.setX(vek.getX() / scaleNbr);
        vek.setY(vek.getY() / scaleNbr);
        vek.setZ(vek.getZ() / scaleNbr);
    }
    else
        cout << "Vektor scaling failed, please look at the function call." << endl;
    vek.setLength();
    return vek;
}

Vektor negateVektor(Vektor vek)
{
    vek.setX(-vek.getX());
    vek.setY(-vek.getY());
    vek.setZ(-vek.getZ());
    return vek;
}

Vektor combineVektor(Vektor vek1, Vektor vek2, char ope)
{
    if (ope == '+')
    {
        Vektor finalVek(vek1.getX() + vek2.getX(), vek1.getY() + vek2.getY(), vek1.getZ() + vek2.getZ(), 1);
        return finalVek;
    }
    else if (ope == '-')
    {
        Vektor finalVek(vek1.getX() - vek2.getX(), vek1.getY() - vek2.getY(), vek1.getZ() - vek2.getZ(), 1);
        return finalVek;
    }
    else
        cout << "Vektor combining failed, please look at the function call." << endl;
    Vektor nullVek(0, 0, 0, 0);
    return (nullVek);
}

float dotProduct(Vektor vek1, Vektor vek2)
{
    return ((vek1.getX() * vek2.getX()) + (vek1.getY() * vek2.getY()) + (vek1.getZ() * vek2.getZ()));
}

float radAngle(Vektor vek1, Vektor vek2)
{
    float angle = 0.0f;
    float dotP = dotProduct(vek1, vek2);
    if ((vek1.getLength() * vek2.getLength()) != 0)
        angle = acosf(dotP / (vek1.getLength() * vek2.getLength()));
    else
        return 0; 
    return angle;
}

float degAngle(Vektor vek1, Vektor vek2)
{
    float angle = 0.0f;
    float dotP = dotProduct(vek1, vek2);
    if ((vek1.getLength() * vek2.getLength()) != 0)
        angle = acosf(dotP / (vek1.getLength() * vek2.getLength()));
    else
        return 0; 
    return (angle * (180 / M_PI));
}

Vektor crossProduct(Vektor vek1, Vektor vek2)
{
    Vektor finalVek(vek1.getY() * vek2.getZ() - vek1.getZ() * vek2.getY(),
                    vek1.getZ() * vek2.getX() - vek1.getX() * vek2.getZ(),
                    vek1.getX() * vek2.getY() - vek1.getY() * vek2.getX(), 1.0f);
    return finalVek;
}