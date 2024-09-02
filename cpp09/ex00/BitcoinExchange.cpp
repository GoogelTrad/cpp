/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 02:08:12 by cmichez           #+#    #+#             */
/*   Updated: 2024/02/24 02:08:12 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	this->data.insert(copy.data.begin(), copy.data.end());	
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	this->data.insert(copy.data.begin(), copy.data.end());	
	return *this;
}

std::map<std::string, double> BitcoinExchange::getMap()
{
	return this->data;
}

std::map<std::string, double> BitcoinExchange::getDataValues()
{
	std::string ligne;
	std::fstream fd;
	std::string date;
	double value;
	
	std::map<std::string, double> map;
	fd.open("data.csv", std::ios::in);
	std::getline(fd, ligne);

	if (ligne.compare("date,exchange_rate") != 0)
	{
		std::cout << "Wrong database type!" << std::endl;
		return map;
	}

	while (std::getline(fd, ligne))
	{
		date = ligne.substr(0, ligne.find(","));
		value = static_cast<double>(std::atof(ligne.substr(ligne.find(",") + 1).c_str()));
		map.insert(std::make_pair(date, value));
	}
	fd.close();
	return map;
}

void BitcoinExchange::finalPrinting(const char* file)
{
	std::fstream fd;
	std::string ligne;
	std::string date;
	double taux;
	double value;

	this->data = getDataValues();
	fd.open(file, std::ios::in);
	if (!fd)
	{
		std::cout << "File didn't open sucessfully!" << std::endl;
		return;
	}
	while (std::getline(fd, ligne))
	{
		date = ligne.substr(0, ligne.find(" "));

		if (this->isDate(date))
		{
			taux = this->chooseDate(date);
			value = static_cast<double>(std::atof(ligne.substr(ligne.find('|') + 1).c_str()));
			if (value < 0 || value > 1000)
				std::cout << "Error: Incorrect value must be between 0 and 1000." << std::endl;
			else
				std::cout << date << " => " << value << " = " << value * taux << std::endl;
		}
		else
			std::cout << "Bad input => " << date << std::endl;
	}
	fd.close();
}

bool BitcoinExchange::isDate(std::string date)
{
	int year;
	int month;
	int day;
	int cursor; 

	year = static_cast<int>(std::atoi(date.substr(0, date.find("-")).c_str()));
	cursor = date.find("-");
	month = static_cast<int>(std::atoi(date.substr(cursor + 1, date.find("-")).c_str()));
	cursor += date.find("-");
	day = static_cast<int>(std::atoi(date.substr(cursor, date.find("|")).c_str()));

	if (year < 0)
		return false;
	if (month < 1 || month > 12)
		return false;
	if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8
		|| month == 10 || month == 12) && day > 31)
		return false;
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;
	else if (month == 2)
	{
		if (year % 4 == 0 && day > 29)
			return false;
		else
		{
			if (day > 28)
				return false;
		}
	}
	return true;
}

double BitcoinExchange::chooseDate(std::string date)
{
	std::string res;
	std::map<std::string, double>::iterator it;

	it = this->data.lower_bound(date);
	if (it == this->data.begin())
		return 0;
	if (it == this->data.end())
	{
		it--;
		return it->second;
	}
	if (it->first == date)
		return it->second;

	it--;
	return it->second;
}
