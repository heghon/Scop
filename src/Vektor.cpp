/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vektor.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:06:32 by bmenant           #+#    #+#             */
/*   Updated: 2022/02/03 12:29:23 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Vektor.h"
#include <iostream>

using namespace std;

Vektor::Vektor(float x, float y, float z, float w) : X(x), Y(y), Z(z), W(w)
{
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

void Vektor::displayVektor()
{
    cout << "[ " << X << " ]" << endl
        << "[ " << Y << " ]" << endl
        << "[ " << Z << " ]" << endl
        << "[ " << W << " ]" << endl;
}