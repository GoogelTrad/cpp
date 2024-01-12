/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 00:29:18 by cmichez           #+#    #+#             */
/*   Updated: 2024/01/08 00:29:18 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string target;
public:
	RobotomyRequestForm(std::string _target);
	RobotomyRequestForm(const RobotomyRequestForm &copy);
	~RobotomyRequestForm();

	void execute(const Bureaucrat & executor) const;

	std::string getTarget(void) const;

	RobotomyRequestForm operator=(const RobotomyRequestForm &copy);
};
