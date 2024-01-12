/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:43:46 by cmichez           #+#    #+#             */
/*   Updated: 2024/01/06 15:43:46 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	const std::string name;
	int grade;
public:
	Bureaucrat();
	Bureaucrat(int initialGrade, const std::string _name);
	Bureaucrat(const Bureaucrat &copy);
	~Bureaucrat();

	Bureaucrat &operator=(const Bureaucrat &copy);

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

	std::string getName(void) const;
	int getGrade(void) const;

	void downGrade(void);
	void upGrade(void);
	void signForm(Form *form);
};

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &employe);