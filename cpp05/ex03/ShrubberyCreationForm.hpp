/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 00:57:10 by cmichez           #+#    #+#             */
/*   Updated: 2024/01/08 00:57:10 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
	std::string target;
public:
	ShrubberyCreationForm(std::string _target);
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);
	~ShrubberyCreationForm();

	ShrubberyCreationForm operator=(const ShrubberyCreationForm &copy);
	std::string getTarget(void) const;

	void execute(const Bureaucrat & executor) const;
};

