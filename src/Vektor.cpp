/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vektor.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:06:32 by bmenant           #+#    #+#             */
/*   Updated: 2022/02/03 17:46:15 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Vektor.h"
#include <iostream>
#include <cmath>

using namespace std;

Vektor::Vektor(float x, float y, float z, float w) : X(x), Y(y), Z(z), W(w)
{
    length = sqrtf((X * X) + (Y * Y) + (Z * Z));
}

float Vektor::getX()
{
    return X;
}

float Vektor::getY()
{
    return Y;
}

float Vektor::getZ()
{
    return Z;
}

float Vektor::getW()
{
    return W;
}

float Vektor::getLength()
{
    return length;
}

void Vektor::setX(float newValue)
{
    X = newValue;
}

void Vektor::setY(float newValue)
{
    Y = newValue;
}

void Vektor::setZ(float newValue)
{
    Z = newValue;
}

void Vektor::setW(float newValue)
{
    W = newValue;
}

void Vektor::setLength()
{
    length = length = sqrtf((X * X) + (Y * Y) + (Z * Z));;
}

void Vektor::displayVektor(string name)
{
    cout << "Vector " << name << " = "
        << " [ " << X << " ]" << endl
        << "               [ " << Y << " ]" << endl
        << "               [ " << Z << " ]" << endl
        << "               [ " << W << " ]" << endl;
}

void Vektor::displayLength(string name)
{
    cout << "Vector " << name << " - length = " << length << "." << endl;
}