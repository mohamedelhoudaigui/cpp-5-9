/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:19:34 by mel-houd          #+#    #+#             */
/*   Updated: 2024/10/01 17:45:42 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

Scalar::Scalar() {}
Scalar::Scalar(const Scalar& other) {}
Scalar& Scalar::operator=(const Scalar& other) {return *this;}


int	*ToInt(std::string& litt, bool ToChar) {
	int	*res = new(int);
	*res = std::atoi(litt.c_str());
	if (!ToChar) {
		if (errno == 0)
			std::cout << "int: " << *res << '\n';
		else
			std::cout << "int: impossible\n";
	}
	if (errno != 0)
	{
		delete res;
		return NULL;
	}
	return res;
}

void	ToFloat(std::string& litt) {
	std::cout << "float: ";
	float res = std::strtod(litt.c_str(), NULL);
	if (errno == 22 && res == 0) {
		std::cout << "impossible\n";
	} else {
		std::cout << std::fixed << std::setprecision(1) << res << 'f' << '\n';	
	}
}

void	ToDouble(std::string& litt) {
	std::cout << "double: ";
	double res = std::strtod(litt.c_str(), NULL);
	if (errno == 22 && res == 0) {
		std::cout << "impossible\n";
	} else {
		std::cout << std::fixed << std::setprecision(1) << res << '\n';	
	}
}

void	ToChar(std::string& litt) {
	std::cout << "Char: ";

	if (litt.length() == 1 && isalpha(litt[0])) {
		std::cout << litt[0] << '\n';
	} else {
		int	*res = ToInt(litt, true);
		if (res == NULL || *res < 0 || *res > 127){
			std::cout << "impossible\n";
		} else if (*res < 32 || *res > 126) {
			std::cout <<  "not displayable\n";
		}else {
			std::cout << '\'' <<char(*res) << '\'' <<  '\n';
		}
		delete res;
	}
}

void	Scalar::convert(std::string& litt) {
	ToChar(litt);
	ToInt(litt, false);
	ToFloat(litt);
	ToDouble(litt);
}