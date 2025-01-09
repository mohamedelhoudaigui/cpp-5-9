#include <cstdlib>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

template<template<typename T, typename Alloc = std::allocator<T> > class Container>
class MergeInsertion {
  public:
    MergeInsertion() : reminder(-1) {};

    long convert(char *s)
    {
      char *pos;
      long res = std::strtol(s, &pos, 10);
      if (*pos != '\0')
          throw std::runtime_error("error converting number");
      if (res < 0)
          throw std::runtime_error("error negative number");
      return (res);
    }

    void print_container(Container<long>& v, std::string title)
    {
      std::cout << title << " : ";
      for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
      }
      std::cout << std::endl;
    }

    void  buffer_input(int ac, char **av)
    {
      for (int i = 1; i < ac; ++i) {
        long res = convert(av[i]);
        input.push_back(res);
      }
    }

    void  split_input()
    {
      if (input.size() % 2 != 0) {
        reminder = input.back();
        input.pop_back();
      }

      for (int i = 0; i < input.size(); ++i) {
        if (i % 2 == 1) {
            chain.push_back(std::pair<long, long>(input[i - 1], input[i]));
        }
      }
    }

    void  sort_pairs()
    {
      for (int i = 0; i < chain.size(); ++i) {
        if (chain[i].first < chain[i].second) {
            long tmp = chain[i].first;
            chain[i].first = chain[i].second;
            chain[i].second = tmp;
        }
      }
    }

    void  insertion_sort()
    {
      for (int i = 1; i < chain.size(); ++i) {
        std::pair<long, long> key = chain[i];
        int j = i - 1;
        while (j >= 0 && chain[j].first > key.first) {
            chain[j + 1] = chain[j];
            j = j - 1;
        }
        chain[j + 1] = key;
      }
    }

    void  seperate_chain()
    {
      bool first = true;
      for (int i = 0; i < chain.size(); ++i) {
        if (first == true) {
            main_chain.push_back(chain[i].second);
            main_chain.push_back(chain[i].first);
            first = false;
        } else {
            main_chain.push_back(chain[i].first);
            pend_chain.push_back(chain[i].second);
        }
      }
    }

    int   binary_search(long target)
    {
      int left = 0;
      int right = main_chain.size() - 1;
      
      if (main_chain.empty() || target <= main_chain[0]) 
          return 0;
      if (target > main_chain[right]) 
          return main_chain.size();

      while (left <= right) {
          int mid = left + (right - left) / 2;

          if (main_chain[mid] == target)
              return mid;

          if (main_chain[mid] < target &&
              (mid == main_chain.size() - 1 || main_chain[mid + 1] > target))
              return mid + 1;

          if (main_chain[mid] < target)
              left = mid + 1;
          else
              right = mid - 1;
      }
      return left;
    }

    void  pend_chain_setup()
    {
      Container<long> result;

      size_t groupSize = 2;
      size_t powerFactor = 2;

      for (size_t i = 0; i < pend_chain.size();) {
          Container<long>   group;
          for (size_t j = 0; i < pend_chain.size() && j < groupSize; i++, j++) {
              group.push_back(pend_chain[i]);
          }
          std::reverse(group.begin(), group.end());
          result.insert(result.end(), group.begin(), group.end());
          groupSize  = std::pow(2, powerFactor) - groupSize;
          powerFactor++;
      }
      pend_chain = result;
    }

    void  merge()
    {
      for (int i = 0; i < pend_chain.size(); ++i)
      {
          int pos = binary_search(pend_chain[i]);
          main_chain.insert(main_chain.begin() + pos, pend_chain[i]);
      }
      if (reminder != -1)
      {
          int pos = binary_search(reminder);
          main_chain.insert(main_chain.begin() + pos, reminder);
      }
    }

    void  entry_point(int ac, char **av)
    {
      buffer_input(ac, av);
      print_container(input, "before");
      split_input();
      sort_pairs();
      insertion_sort();
      seperate_chain();
      pend_chain_setup();
      merge();
      print_container(main_chain, "after ");
    }

  private:
    Container<long> input;
    Container<std::pair<long, long> > chain;
    Container<long> main_chain;
    Container<long> pend_chain;
    long reminder;
};
