/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:50:00 by bmenant           #+#    #+#             */
/*   Updated: 2022/02/02 17:26:25 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADER_H
#define SHADER_H

#include "../glad/include/glad/glad.h" // include glad to get all the required OpenGL headers
  
#include <string>

class Shader
{
private:

    unsigned int ID;

    void checkCompileErrors(unsigned int shader, std::string type);

public:

    Shader(const char* vertexPath, const char* fragmentPath);
    unsigned int returnID();
    void use();
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
};
  
#endif