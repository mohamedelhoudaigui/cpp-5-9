/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:19:43 by mel-houd          #+#    #+#             */
/*   Updated: 2024/10/01 17:27:51 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cerrno>

class Scalar {
	private:
		Scalar();
		Scalar(const Scalar& other);
		Scalar& operator=(const Scalar& other);

	public:
		static void convert(std::string& litt);
};



#endif