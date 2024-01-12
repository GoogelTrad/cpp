/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:25:39 by cmichez           #+#    #+#             */
/*   Updated: 2024/01/07 17:25:39 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string _target)
	: target(_target), AForm::AForm("PresidentialPardonForm", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
	: AForm::AForm(copy), target(copy.getTarget())
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	this->target = copy.target;
	return *this;
}

std::string PresidentialPardonForm::getTarget(void) const
{
	return this->target;
}

void PresidentialPardonForm::execute(const Bureaucrat & executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowExecute();
	if (!this->isSigned())
		throw FormNotSigned();

	std::cout << executor.getName() << " has been pardonned by Zaphod Beeblerox!" << std::endl;
}