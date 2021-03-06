/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:20:26 by bmenant           #+#    #+#             */
/*   Updated: 2022/02/20 14:20:15 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

#include "../glad/include/glad/glad.h"
#include "../GLFW/include/GLFW/glfw3.h"
#include "Shader.h"
#include "Vektor.h"
#include "Matriks.h"

void glfwStart();
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
GLFWwindow* makeWindow(int width, int height);
void renderLoop(GLFWwindow* window, Shader ourShader, unsigned int VAO, unsigned int texture1, unsigned int texture2);

int gladStart();

void processInput(GLFWwindow *window);

unsigned int shadersHandler();
unsigned int vertexShadersCompil();
unsigned int fragmentShadersCompil();
unsigned int shaderProgramLoader(unsigned int vertexShader, unsigned int fragmentShader);

Vektor scaleVektor(Vektor vek, char scaleOp, float scaleNbr);
Vektor negateVektor(Vektor vek);
float dotProduct(Vektor vek1, Vektor vek2);
float radAngle(Vektor vek1, Vektor vek2);
float degAngle(Vektor vek1, Vektor vek2);
Vektor crossProduct(Vektor vek1, Vektor vek2);
Vektor operator+(Vektor const& vek1, Vektor const& vek2);
Vektor operator-(Vektor const& vek1, Vektor const& vek2);

Matriks MatriksScaling(Matriks mat, float scale);
GLfloat *giveMatriksList();
Matriks operator+(Matriks const& mat1, Matriks const& mat2);
Matriks operator-(Matriks const& mat1, Matriks const& mat2);
Matriks operator*(Matriks const& mat1, Matriks const& mat2);

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 1000

#endif