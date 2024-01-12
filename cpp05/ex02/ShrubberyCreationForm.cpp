/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 00:57:30 by cmichez           #+#    #+#             */
/*   Updated: 2024/01/08 00:57:30 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target) : target(_target),
	AForm::AForm("ShrubberyCreationForm", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
	:  AForm::AForm(copy), target(copy.getTarget())
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

std::string ShrubberyCreationForm::getTarget(void) const
{
	return this->target;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	std::fstream fd;

	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowExecute();
	if (!this->isSigned())
		throw FormNotSigned();

	fd.open(this->target + "_shrubbery", std::ios::out);
	fd << "       ###\n      #o###\n    #####o###\n   #o#\\#|#/###\n    ###\\|/#o#\n     # }|{  #\n       }|{\n";
	fd.close();
}

ShrubberyCreationForm ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	this->target = copy.target;
	return *this;
}