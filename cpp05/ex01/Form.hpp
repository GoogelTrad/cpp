/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
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

class Form
{
private:
	const std::string name;
	bool sign;
	const int gradeToSign;
	const int gradeToExecute;
public:
	Form();
	Form(std::string _name, int toSign, int toExecute);
	Form(const Form &copy);
	~Form();

	Form &operator=(const Form &copy);

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

	void beSigned(Bureaucrat &employe);
	int getGradeToSign() const;
	int getGradeToExecute() const;
	bool isSigned(void) const;
	std::string getName(void) const;
};

std::ostream &operator<<(std::ostream &stream, const Form &employe);