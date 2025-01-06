#include "PmergeMe.hpp"


int main(int ac, char **av)
{
  if (ac == 1)
  {
    cerr << "error , need args" << endl;
    exit(1);
  }
  try
  {
    MergeInsertion  a;
    vector<long>  input;
    for (int i = 1; i < ac; ++i)
    {
      long res = convert(av[i]);
      input.push_back(res);
    }
    a.split_input(input);
    a.sort_pairs();
    a.insertion_sort();
    a.seperate_chain();
    a.insert_pending_elements();

    std::cout << "res : " << std::endl;
    for (int i = 0; i < a.)
  }
  catch (const std::exception& e)
  {
    cerr << e.what() << endl;
  }
  return (0);
}
