/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vektor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:10:28 by bmenant           #+#    #+#             */
/*   Updated: 2022/02/03 12:20:17 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEKTOR_H
#define VEKTOR_H

class Vektor
{
private:

    float X;
    float Y;
    float Z;
    float W;

public:

    Vektor(float x, float y, float z, float w);
    float getX();
    float getY();
    float getZ();
    float getW();
    void displayVektor();
};
  
#endif