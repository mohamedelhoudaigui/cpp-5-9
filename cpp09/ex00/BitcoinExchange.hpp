/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 23:57:59 by mel-houd          #+#    #+#             */
/*   Updated: 2024/12/25 04:32:13 by mel-houd         ###   ########.fr       */
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
		std::map<long, double>	data; //date -> bitcoin_price
};

#endif