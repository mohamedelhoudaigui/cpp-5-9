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
    template<typename T>
    void                        split_input(T<long>& input)
    {
        this->reminder = -1;
        if (input.size() % 2 != 0)
        {
            reminder = input.back();
            input.pop_back();
        }
        for (int i = 0; i < input.size(); ++i)
        {
            if (i % 2 == 1)
            {
                pair<long, long>  s(input[i - 1], input[i]);
            chain.push_back(s);
        }
    }


    }
    void                        sort_pairs();
    void                        insertion_sort();
    void                        seperate_chain();
    long                        jacobsthal(int n);
    vector<int>                 generate_jacobsthal_sequence(int n);
    int                         binary_search(const vector<long>& arr, long target, int left, int right);
    void                        insert_pending_elements();
    const std::vector<long>&    get_result();

  private:
    vector<pair<long, long> >  chain;
    vector<long>  main_chain;
    vector<long>  pend_chain;
    long          reminder;
};

long    convert(char *s);
void    print_vector(const std::vector<long>& v, std::string title);

