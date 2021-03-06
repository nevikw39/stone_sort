mt19937 _rand((random_device())()); // create an object with random seed that generates random numbers using Mersenne Twister Algo

class Solution
{
private:
    int quickselect(vector<int>::iterator begin, vector<int>::iterator end, int k)
    {
        int n = end - begin;
        if (n <= 1)
            return *begin;
        auto itr = begin, pivot = end - 1;
        swap(*pivot, *(begin + (_rand() % n + n) % n)); // randomly pick pivot
        for (auto jtr = begin; jtr != pivot; jtr++)
            if (*jtr < *pivot)
                swap(*itr++, *jtr);
        swap(*itr, *pivot);
        if (k < itr - begin)
            return quickselect(begin, itr, k);
        else if (k == itr - begin)
            return *itr;
        else                                                         // the size of less part is (itr - begin) ans pivot alse counts
            return quickselect(itr + 1, end, k - (itr - begin) - 1); // so the k-th in origin is (k - (itr - begin) - 1) in greater part
    }

public:
    int findKthLargest(vector<int> &nums, int k)
    {
        return quickselect(nums.begin(), nums.end(), nums.size() - k);
    }
};