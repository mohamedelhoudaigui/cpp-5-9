/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:16:29 by mel-houd          #+#    #+#             */
/*   Updated: 2024/10/10 09:17:52 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <iostream>

template<typename T>
class Array {
public:
    Array() : size_(0), stockage(NULL) {}

    Array(unsigned int size) : size_(size) {
        stockage = new T[size_];
    }

    ~Array() {
        delete[] stockage;
    }

    Array(const Array& other) : size_(other.size_) {
        stockage = new T[size_];
        for (unsigned int i = 0; i < size_; ++i) {
            stockage[i] = other.stockage[i];
        }
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] stockage;
            size_ = other.size_;
            stockage = new T[size_];
            for (unsigned int i = 0; i < size_; ++i) {
                stockage[i] = other.stockage[i];
            }
        }
        return *this;
    }

    const T& operator[](unsigned int index) const {
        if (index >= size_) {
            throw std::out_of_range("index out of range");
        }
        return stockage[index];
    }

    unsigned int size() const {
        return size_;
    }

private:
    unsigned int size_;
    T* stockage;
};

#endif