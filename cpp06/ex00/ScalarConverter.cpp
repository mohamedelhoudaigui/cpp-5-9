/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:19:34 by mel-houd          #+#    #+#             */
/*   Updated: 2024/10/19 16:58:34 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool	AllNumbers(const char *str)
{
	if (strlen(str) == 0)
		return false;
	int	point = 0;
	for (int i = 0; i < strlen(str); ++i)
	{
		if (str[i] == '.')
		{
			if (i == 0 || i == strlen(str) - 1 || point >= 0)
				return false; 
			point ++;
		}
		else if (str[i] < '0' || str[i] > '9') 
		{
			if (str[i] != '+' && str[i] != '-')
				return false;	
		}
	}
	return true;
}

int	Scalar::ToInt(const char *str, bool c)
{
	if (c == true)
		std::cout << "int : ";
	long res = std::atol(str);
	if (res > INT_MAX || res < INT_MIN || !AllNumbers(str))
	{
		if (c == true)
			std::cout << "impossible" << std::endl;
		return (-1);
	}
	else
	{
		if (c == true)
			std::cout << res << std::endl;
	}
	return (res);
}

void	Scalar::ToFloat(const char *str)
{
	std::cout << "float : ";

	char	*end;
	float res = std::strtof(str, &end);
	if (end != &str[strlen(str)] || strlen(str) == 0 || str[0] == ' ' || str[0] == '\t')
	{
		std::cout << "impossible";
	}
	else
		std::cout  << res << 'f';
	std::cout << std::endl;
}

void	Scalar::ToDouble(const char *str)
{
	char	*end;
	std::cout << "double : ";
	float res = std::strtod(str, &end);
	if (end != &str[strlen(str)] || strlen(str) == 0 || (str[0] == ' ' || str[0] == '\t'))
	{
		std::cout << "impossible";
	}
	else
		std::cout  << res;
	std::cout << std::endl;
}

void	Scalar::ToChar(const char *str)
{
	std::cout << "char: ";
	if (strlen(str) == 1)
	{
		if ((str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z'))
		{
			std::cout << str << std::endl;
			return ;	
		}
	}

	int res = ToInt(str, false);

	if (res < 0 || res > 127)
	 	std::cout << "impossible";
	else if (res < 32 || res == 127)
		std::cout << "not displayable";
	else
		std::cout << static_cast<char>(res);
	std::cout << std::endl;
}

void	Scalar::convert(const char *input)
{
	ToChar(input);
	ToInt(input, true);
	ToFloat(input);
	ToDouble(input);
}