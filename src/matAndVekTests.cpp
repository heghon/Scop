/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matAndVekTests.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 15:44:33 by bmenant           #+#    #+#             */
/*   Updated: 2022/02/20 14:20:34 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/scop.h"

using namespace std;

void matAndVekTests()
{
    Matriks mat1(4, 4);
    mat1.displayMatriks("mat1");
    mat1.identification();
    mat1.displayMatriks("mat1");
    mat1.scalification(2, 3, 4);
    mat1.displayMatriks("mat1");
    mat1.identification();
    mat1.displayMatriks("mat1");
    mat1.translatification(2, 3, 4);
    mat1.displayMatriks("mat1");
    mat1.identification();
    mat1.rotatification('X', -45);
    mat1.displayMatriks("mat1");
    Vektor vek(1, 2, 3, 1);
    Matriks mat2(vek);
    Matriks mat3 = mat1 * mat2;
    mat2.displayMatriks("mat2");
    mat3.displayMatriks("mat3");


    Matriks mat1(3, 3);
    mat1.setMatriksElement("set", 0, 0, 4);
    mat1.setMatriksElement("set", 0, 1, 2);
    mat1.setMatriksElement("set", 0, 2, 0);
    mat1.setMatriksElement("set", 1, 0, 0);
    mat1.setMatriksElement("set", 1, 1, 8);
    mat1.setMatriksElement("set", 1, 2, 1);
    mat1.setMatriksElement("set", 2, 0, 0);
    mat1.setMatriksElement("set", 2, 1, 1);
    mat1.setMatriksElement("set", 2, 2, 0);
    // mat1 = MatriksScaling(mat1, 0.5);
    mat1.displayMatriks("mat1");
    Matriks mat2(3, 3);
    mat2.setMatriksElement("set", 0, 0, 4);
    mat2.setMatriksElement("set", 0, 1, 2);
    mat2.setMatriksElement("set", 0, 2, 1);
    mat2.setMatriksElement("set", 1, 0, 2);
    mat2.setMatriksElement("set", 1, 1, 0);
    mat2.setMatriksElement("set", 1, 2, 4);
    mat2.setMatriksElement("set", 2, 0, 9);
    mat2.setMatriksElement("set", 2, 1, 4);
    mat2.setMatriksElement("set", 2, 2, 2);
    mat2.displayMatriks("mat2");
    // Matriks mat3 = mat1 - mat2;
    Matriks mat3(4, 4);
    mat3.identification();
    mat3.displayMatriks("mat3");
    Vektor vek(1, 2, 3, 4);
    Matriks mat5(vek);
    mat5.displayMatriks("mat5");
    Matriks mat6 = mat3 * mat5;
    mat6.displayMatriks("mat6");
    Matriks mat4(3, 3);
    mat4 = mat1 * mat2;
    mat4.displayMatriks("mat4");

    Vektor vec1 = Vektor(0, 2, 1, 1);
    Vektor vec2 = Vektor(-3, 0, 0, 1);
    vec1.displayVektor("vec1");
    vec1.displayLength("vec1");
    vec1 = scaleVektor(vec1, '*', 2);
    vec1.displayVektor("vec1");
    vec1.displayLength("vec1");
    vec2.displayVektor("vec2");
    vec2.displayLength("vec2");
    vec2 = negateVektor(vec2);
    vec2.displayVektor("vec2");
    vec2.displayLength("vec2");
    Vektor vec3 = vec2 - vec1;
    vec3 += vec2;
    vec3.displayVektor("vec3");
    vec3.displayLength("vec3");
    cout << "vec1 . vec2 = " << dotProduct(vec1, vec2) << endl;
    cout << "radangle(vec1, vec2) = " << radAngle(vec1, vec2) << endl;
    cout << "degAngle(vec1, vec2) = " << degAngle(vec1, vec2) << endl;
    Vektor vec4 = crossProduct(vec1, vec3);
    vec4.displayVektor("vec4");
    vec4.displayLength("vec4");
}