#include "PmergeMe.hpp"


int main(int ac, char **av) {

  if (ac == 1) {
    std::cerr << "error , need args" << std::endl;
    exit(1);
  }

  try {

    struct timeval start, end;
    MergeInsertion<std::vector> a;
    MergeInsertion<std::deque>  b;

    gettimeofday(&start, NULL);
    a.entry_point(ac, av, true);
    gettimeofday(&end, NULL);
    double microseconds1 = ((end.tv_sec - start.tv_sec) * 1000000) + (end.tv_usec - start.tv_usec);
    std::cout << std::fixed << std::setprecision(5) <<
    "Time to process a range of " <<  a.get_size()  << " elements with std::vector : " <<
    (microseconds1 / 1000000) << " us" << std::endl;


    gettimeofday(&start, NULL);
    b.entry_point(ac, av, false);
    gettimeofday(&end, NULL);
    double microseconds2 = ((end.tv_sec - start.tv_sec) * 1000000) + (end.tv_usec - start.tv_usec);
    std::cout << std::fixed << std::setprecision(5) <<
    "Time to process a range of " << b.get_size() << " elements with std::dueue : " <<
    (microseconds2 / 1000000) << " us" << std::endl;

  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  return (0);
}
