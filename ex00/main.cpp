/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:10:56 by malbrand          #+#    #+#             */
/*   Updated: 2023/03/28 12:35:32 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (0);
	}
	std::string db = "./data.csv";
 	BitcoinExchange btc;
 	BitcoinExchange blop(btc);
	//btc.display(db, av[1]);
	(void)av;
	return (0);
}
