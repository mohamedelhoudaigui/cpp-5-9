#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <cstdlib>
#include <utility>
#include <set>

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::deque;
using std::cerr;
using std::pair;
using std::set;

class MergeInsertion
{
  public:
    void        split_input(vector<long>& input);
    void        sort_pairs();
    void        insertion_sort();
    void        seperate_chain();
    long        jacobsthal(int n);
    vector<int> generate_jacobsthal_sequence(int n);
    int         binary_search(const vector<long>& arr, long target, int left, int right);
    void        insert_pending_elements();

  private:
    vector<pair<long, long> >  chain;
    vector<long>  main_chain;
    vector<long>  pend_chain;
    long          reminder;
};

long convert(char *s);
