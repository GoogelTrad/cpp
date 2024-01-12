/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:17:17 by cmichez           #+#    #+#             */
/*   Updated: 2024/01/06 17:17:17 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string name;
	bool sign;
	const int gradeToSign;
	const int gradeToExecute;
public:
	AForm();
	AForm(std::string _name, int toSign, int toExecute);
	AForm(const AForm &copy);
	virtual ~AForm();

	AForm &operator=(const AForm &copy);

	virtual void execute(const Bureaucrat &executor) const = 0;

	class GradeTooHighExecption : std::exception
	{
		public :
			const char* what(void) const noexcept override {
				return "Grade is too high!";
			}
	};

	class GradeTooLowExecption : std::exception
	{
		public :
			const char* what(void) const noexcept override {
				return "Grade is too low!";
			}
	};

	class FormNotSigned : std::exception
	{
		public :
			const char* what(void) const noexcept override {
				return "The form is not signed!";
			}
	};

	class GradeTooLowExecute : std::exception
	{
		public :
			const char* what(void) const noexcept override {
				return "Grade is too low to execute!";
			}
	};

	void beSigned(Bureaucrat &employe);
	int getGradeToSign() const;
	int getGradeToExecute() const;
	bool isSigned(void) const;
	std::string getName(void) const;
};

std::ostream &operator<<(std::ostream &stream, const AForm &employe);