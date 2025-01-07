#include "PmergeMe.hpp"

int main(int ac, char **av) {

  if (ac == 1) {
    cerr << "error , need args" << endl;
    exit(1);
  }

  try {
    MergeInsertion<vector> a;

    a.buffer_input(ac, av);
    a.split_input();
    a.sort_pairs();
    a.insertion_sort();
    a.seperate_chain();
    a.merge_insert();

    //    a.print_vector(a.get_input(), "Before");
    //  a.print_vector(a.get_result(), "After");

  } catch (const std::exception &e) {
    cerr << e.what() << endl;
  }

  return (0);
}
