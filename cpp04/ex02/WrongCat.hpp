/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 23:39:07 by cmichez           #+#    #+#             */
/*   Updated: 2023/12/20 23:39:07 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:
	/* data */
public:
	WrongCat();
	WrongCat(const WrongCat &copy);
	virtual ~WrongCat();

	WrongCat &operator=(const WrongCat &copy);

	void makeSound(void) const;
};
