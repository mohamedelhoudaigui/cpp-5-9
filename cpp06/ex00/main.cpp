/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:19:18 by mel-houd          #+#    #+#             */
/*   Updated: 2024/10/18 14:19:07 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	tester()
{
	Scalar::convert("");
	std::cout << "----------------------" << std::endl;
	Scalar::convert("8.9");
	std::cout << "----------------------" << std::endl;
	Scalar::convert("48");
	std::cout << "----------------------" << std::endl;
	Scalar::convert("0");
	std::cout << "----------------------" << std::endl;
	Scalar::convert("1");
	std::cout << "----------------------" << std::endl;
	Scalar::convert("-1");
	std::cout << "----------------------" << std::endl;
	Scalar::convert("217483648f");
	std::cout << "----------------------" << std::endl;
	Scalar::convert("214748364899999999989988789898977896689767679869786978698698669899");
	std::cout << "----------------------" << std::endl;
	Scalar::convert("inf");
	std::cout << "----------------------" << std::endl;
	Scalar::convert("nan");
	std::cout << "----------------------" << std::endl;
}

int	main(int ac, char **av) {
	//if (ac == 2)
	//{
	//	std::string s(av[1]);
	//	Scalar::convert(s);
	//	return 0;
	//}
	//std::cout << "usage : ./convert {value}" << std::endl;
	tester();
	return 1;
}

