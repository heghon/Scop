/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:19:15 by bmenant           #+#    #+#             */
/*   Updated: 2022/02/04 22:17:35 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/scop.h"
#include "../inc/Vektor.h"
#include "../inc/Matrix.h"

#define STB_IMAGE_IMPLEMENTATION
#include "../inc/stb_image.h"

using namespace std;

float mixValue = 0.2f;

int main()
{
    Matrix mat1(3, 3);
    mat1.setMatrixElement("set", 0, 0, 4);
    mat1.setMatrixElement("set", 0, 1, 2);
    mat1.setMatrixElement("set", 0, 2, 0);
    mat1.setMatrixElement("set", 1, 0, 0);
    mat1.setMatrixElement("set", 1, 1, 8);
    mat1.setMatrixElement("set", 1, 2, 1);
    mat1.setMatrixElement("set", 2, 0, 0);
    mat1.setMatrixElement("set", 2, 1, 1);
    mat1.setMatrixElement("set", 2, 2, 0);
    // mat1 = matrixScaling(mat1, 0.5);
    mat1.displayMatrix("mat1");
    Matrix mat2(3, 3);
    mat2.setMatrixElement("set", 0, 0, 4);
    mat2.setMatrixElement("set", 0, 1, 2);
    mat2.setMatrixElement("set", 0, 2, 1);
    mat2.setMatrixElement("set", 1, 0, 2);
    mat2.setMatrixElement("set", 1, 1, 0);
    mat2.setMatrixElement("set", 1, 2, 4);
    mat2.setMatrixElement("set", 2, 0, 9);
    mat2.setMatrixElement("set", 2, 1, 4);
    mat2.setMatrixElement("set", 2, 2, 2);
    mat2.displayMatrix("mat2");
    // Matrix mat3 = mat1 - mat2;
    Matrix mat3(4, 4);
    mat3.identification();
    mat3.displayMatrix("mat3");
    Matrix mat5(4, 1);
    mat5.setMatrixElement("set", 0, 0, 1);
    mat5.setMatrixElement("set", 1, 0, 2);
    mat5.setMatrixElement("set", 2, 0, 3);
    mat5.setMatrixElement("set", 3, 0, 4);
    mat5.displayMatrix("mat5");
    Matrix mat6 = mat3 * mat5;
    mat6.displayMatrix("mat6");
    Matrix mat4(3, 3);
    mat4 = mat1 * mat2;
    mat4.displayMatrix("mat4");

    // Vektor vec1 = Vektor(0, 2, 1, 1);
    // Vektor vec2 = Vektor(-3, 0, 0, 1);
    // vec1.displayVektor("vec1");
    // vec1.displayLength("vec1");
    // vec1 = scaleVektor(vec1, '*', 2);
    // vec1.displayVektor("vec1");
    // vec1.displayLength("vec1");
    // vec2.displayVektor("vec2");
    // vec2.displayLength("vec2");
    // vec2 = negateVektor(vec2);
    // vec2.displayVektor("vec2");
    // vec2.displayLength("vec2");
    // Vektor vec3 = vec2 - vec1;
    // vec3 += vec2;
    // vec3.displayVektor("vec3");
    // vec3.displayLength("vec3");
    // cout << "vec1 . vec2 = " << dotProduct(vec1, vec2) << endl;
    // cout << "radangle(vec1, vec2) = " << radAngle(vec1, vec2) << endl;
    // cout << "degAngle(vec1, vec2) = " << degAngle(vec1, vec2) << endl;
    // Vektor vec4 = crossProduct(vec1, vec3);
    // vec4.displayVektor("vec4");
    // vec4.displayLength("vec4");


    // glfwStart();

    // GLFWwindow* window = makeWindow(SCREEN_WIDTH,SCREEN_HEIGHT);
    // if (window == NULL || gladStart() == -1)
    //     return -1;

    // glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    
    // // unsigned int shaderProgram = shadersHandler();

    // Shader ourShader("./shaders/shader.vs", "./shaders/shader.fs");

    // // float vertices[] = {
    // //     // positions         // colors
    // //      0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
    // //     -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
    // //      0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top 
    // // };

    // // texture generation

    // unsigned int texture1;
    // glGenTextures(1, &texture1);
    // glActiveTexture(GL_TEXTURE0); // activate the texture unit first before binding texture
    // glBindTexture(GL_TEXTURE_2D, texture1);
    // // set the texture wrapping/filtering options (on the currently bound texture object)
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // // load and generate the texture
    // int width, height, nrChannels;
    // unsigned char *data = stbi_load("./textures/container.jpeg", &width, &height, &nrChannels, 0);
    // if (data)
    // {
    //     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    //     glGenerateMipmap(GL_TEXTURE_2D);
    // }
    // else
    // {
    //     cout << "Failed to load texture" << endl;
    // }
    // stbi_image_free(data);

    // // stbi_set_flip_vertically_on_load(true); 

    // // texture generation 2

    // unsigned int texture2;
    // glGenTextures(1, &texture2);
    // glActiveTexture(GL_TEXTURE1); // activate the texture unit first before binding texture
    // glBindTexture(GL_TEXTURE_2D, texture2);
    // // set the texture wrapping/filtering options (on the currently bound texture object)
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // // load and generate the texture
    // data = stbi_load("./textures/awesomeface.png", &width, &height, &nrChannels, 0);
    // if (data)
    // {
    //     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    //     glGenerateMipmap(GL_TEXTURE_2D);
    // }
    // else
    // {
    //     cout << "Failed to load texture" << endl;
    // }
    // stbi_image_free(data);

    // float vertices[] = {
    //     // positions          // colors           // texture coords
    //      0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
    //      0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
    //     -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
    //     -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
    // };

    // unsigned int indices[] = {  // note that we start from 0!
    //     0, 1, 3,   // first triangle
    //     1, 2, 3    // second triangle
    // };

    // // float texCoords[] = {
    // //     0.0f, 0.0f,  // lower-left corner  
    // //     1.0f, 0.0f,  // lower-right corner
    // //     0.5f, 1.0f   // top-center corner
    // // };

    // unsigned int VAO, VBO;
    // unsigned int EBO;
    
    // glGenVertexArrays(1, &VAO);
    // glGenBuffers(1, &VBO);
    // glGenBuffers(1, &EBO);
    // // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    // glBindVertexArray(VAO);

    // glBindBuffer(GL_ARRAY_BUFFER, VBO);  
    // glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    // glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // // position attribute
    // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,8 * sizeof(float), (void*)0);
    // glEnableVertexAttribArray(0);
    
    // // color attribute
    // glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    // glEnableVertexAttribArray(1);

    // // textureattribute
    // glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    // glEnableVertexAttribArray(2); 

    // // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    // glBindBuffer(GL_ARRAY_BUFFER, 0);
    // // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    // glBindVertexArray(0); 
    
    // ourShader.use(); // don't forget to activate the shader before setting uniforms!  
    // glUniform1i(glGetUniformLocation(ourShader.returnID(), "texture1"), 0); // set it manually
    // ourShader.setInt("texture2", 1); // or with shader class

    // renderLoop(window, ourShader, VAO);
    
    // glDeleteVertexArrays(1, &VAO);
    // glDeleteBuffers(1, &VBO);
    // // glDeleteProgram(shaderProgram);

    // glfwTerminate();
    
    return 0;
}