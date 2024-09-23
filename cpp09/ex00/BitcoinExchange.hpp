/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 02:08:13 by cmichez           #+#    #+#             */
/*   Updated: 2024/02/24 02:08:13 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <map>


class BitcoinExchange
{
	private:
		std::map<std::string, double> data;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);

		BitcoinExchange &operator=(const BitcoinExchange &copy);

		std::map<std::string, double> getDataValues();
		std::map<std::string, double> getMap();

		bool isDate(std::string date);
		void finalPrinting(const char* file);
		double chooseDate(std::string date);
		bool isDateOkay(std::string date);
		~BitcoinExchange();

};