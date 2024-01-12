/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:24:47 by cmichez           #+#    #+#             */
/*   Updated: 2024/01/07 17:24:47 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string target;
public:
	PresidentialPardonForm(std::string _target);
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	~PresidentialPardonForm();

	void execute(const Bureaucrat & executor) const;

	std::string getTarget(void) const;

	PresidentialPardonForm operator=(const PresidentialPardonForm &copy);
};

