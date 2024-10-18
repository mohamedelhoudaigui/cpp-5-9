/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:19:18 by mel-houd          #+#    #+#             */
/*   Updated: 2024/10/18 12:28:39 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int ac, char **av) {
	if (ac == 2)
	{
		std::string s(av[1]);
		Scalar::convert(s);
		return ;
	}
	std::cout << "usage : ./convert {value}" << std::endl;
}
