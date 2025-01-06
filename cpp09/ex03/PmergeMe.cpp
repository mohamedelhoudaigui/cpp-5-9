
#include "PmergeMe.hpp"

void    print_vector(const std::vector<long>& vec, std::string title)
{
    std::cout << title << " : ";
    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

long    convert(char *s)
{
    char  *pos;
    long res = std::strtol(s, &pos, 10);
    if (*pos != '\0')
        throw std::runtime_error("error converting number");
    if (res < 0)
        throw std::runtime_error("error negative number");
    return (res);
}


void  MergeInsertion::split_input(vector<long>& input)
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

void  MergeInsertion::sort_pairs()
{
    for (int i = 0; i < chain.size(); ++i)
    {
        if (chain[i].first < chain[i].second)
        {
            long tmp = chain[i].first;
            chain[i].first = chain[i].second;
            chain[i].second = tmp;
        }
    }
}

void  MergeInsertion::insertion_sort()
{
    for (int i = 1; i < chain.size(); ++i)
    {
        pair<long, long> key = chain[i];
        int j = i - 1;
        while (j >= 0 && chain[j].first > key.first)
        {
            chain[j + 1] = chain[j];
            j = j - 1;
        }
        chain[j + 1] = key;
    }
}

void  MergeInsertion::seperate_chain()
{
    bool  first = true;
    for(int i = 0; i < chain.size(); ++i)
    {
        if (first == true)
        {
            main_chain.push_back(chain[i].second);
            main_chain.push_back(chain[i].first);
            first = false;
        }
        else
        {
            main_chain.push_back(chain[i].first);
            pend_chain.push_back(chain[i].second);
        }
    }
}

 // Generate nth Jacobsthal number
long    MergeInsertion::jacobsthal(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

// Generate Jacobsthal sequence up to n
vector<int> MergeInsertion::generate_jacobsthal_sequence(int n)
{
    vector<int> sequence;
    int i = 0;

    while (true)
    {
        long j = jacobsthal(i);
        if (j >= n) break;
        sequence.push_back(j);
        i++;
    }
    return sequence;
}

// Binary search to find insertion position
int MergeInsertion::binary_search(const vector<long>& arr, long target, int left, int right)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return left;
}

 // Insert pending elements using Jacobsthal sequence
void    MergeInsertion::insert_pending_elements()
{
    // Generate Jacobsthal sequence for insertion positions
    vector<int> jacobsthal_pos = generate_jacobsthal_sequence(pend_chain.size());

    // Create set of all positions
    set<int> remaining_positions;
    for (int i = 0; i < pend_chain.size(); i++)
    {
        remaining_positions.insert(i);
    }

    // Remove Jacobsthal positions from set
    for (int pos : jacobsthal_pos)
    {
        if (pos < pend_chain.size())
        {
            remaining_positions.erase(pos);
        }
    }

    // Create final insertion sequence
    vector<int> insertion_sequence = jacobsthal_pos;
    for (int pos : remaining_positions)
    {
        insertion_sequence.push_back(pos);
    }

     // Perform insertions
    for (int i : insertion_sequence)
    {
        if (i >= pend_chain.size()) continue;

        int insert_pos = binary_search(main_chain, pend_chain[i], 0, main_chain.size() - 1);
        main_chain.insert(main_chain.begin() + insert_pos, pend_chain[i]);      
    }

    // Handle reminder if it exists
    if (reminder != -1)
    {
        int insert_pos = binary_search(main_chain, reminder, 0, main_chain.size() - 1);
        main_chain.insert(main_chain.begin() + insert_pos, reminder);
    }
}

const std::vector<long>&    MergeInsertion::get_result()
{
    return (main_chain);
}
