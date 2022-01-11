/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:19:15 by bmenant           #+#    #+#             */
/*   Updated: 2022/01/11 16:24:42 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/scop.h"

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "nombre d'arguments : " << argc - 1 << endl;
    if (argc == 2)
        cout << "Seul argument : " << argv[1] << endl;
    return 0;
}
