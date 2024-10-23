/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:19:34 by mel-houd          #+#    #+#             */
/*   Updated: 2024/10/23 21:44:10 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

double converter(const char *str, char **indicator)
{
	char				*end;
	void				*res[2];

	double r = std::strtod(str, &end);
	if(indicator)
		*indicator = end;
	return (r);
}


void	Scalar::convert(const char *input)
{
	char	*gg;

	double	d = converter(input, &gg);
	float	f = static_cast<float>(converter(input, &gg));
	int		i =  static_cast<int>(converter(input, &gg));
	char	c = static_cast<char>(converter(input, &gg));
	int		len = strlen(input);

	if (gg[0] == '\0' && len != 0)
	{
		std::cout << "double: " << d << std::endl;
		std::cout << "float: " << f << std::endl;
		std::cout << "int: ";
		if (d > INT_MAX || d < INT_MIN)
			std::cout << "impossible" << std::endl;
		else
			std::cout << i << std::endl;
		std::cout << "char: ";
		if (d < -127 || d > 127)
			std::cout << "impossible";
		else if (d < 32 || d == 127)
			std::cout << "not displayable";
		else
			std::cout << c << std::endl;
	}
	else
	{
		std::cout << "double: " << "impossible" << std::endl;
		std::cout << "float: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		if (len == 1)
		{
			std::cout << len << std::endl;
			std::cout << "char: " << input[0] << std::endl;	
		}
		else
			std::cout << "char: " << "impossible" << std::endl;
			
	}
}