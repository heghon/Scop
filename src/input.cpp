/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:45:52 by bmenant           #+#    #+#             */
/*   Updated: 2022/01/31 17:57:31 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/scop.h"

using namespace std;

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS)
    {
        glClearColor(0.9f, 0.0f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }
}