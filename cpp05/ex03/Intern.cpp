/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:41:33 by cmichez           #+#    #+#             */
/*   Updated: 2024/01/09 15:41:33 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern &copy)
{
	(void) copy;
}

AForm *Intern::makeForm(std::string name, const std::string target) const
{
	AForm *type[] = {(new PresidentialPardonForm(target)), (new ShrubberyCreationForm(target)), (new RobotomyRequestForm(target))};
	std::string tForm[3] = { "presidential pardon", "shrubbery creation", "robotomy request"};
	int i;
	for (i = 0; i < 3; i++)
	{
		if (tForm[i] == name)
		{
			std::cout << "Intern creates " << type[i]->getName() << std::endl;
			return type[i];
		}
		delete type[i];
	}
	throw InvalidFormNameExecption();
	return NULL;
}

Intern &Intern::operator=(const Intern &copy)
{
	return *this;
}