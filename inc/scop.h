/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:20:26 by bmenant           #+#    #+#             */
/*   Updated: 2022/02/01 16:35:25 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

#include "../glad/include/glad/glad.h"
#include "../GLFW/include/GLFW/glfw3.h"
#include "Shader.h"

void glfwStart();
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
GLFWwindow* makeWindow(int width, int height);
void renderLoop(GLFWwindow* window, Shader ourShader, unsigned int VAO);

int gladStart();

void processInput(GLFWwindow *window);

unsigned int shadersHandler();
unsigned int vertexShadersCompil();
unsigned int fragmentShadersCompil();
unsigned int shaderProgramLoader(unsigned int vertexShader, unsigned int fragmentShader);

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 1000

#endif