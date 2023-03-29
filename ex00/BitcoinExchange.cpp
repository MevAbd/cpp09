/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:43:53 by malbrand          #+#    #+#             */
/*   Updated: 2023/03/29 16:19:47 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//**********************************************************************//
//							  CONSTRUCTOR                               //
//**********************************************************************//
BitcoinExchange::BitcoinExchange(void)
{
	return;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &rhs)
{
	*this = rhs; 
}

//**********************************************************************//
//							  DESTRUCTOR                                //
//**********************************************************************//
BitcoinExchange::~BitcoinExchange(void)
{
	return;
}

//**********************************************************************//
//							  OPERATOR                                  //
//**********************************************************************//
BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	this->_map = rhs._map;
	return *this;
}
//**********************************************************************//
//					          FONCTION                                  //
//**********************************************************************//

int	dateValid(std::string date)
{
	int y,m,d;
	std::string tmp;

	y = std::atoi(date.substr(0,4).c_str());
	m = std::atoi(date.substr(5,2).c_str());
	d = std::atoi(date.substr(8,2).c_str());
	if(y > 2023 || m > 12 || d > 31)
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return (0);
	}
	return (1);
}

//**********************************************************************//
//					   MEMBER FONCTION                                  //
//**********************************************************************//
void	BitcoinExchange::getMap(void)
{
	std::ifstream	file("data.csv");
    std::string 	line;

    if (!file.is_open())
	{
        throw "Error: can't opening.";
    }
	while (std::getline(file, line))
    {
        double 				value;
        std::string 		dateStr;
        std::stringstream	lineStream(line);

        std::getline(lineStream, dateStr, ',');
        lineStream >> value;
        _map[dateStr] = value;
    }
    file.close();
}

void	BitcoinExchange::convert(char  *av, BitcoinExchange &btc)
{
	std::ifstream	file;

	file.open(av);
	if (!file)
	{
        throw "Error: can't opening your 2n file.";
    }

	std::string		line;
	std::string		date;
	std::string 	value;
	while (std::getline(file, line))
	{
		date = line.substr(0,10);
		if (!dateValid(date))
			continue;
		value = line.substr(12,5);
		if (value == "")
		{
			std::cout << "Error: didn't find a number => " << date << std::endl;
			continue;
		}
		else
		{
			float	ret = std::atof(value.c_str());
			if(ret < 0)
			{
				std::cout << "Error: not a positive number." << std::endl;
				continue;
			}
			if(ret > 1000)
			{
				std::cout << "Error: too large a number." << std::endl;
				continue;
			}
			ret = ret * btc.getDate(date);
			std::cout << date << " => " << value << " = " << ret << std::endl;
		}
	}
	file.close();
}

float	BitcoinExchange::getDate(std::string date)
{
	std::map<std::string, float>::iterator it = this->_map.begin();
	std::string	check = it->first;
	while(it != this->_map.end())
	{
		if(date > check)
			it++;
		if(date == check)
			return(this->_map.find(check)->second);
		if (date < check)
			return(this->_map.find(check)->second);
		check = it->first;
	}
	return(this->_map.find(check)->second);
}
