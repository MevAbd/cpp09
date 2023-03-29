/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:43:53 by malbrand          #+#    #+#             */
/*   Updated: 2023/03/28 13:05:50 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//**********************************************************************//
//							  CONSTRUCTOR                               //
//**********************************************************************//
BitcoinExchange::BitcoinExchange(void)
{
	std::cout << "CONSTRUCTOR BITCOIN IS CALLED" << std::endl;
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
	std::cout << "DESTRUCTOR BITCOIN IS CALLED" << std::endl;
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
