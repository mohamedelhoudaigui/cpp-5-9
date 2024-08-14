/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:28:10 by mel-houd          #+#    #+#             */
/*   Updated: 2024/08/14 05:51:02 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	try
	{
		Bureaucrat a("test", 2);
		Form		fo("form", 1, 1);

		std::cout << fo;
		a.signForm(fo);
		std::cout << fo;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return(1);
	}
	return (0);
}