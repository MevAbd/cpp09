/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:10:56 by malbrand          #+#    #+#             */
/*   Updated: 2023/03/29 16:02:36 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	try
	{
		if (ac != 2)
			throw "Error: need one file.";

		BitcoinExchange btc;
		btc.getMap();
		btc.convert(av[1], btc);
	}
	catch(const char *s)
	{
		std::cerr << s << std::endl;
	}
	return (0);
}
