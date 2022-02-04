/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vektor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:10:28 by bmenant           #+#    #+#             */
/*   Updated: 2022/02/04 21:17:42 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEKTOR_H
#define VEKTOR_H

#include <string>

class Vektor
{
private:

    float X;
    float Y;
    float Z;
    float W;
    float length;

public:

    Vektor();
    Vektor(float x, float y, float z, float w);
    float getX();
    float getY();
    float getZ();
    float getW();
    float getLength();
    void setX(float newValue);
    void setY(float newValue);
    void setZ(float newValue);
    void setW(float newValue);
    void setLength();
    void displayVektor(std::string name);
    void displayLength(std::string name);
    Vektor addition(Vektor const& vek) const;
    Vektor subtraction(Vektor const& vek) const;
    void operator+=(Vektor const& vek);
    void operator-=(Vektor const& vek);
};
  
#endif