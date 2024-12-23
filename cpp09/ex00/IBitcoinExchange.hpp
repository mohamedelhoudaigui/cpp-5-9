/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IBitcoinExchange.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 00:14:27 by mel-houd          #+#    #+#             */
/*   Updated: 2024/12/14 00:22:39 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IBITCOIN
#define IBITCOIN

class IBitcoinParser
{
	public:
		virtual void	ReadData() const = 0;
		virtual void	ParseData() const = 0;
		virtual void	CheckData() const = 0;
		virtual ~IBitcoinParser(){};

};


#endif