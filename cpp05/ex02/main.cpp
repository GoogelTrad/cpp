/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:09:35 by cmichez           #+#    #+#             */
/*   Updated: 2024/01/06 16:09:35 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

int main(void)
{
	Bureaucrat *Boss = new Bureaucrat(1, "CEO");
	std::cout << *Boss << std::endl;

	try
	{
		AForm *Pres = new PresidentialPardonForm("BoB");
		AForm *Shrub = new ShrubberyCreationForm("home");
		AForm *Robot = new RobotomyRequestForm("Henry");

		std::cout << *Pres << std::endl;
		std::cout << *Shrub << std::endl;
		std::cout << *Robot << std::endl;

		Boss->signForm(Pres);
		Boss->executeForm(*Pres);

		Boss->signForm(Shrub);
		Boss->executeForm(*Shrub);

		Boss->signForm(Robot);
		Boss->executeForm(*Robot);

		std::cout << *Pres << std::endl;
		std::cout << *Shrub << std::endl;
		std::cout << *Robot << std::endl;

		delete Pres;
		delete Shrub;
		delete Robot;
		delete Boss;
	}
	catch(AForm::GradeTooLowExecption& e) {
		std::cout << "Error " << e.what() << std::endl;
	}
	catch(AForm::GradeTooLowExecute &e) {
		std::cout << "Error " << e.what() << std::endl;
	}
	catch(AForm::FormNotSigned &e) {
		std::cout << "Error " << e.what() << std::endl;
	}	
	
	return 0;
}