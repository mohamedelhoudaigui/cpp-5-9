/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:19:43 by mel-houd          #+#    #+#             */
/*   Updated: 2024/10/23 21:28:57 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits.h>
#include <cstring>
#include <cstdio>
#include <float.h>

class Scalar {
	private:
		Scalar();
		static int	ToInt(const char *str, bool c);
		static void ToChar(const char *str);
		static void	ToFloat(const char *str);
		static void	ToDouble(const char *str);

	public:
		static void convert(const char* input);
};



#endif