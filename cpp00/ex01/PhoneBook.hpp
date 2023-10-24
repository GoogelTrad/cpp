/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:41:38 by cmichez           #+#    #+#             */
/*   Updated: 2023/10/23 23:41:38 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact rep[8];
public:
	PhoneBook();
	void add();
	void search();
	void exit();
	void affiche(Contact *ct);
	void limit(std::string str);
	Contact getInfo(int index);
	~PhoneBook();
};

#endif