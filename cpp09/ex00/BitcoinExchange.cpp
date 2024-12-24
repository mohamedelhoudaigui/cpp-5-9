/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 23:58:01 by mel-houd          #+#    #+#             */
/*   Updated: 2024/12/24 03:09:45 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


BitcoinParser::BitcoinParser()
{
	std::fstream		file;
	std::string			Token;

	file.open(DATA_FILE);
	if (file.is_open() == false)
	{
		std::cerr << "error openning data file" << std::endl;
		exit(1);
	}
	std::getline(file, Token);
	while (std::getline(file, Token))
	{
		size_t		pos = Token.find(',');
		std::string	value = Token.substr(0, pos);
		double		key = strtod(Token.substr(pos + 1, Token.size()).c_str(), NULL);
		data[key] = value;
	}
}

static std::string trim(const std::string& str)
{
    size_t start = str.find_first_not_of(" \t\n\r\f\v");
    if (start == std::string::npos) return "";

    size_t end = str.find_last_not_of(" \t\n\r\f\v");
    return (str.substr(start, end - start + 1));
}

void	BitcoinParser::Feed(const char* input_file)
{
	std::fstream		file;
	std::string			Token;

	file.open(input_file);
	if (file.is_open() == false)
	{
		std::cerr << "error openning data file" << std::endl;
		exit(1);
	}
	std::getline(file, Token);
	while (std::getline(file, Token))
	{
		size_t	pos = Token.find('|');
		std::string	value = trim(Token.substr(0, pos));
		long	key = strtol(trim(Token.substr(pos + 1, Token.size())).c_str(), NULL, 10);
		input[key] = value;
		std::cout << key << " -> " << input[key] << std::endl;
	}
}


