/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 23:06:58 by mel-houd          #+#    #+#             */
/*   Updated: 2024/12/23 05:08:39 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN & other)
{
	*this = other;
}

RPN& RPN::operator=(const RPN & other)
{
	if (this != &other)
	{
		this->Input = other.GetInput();
	}
	return (*this);
}

const std::stack<int>&	RPN::GetInput() const
{
	return (Input);
}

// ----------------------------------


static int	DoOp(int a, int b, char op)
{
	switch (op)
	{
		case '+':
			return a + b;
			break;

		case '-':
			return a - b;
			break;

		case '*':
			return a * b;
			break;

		case '/':
		{
			if (b == 0)
				throw std::runtime_error("divide by zero");
			return a / b;
		}
	}
	return 0;
}

void	RPN::Parse(const char* input)
{
	std::string	data(input);

    std::stringstream	ss(data);
    std::string			token;
    
    while (std::getline(ss, token, ' '))
	{
        if (!token.empty())
		{
			if (token == "+" || token == "-" || token == "+" || token == "/")
			{
				if (Input.size() < 2)
				{
					std::cerr << "stack size smaller than 2 elements" << std::endl;
					exit(1);
				}
				int	n1 = Input.top();
				Input.pop();
				int	n2 = Input.top();
				Input.pop();
				try
				{
					int res = DoOp(n1, n2, token[0]);
					Input.push(res);
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
					exit(1);
				}
			}
			else if (token.size() == 1 && isdigit(token[0]) != 0)
			{
				Input.push(token[0] - '0');
			}
			else
			{
				std::cerr << "Invalid token: " << token << std::endl;
			}
        }
    }
	if (Input.size() != 1)
	{
		std::cerr << "Error" << std::endl;
	}
}