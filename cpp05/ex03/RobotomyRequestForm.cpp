/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 00:29:08 by cmichez           #+#    #+#             */
/*   Updated: 2024/01/08 00:29:08 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string _target) : target(_target), 
	AForm::AForm("RobotomyRequestForm", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
	:  AForm::AForm(copy), target(copy.getTarget())
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{
}


std::string RobotomyRequestForm::getTarget(void) const
{
	return this->target;
}

RobotomyRequestForm RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	this->target = copy.target;
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowExecute();
	if (!this->isSigned())
		throw FormNotSigned();

	std::cout << "Some drilling noises!" << std::endl;
	std::srand(time(0));

	int random = std::rand();
	if (random < RAND_MAX / 2)
		std::cout << executor.getName() << " has been robotomized!" << std::endl;
	else
		std::cout << executor.getName() << " has fail the robotomization!" << std::endl;
}