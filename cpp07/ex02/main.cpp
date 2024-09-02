/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:42:24 by cmichez           #+#    #+#             */
/*   Updated: 2024/01/26 16:42:24 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <cstdlib>

/*int main(void)
{
	try
	{
		Array<int> tab = Array<int>(3);
		Array<int> vide = Array<int>();

		tab[0] = 1;
		tab[1] = 2;
		tab[2] = 56;
		
		Array<int> copy = Array<int>(tab);
		std::cout << "copy = " << copy[1] << std::endl;

		copy[1] = 88;
		std::cout << "tab = " << tab[10] << std::endl;

		std::cout << "Size tab = " << tab.size() << std::endl;
		std::cout << "Size vide = " << vide.size() << std::endl;
		std::cout << "Size copy = " << copy.size() << std::endl;

		vide = tab;
		std::cout << "Size vide = " << vide.size() << std::endl;
		
		return 0;		
	}
	catch(const std::exception& ArrayException)
	{
		std::cerr << ArrayException.what() << '\n';
	}
	
	
}*/

#include <iostream>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}