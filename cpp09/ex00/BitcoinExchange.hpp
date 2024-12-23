/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 23:57:59 by mel-houd          #+#    #+#             */
/*   Updated: 2024/12/14 00:21:52 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN
#define BITCOIN

#include <string>
#include <fstream>
#include <map>

#include "IBitcoinExchange.hpp"


class BitcoinParser : public IBitcoinParser
{
	public:
		BitcoinParser(std::string data_file, std::string input_file);
		

	private:
		std::map<int, std::string> input;
		std::map<int, std::string> data;
};

#endif