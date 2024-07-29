/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 08:58:50 by mel-houd          #+#    #+#             */
/*   Updated: 2024/07/29 09:42:18 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class	Bureaucrat
{
	public:
		// canonical form :
		Bureaucrat(std::string name, unsigned int grade);
		~Bureaucrat();
		Bureaucrat&	operator=(const Bureaucrat& other);
		Bureaucrat(const Bureaucrat& other);
		// getters :
		std::string		getName() const;
		unsigned int	getGrade() const;
		//setters :
		void			incrGrade();
		void			decrGrade();
		// exeptions :
		 class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const _NOEXCEPT;
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const _NOEXCEPT;
		};
		
	private:
		const std::string	name;
		unsigned int		grade;
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj);

#endif