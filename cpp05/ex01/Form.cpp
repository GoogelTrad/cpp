/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:17:04 by cmichez           #+#    #+#             */
/*   Updated: 2024/01/06 17:17:04 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("BoB"), sign(false), gradeToSign(50), gradeToExecute(100)
{
}

Form::Form(std::string _name, int toSign, int toExecute) : name(_name), sign(false),
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

Form::Form(const Form &copy) : name(copy.getName()), gradeToExecute(copy.getGradeToExecute()),
							gradeToSign(copy.getGradeToSign())
{
	this->sign = copy.isSigned();
}

Form &Form::operator=(const Form &copy)
{
	if (this != &copy)
	{
		(std::string) this->name = copy.name;
		this->sign = copy.sign;
	}

	return *this;
}

Form::~Form()
{
}

int Form::getGradeToSign(void) const
{
	return this->gradeToSign;
}

int Form::getGradeToExecute(void) const
{
	return this->gradeToExecute;
}

bool Form::isSigned(void) const
{
	return this->sign;
}

void Form::beSigned(Bureaucrat &employe)
{
	if (employe.getGrade() > this->getGradeToSign())
		throw GradeTooLowExecption();
	else
		this->sign = true;
}

std::string Form::getName(void) const
{
	return this->name;
}

std::ostream &operator<<(std::ostream &stream, const Form &form)
{
	stream << form.getName() << " form needs " << form.getGradeToSign() << " to be signed!" << std::endl;
	stream << form.getName() << " form needs " << form.getGradeToExecute() << " to be executed!" << std::endl;
	if (form.isSigned())
		stream << form.getName() << " is signed!" << std::endl;
	else
		stream << form.getName() << " is not signed!" << std::endl;
	return stream;
}