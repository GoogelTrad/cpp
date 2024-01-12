/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:43:57 by cmichez           #+#    #+#             */
/*   Updated: 2024/01/06 15:43:57 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Tartenpion"), grade(150)
{
}

Bureaucrat::Bureaucrat(int initialGrade, const std::string _name) : name(_name), grade(initialGrade)
{
	if (initialGrade < 1)
		throw GradeTooHighExecption();
	else if (initialGrade > 150)
		throw GradeTooLowExecption();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.getName()), grade(copy.getGrade())
{
}


Bureaucrat::~Bureaucrat()
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	this->grade = copy.grade;
	(std::string) this->name = name;

	return *this;
}

std::string Bureaucrat::getName(void) const
{
	return this->name;
}

int Bureaucrat::getGrade(void) const
{
	return this->grade;
}

void Bureaucrat::downGrade(void)
{
	if (grade < 150)
		this->grade++;
	else 
		throw GradeTooLowExecption();
}

void Bureaucrat::upGrade(void)
{
	if (grade > 1)
		this->grade--;
	else 
		throw GradeTooHighExecption();
}

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &employe)
{
	stream << employe.getName() << ", bureaucrat grade " << employe.getGrade();
	return stream;
}