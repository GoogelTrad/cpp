/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:17:04 by cmichez           #+#    #+#             */
/*   Updated: 2024/01/06 17:17:04 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("BoB"), sign(false), gradeToSign(50), gradeToExecute(100)
{
}

AForm::AForm(std::string _name, int toSign, int toExecute) : name(_name), sign(false),
			gradeToSign(toSign), gradeToExecute(toExecute)
{
	if (this->gradeToSign > 150)
		throw GradeTooLowExecption();
	else if (this->gradeToSign < 1)
		throw GradeTooHighExecption();
	if (this->gradeToExecute > 150)
		throw GradeTooLowExecption();
	else if (this->gradeToExecute < 1)
		throw GradeTooHighExecption();
}

AForm::AForm(const AForm &copy) : name(copy.getName()), gradeToExecute(copy.getGradeToExecute()),
							gradeToSign(copy.getGradeToSign())
{
	this->sign = copy.isSigned();
}

AForm &AForm::operator=(const AForm &copy)
{
	if (this != &copy)
	{
		(std::string) this->name = copy.name;
		this->sign = copy.sign;
	}

	return *this;
}

AForm::~AForm()
{
}

int AForm::getGradeToSign(void) const
{
	return this->gradeToSign;
}

int AForm::getGradeToExecute(void) const
{
	return this->gradeToExecute;
}

bool AForm::isSigned(void) const
{
	return this->sign;
}

void AForm::beSigned(Bureaucrat &employe)
{
	if (employe.getGrade() > this->getGradeToSign())
		throw GradeTooLowExecption();
	else
		this->sign = true;
}

std::string AForm::getName(void) const
{
	return this->name;
}

std::ostream &operator<<(std::ostream &stream, const AForm &AForm)
{
	stream << AForm.getName() << " AForm needs " << AForm.getGradeToSign() << " to be signed!" << std::endl;
	stream << AForm.getName() << " AForm needs " << AForm.getGradeToExecute() << " to be executed!" << std::endl;
	if (AForm.isSigned())
		stream << AForm.getName() << " is signed!" << std::endl;
	else
		stream << AForm.getName() << " is not signed!" << std::endl;
	return stream;
}
