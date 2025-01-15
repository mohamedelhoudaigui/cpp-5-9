/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 23:58:01 by mel-houd          #+#    #+#             */
/*   Updated: 2024/12/26 05:50:48 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinParser::~BitcoinParser() {}

BitcoinParser::BitcoinParser(const BitcoinParser &other) { *this = other; }

BitcoinParser &BitcoinParser::operator=(const BitcoinParser &other) {
  if (this != &other) {
    this->data = other.get_data();
  }
  return (*this);
}

const std::map<long, double> &BitcoinParser::get_data() const {
  return (this->data);
}

static double convert_double(std::string value) {
  char *pos;
  double res = strtod(value.c_str(), &pos);
  if (*pos != '\0')
    throw std::runtime_error("Error: non digit value");
  else if (res < 0)
    throw std::runtime_error("Error: negative value");
  return (res);
}

static long convert_long(std::string value) {
  char *pos;
  double res = strtol(value.c_str(), &pos, 10);
  if (*pos != '\0')
    throw std::runtime_error("Error: non digit value");
  else if (res < 0)
    throw std::runtime_error("Error: negative value");
  return (res);
}

static std::string trim(const std::string str) {
  size_t start = str.find_first_not_of(" \t\n\r\f\v");
  if (start == std::string::npos)
    return "";

  size_t end = str.find_last_not_of(" \t\n\r\f\v");
  return (str.substr(start, end - start + 1));
}

static int leap_year(long year) {
  return (!(year % 4) && (year % 100) && (year % 400));
}

static int get_days(long year, long month) {
  switch (month) {
  case 1:
    return 31;
  case 2:
    return leap_year(year) ? 29 : 28;
  case 3:
    return 31;
  case 4:
    return 30;
  case 5:
    return 31;
  case 6:
    return 30;
  case 7:
    return 31;
  case 8:
    return 31;
  case 9:
    return 30;
  case 10:
    return 31;
  case 11:
    return 30;
  case 12:
    return 31;
  default:
    return 0;
  }
  return (0);
}

static long check_year(std::string year) {
  long res = convert_long(year);
  return (res);
}

static long check_month(std::string month) {
  long res = convert_long(month);
  if (res == 0 || res > 12)
    throw std::runtime_error("Error: month value is wrong");
  return (res);
}

static long check_day(std::string day, long year, long month) {
  long res = convert_long(day);
  if (res == 0 || res > get_days(year, month))
    throw std::runtime_error("Error: wrong day value");
  return (res);
}

static long convert_date(std::string date) {
  std::stringstream ss(date);
  int n_tokens = 0;
  std::string Token;
  std::string day;
  std::string month;
  std::string year;

  while (std::getline(ss, Token, '-')) {
    if (n_tokens == 0)
      year = Token;
    else if (n_tokens == 1) {
      month = Token;
    } else if (n_tokens == 2)
      day = Token;
    n_tokens++;
  }
  if (n_tokens != 3 || year.empty() || month.empty() || day.empty())
    throw std::runtime_error("Error: wrong date format");

  long y = check_year(year);
  long m = check_month(month);
  check_day(day, y, m);
  long res = convert_long(year + month + day);
  return (res);
}

static long ser_date(std::string s) {
  std::string Tmp;
  std::string Token;
  std::stringstream ss(s);

  while (std::getline(ss, Token, '-')) {
    Tmp += Token;
  }

  return (strtol(Tmp.c_str(), NULL, 10));
}

BitcoinParser::BitcoinParser() {
  std::fstream file;
  std::string Token;

  file.open(DATA_FILE);
  if (file.is_open() == false) {
    std::cerr << "error openning data file" << std::endl;
    exit(1);
  }
  std::getline(file, Token);
  while (std::getline(file, Token)) {
    size_t pos = Token.find(',');
    long date = ser_date(Token.substr(0, pos));
    double price = strtod(Token.substr(pos + 1, Token.size()).c_str(), NULL);
    data[date] = price;
  }
}

void BitcoinParser::Feed(const char *input_file) {
  std::fstream file;
  std::string Token;

  file.open(input_file);
  if (file.is_open() == false) {
    std::cerr << "error openning data file" << std::endl;
    exit(1);
  }
  while (std::getline(file, Token)) {
    try {
      size_t pos = Token.find('|');
      std::string date_str = Token.substr(0, pos);
      std::string value_str = Token.substr(pos + 1, Token.size() - 1);

      if (pos == std::string::npos)
        throw std::runtime_error("Error: cant find separator");

      long date = convert_date(trim(date_str));
      if (date > data.rbegin()->first)
        date = data.rbegin()->first;
      double num_coins = convert_double(trim(value_str));

      if (num_coins > 1000.0)
        throw std::runtime_error("Error: too large a number");

      double price_at = data.lower_bound(date)->second;
      std::cout << trim(date_str) << " => " << num_coins << " = "
                << num_coins * price_at << std::endl;

    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }
}
