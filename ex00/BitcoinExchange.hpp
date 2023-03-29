/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:38:56 by malbrand          #+#    #+#             */
/*   Updated: 2023/03/28 12:53:12 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>

class BitcoinExchange
{
	private :
				std::map<std::string, float> _map;

	public :
	//**********************************************************************//
	//							CONSTRUCTOR                                 //
	//**********************************************************************//
				BitcoinExchange(void);
				BitcoinExchange(const BitcoinExchange&);
	//**********************************************************************//
	//							 DESTRUCTOR                                 //
	//**********************************************************************//
				virtual ~BitcoinExchange(void);
	//**********************************************************************//
	//							  OPERATOR                                  //
	//**********************************************************************//
				BitcoinExchange	&operator=(const BitcoinExchange&);
};

#endif
