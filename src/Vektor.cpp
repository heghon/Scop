/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vektor.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:06:32 by bmenant           #+#    #+#             */
/*   Updated: 2022/02/04 21:18:01 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Vektor.h"
#include <iostream>
#include <cmath>

using namespace std;

Vektor::Vektor() : X(0.0f), Y (0.0f), Z(0.0f), W(1.0f), length(sqrtf((X * X) + (Y * Y) + (Z * Z)))
{
}

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
    length = sqrtf((X * X) + (Y * Y) + (Z * Z));
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

Vektor Vektor::addition(Vektor const& vek) const
{
    Vektor result;

    result.setX(vek.X + X);
    result.setY(vek.Y + Y);
    result.setZ(vek.Z + Z);
    result.setLength();
    
    return result;
}

Vektor Vektor::subtraction(Vektor const& vek) const
{
    Vektor result;

    result.setX(X - vek.X);
    result.setY(Y - vek.Y);
    result.setZ(Z - vek.Z);
    result.setLength();
    
    return result;
}

Vektor operator+(Vektor const& vek1, Vektor const& vek2)
{
    Vektor result;

    result = vek1.addition(vek2);

    return result;
}

Vektor operator-(Vektor const& vek1, Vektor const& vek2)
{
    Vektor result;

    result = vek1.subtraction(vek2);

    return result;
}

void Vektor::operator+=(Vektor const& vek)
{
    X += vek.X;
    Y += vek.Y;
    Z += vek.Z;
    setLength();
}

void Vektor::operator-=(Vektor const& vek)
{
    X -= vek.X;
    Y -= vek.Y;
    Z -= vek.Z;
    setLength();
}