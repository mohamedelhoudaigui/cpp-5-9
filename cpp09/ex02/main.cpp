#include "PmergeMe.hpp"


int main(int ac, char **av) {

  if (ac == 1) {
    std::cerr << "error , need args" << std::endl;
    exit(1);
  }

  try {
    MergeInsertion<std::vector> a;
    MergeInsertion<std::deque>  b;
    a.entry_point(ac, av);
    b.entry_point(ac, av);

  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  return (0);
}
