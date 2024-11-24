/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:16:29 by mel-houd          #+#    #+#             */
/*   Updated: 2024/11/23 00:15:49 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <iostream>

template<typename T>
class Array
{
	public:
		Array() : _size(0), _stockage(NULL) {}

		Array(unsigned int size) : _size(size)
		{
			_stockage = new T[_size];
		}

		~Array()
		{
			delete[] _stockage;
		}

		Array(const Array& other) : _size(other.size())
		{
			T*	OtherStockage = other.GetStockage();

			_stockage = new T[_size];
			for (unsigned int i = 0; i < _size; ++i)
			{
				_stockage[i] = OtherStockage[i];
			}
		}

		Array& operator=(const Array& other)
		{
			if (this == &other)
				return (*this);

			unsigned int	OtherSize = other.size();
			T*              OtherStockage = other.GetStockage();

			this->_size = OtherSize;
			delete[] _stockage;
			this->_stockage = new T[_size];

			for (unsigned int i = 0; i < _size; ++i)
			{
				_stockage[i] = OtherStockage[i];
			}
			return (*this);
		}

		const T& operator[](unsigned int index) const
		{
			if (index >= _size)
			{
				throw std::out_of_range("index out of range");
			}
			return _stockage[index];
		}

		T& operator[](unsigned int index)
		{
			if (index >= _size)
			{
				throw std::out_of_range("index out of range");
			}
			return _stockage[index];
		}

		unsigned int size() const
		{
			return (_size);
		}

		T*          GetStockage() const
		{
			return (this->_stockage);
		}

	private:
		unsigned int    _size;
		T*              _stockage;
};

#endif