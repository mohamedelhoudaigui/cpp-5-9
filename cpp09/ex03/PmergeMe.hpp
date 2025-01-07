#include <cstdlib>
#include <deque>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using std::cerr;
using std::cout;
using std::deque;
using std::endl;
using std::pair;
using std::set;
using std::string;
using std::vector;

template <template <typename> typename T> class MergeInsertion {
public:
  MergeInsertion() : reminder(-1) {}

  void print_vector(const T<long> &v, string title) {
    std::cout << title << " : ";
    for (int i = 0; i < v.size(); ++i) {
      std::cout << v[i] << " ";
    }
    std::cout << std::endl;
  }

  long convert(char *s) {
    char *pos;
    long res = std::strtol(s, &pos, 10);
    if (*pos != '\0')
      throw std::runtime_error("error converting number");
    if (res < 0)
      throw std::runtime_error("error negative number");
    return (res);
  }

  void buffer_input(int ac, char **av) {
    for (int i = 1; i < ac; ++i) {
      long res = convert(av[i]);
      input.push_back(res);
    }
  }

  void split_input() {
    if (input.size() % 2 != 0) {
      reminder = input.back();
      input.pop_back();
    }
    for (int i = 0; i < input.size(); ++i) {
      if (i % 2 == 1) {
        chain.push_back(pair<long, long>(input[i - 1], input[i]));
      }
    }
  }

  void sort_pairs() {
    for (int i = 0; i < chain.size(); ++i) {
      if (chain[i].first < chain[i].second) {
        long tmp = chain[i].first;
        chain[i].first = chain[i].second;
        chain[i].second = tmp;
      }
    }
  }

  void insertion_sort() {
    for (int i = 1; i < chain.size(); ++i) {
      pair<long, long> key = chain[i];
      int j = i - 1;
      while (j >= 0 && chain[j].first > key.first) {
        chain[j + 1] = chain[j];
        j = j - 1;
      }
      chain[j + 1] = key;
    }
  }

  void seperate_chain() {
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

  long jacobsthal(int n) {
    if (n == 0)
      return 0;
    if (n == 1)
      return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
  }

  vector<int> generate_jacobsthal_sequence(int n) {
    vector<int> sequence;
    int i = 0;

    while (true) {
      long j = jacobsthal(i);
      if (j >= n)
        break;
      sequence.push_back(j);
      i++;
    }
    return sequence;
  }

  int binary_search(T<long> &arr, long target, int left, int right) {
    // Handle empty array case
    if (right < left)
      return 0;

    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (arr[mid] == target)
        return mid; // Found exact match
      else if (arr[mid] < target)
        left = mid + 1;
      else
        right = mid - 1;
    }
    return left; // This is the insertion point
  }

  void merge_insert() {
    vector<int> jacob = generate_jacobsthal_sequence(pend_chain.size());
    for (int i = 0; i < jacob.size(); ++i)
      cout << jacob[i] << " ";
    cout << endl;
  }

  const T<long> &get_input() { return (input); }
  const T<long> &get_result() { return (main_chain); }

private:
  vector<long> input;
  T<pair<long, long>> chain;
  T<long> main_chain;
  T<long> pend_chain;
  long reminder;
};
