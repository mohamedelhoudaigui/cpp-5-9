/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 23:58:01 by mel-houd          #+#    #+#             */
/*   Updated: 2024/12/25 05:29:54 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static	long convert_date(std::string date)
{
	std::stringstream	ss(date);
	std::string			Token;
	std::string			Tmp;
	int					n_tokens = 0;

	while (std::getline(ss, Token, '-'))
	{
		Tmp += Token;
		n_tokens++;
	}
	if (n_tokens != 3)
		throw std::runtime_error("wrong date format");
	char *pos;
	long res = std::strtol(Tmp.c_str(), &pos, 10);
	if (*pos != '\0')
		throw std::runtime_error("non digit char in date");
	return (res);
}

static double convert_value(std::string value)
{
	//for (int i = 0; i < value.size(); ++i)
	//{
	//	if (std::isdigit(value[i]) == 0 && value[i] != '-' && value[i] != '+')
	//}
	char	*pos;
	double	res= strtod(value.c_str(), &pos);
	if (*pos != '\0')
		throw std::runtime_error("non digit value");
	return (res);
}


static std::string trim(const std::string& str)
{
    size_t start = str.find_first_not_of(" \t\n\r\f\v");
    if (start == std::string::npos) return "";

    size_t end = str.find_last_not_of(" \t\n\r\f\v");
    return (str.substr(start, end - start + 1));
}

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
		long		date = convert_date(Token.substr(0, pos));
		double		price = strtod(Token.substr(pos + 1, Token.size()).c_str(), NULL);
		data[date] = price;
	}
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
		if (pos == std::string::npos)
		{
			std::cerr << "cant find separator |" << std::endl;
		}
		else
		{
			try
			{
				long	date = convert_date(trim(Token.substr(0, pos)));
				double	num_coins = convert_value(trim(Token.substr(pos + 1, Token.size())));
				double	price_at = data.lower_bound(date)->second;
				
				printf("date = %s, n bitcoins = %f , result = %f\n",
					Token.substr(0, pos).c_str(),
					num_coins,
					num_coins * price_at);	
				
			}
			catch (const std::exception& e)
			{
				std::cerr << e.what() << std::endl;	
			}
		}
	}
}


