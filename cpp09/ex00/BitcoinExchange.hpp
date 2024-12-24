/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 23:57:59 by mel-houd          #+#    #+#             */
/*   Updated: 2024/12/24 03:09:31 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN
#define BITCOIN

#include <string>
#include <fstream>
#include <map>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

#define DATA_FILE "data.csv"

class BitcoinParser
{
	public:
		BitcoinParser();
		void	Feed(const char* input_file);
		

	private:
		std::map<double, std::string>	data;
		std::map<long, std::string>	input;
};

#endif