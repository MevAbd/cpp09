/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:38:56 by malbrand          #+#    #+#             */
/*   Updated: 2023/03/29 16:10:19 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <utility>
# include <cstdlib>
# include <iostream>
# include <sstream>
# include <fstream>

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
	//**********************************************************************//
	//							  MEMBER FONCTION                           //
	//**********************************************************************//
				void	getMap(void);
				float	getDate(std::string date);
				void		convert(char *av, BitcoinExchange & btc);
		
};

#endif
