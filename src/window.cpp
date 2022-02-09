/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:46:07 by bmenant           #+#    #+#             */
/*   Updated: 2022/02/09 20:59:05 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "../inc/scop.h"

using namespace std;

extern float mixValue;

void glfwStart()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}

GLFWwindow* makeWindow(int width, int height)
{
    GLFWwindow* window = glfwCreateWindow(width, height, "{ Scop }", NULL, NULL);
    if (window == NULL)
    {
        cout << "Failed to create GLFW window" << endl;
        glfwTerminate();
        return NULL;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    return window;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
    if (window == NULL)
        return ;
}

void renderLoop(GLFWwindow* window, Shader ourShader, unsigned int VAO)
{
    while(!glfwWindowShouldClose(window))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        processInput(window);

        // glUseProgram(shaderProgram);

        float timeValue = glfwGetTime();
        // float greenValue = sin(timeValue) / 2.0f + 0.5f;
        // int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
        // glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
        // cout << "time value = " << timeValue << endl;
        

        Matrix rotaMat(4, 4);
        rotaMat.identification();
        rotaMat.Rotatification('Z', sin(timeValue));
        rotaMat.displayMatrix("rotamat");
        Matrix translaMat(4, 4);
        translaMat.identification();
        translaMat.translatification(0.5f, -0.5f, 0.0f);

        Matrix transfoMat = rotaMat * translaMat;

        ourShader.use();

        // set the texture mix value in the shader
        ourShader.setFloat("mixValue", mixValue);

        // transform matrix handling here
        unsigned int transformLoc = glGetUniformLocation(ourShader.returnID(), "transform");
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, rotaMat.toArray());

        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        // glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);

        glfwSwapBuffers(window);
        glfwPollEvents();    
    }
}