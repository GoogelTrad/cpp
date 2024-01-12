/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:41:32 by cmichez           #+#    #+#             */
/*   Updated: 2024/01/09 15:41:32 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:
	
public:
	Intern();
	Intern(const Intern &copy);
	~Intern();

	class InvalidFormNameExecption : std::exception
	{
		public :
			const char* what(void) const noexcept override {
				return "Invalid name!";
			}
	};

	Intern &operator=(const Intern &copy);

	AForm *makeForm(std::string name, const std::string target) const;
};
