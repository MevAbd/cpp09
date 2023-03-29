/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:41:21 by malbrand          #+#    #+#             */
/*   Updated: 2023/03/28 22:10:48 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	try
	{
		if (ac < 2)
			throw "Error";

		PmergeMe	mergeme;
		mergeme.ftSort(ac, av);
	}
 	catch(const char *str)
 	{
 		std::cerr << str << std::endl;
 	}
}
