/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matriks.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:34:51 by bmenant           #+#    #+#             */
/*   Updated: 2022/02/20 14:18:18 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Matriks_H
#define Matriks_H

#include "../glad/include/glad/glad.h"
#include <string>
#include <vector>

class Vektor;

class Matriks
{
private:

    int row;
    int column;
    std::vector<std::vector<float> > mat; 

public:

    Matriks(Vektor vek);
    Matriks(int i, int j);
    float getRow();
    float getColumn();
    float getMatriksElement(int row, int col);
    void setMatriksElement(std::string operation, int row, int col, float value);
    void displayMatriks(std::string name);
    void identification();
    void scalification(float sX, float sY, float sZ);
    void translatification(float tX, float tY, float tZ);
    void rotatification(char rot, float angle);
    Matriks addition(Matriks const& mat) const;
    Matriks substraction(Matriks const& mat) const;
    Matriks multiplication(Matriks const& Matriks) const;
    void toArray(GLfloat *tab);
};
  
#endif