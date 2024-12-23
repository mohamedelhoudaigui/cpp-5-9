/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 23:06:58 by mel-houd          #+#    #+#             */
/*   Updated: 2024/12/22 23:19:59 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


RNP::RNP() {}

RNP::~RNP() {}

RNP::RNP(const RNP & other)
{
	*this = other;
}

RNP& RNP::operator=(const RNP & other)
{
	if (this != &other)
	{
		this->Input = other.GetInput();
	}
}

const std::stack<int>&	RNP::GetInput() const
{
	return (Input);
}

// ----------------------------------


void	RNP::Parse(const char* input)
{
	std::string	data(input);

    std::stringstream	ss(data);
    std::string			token;
    
    while (std::getline(ss, token, ' '))
	{
        if (!token.empty())
		{
            Input.push(token)
        }
    }
}