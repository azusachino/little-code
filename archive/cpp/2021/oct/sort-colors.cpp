#include <vector>

using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        using std::swap;
        int size = nums.size();
        int second = size - 1, zero = 0;
        for (int i = 0; i <= second; ++i)
        {
            while (nums[i] == 2 && i < second)
            {
                swap(nums[i], nums[second--]);
            }
            while (nums[i] == 0 && i > zero)
            {
                swap(nums[i], nums[zero++]);
            }
        }
    }
};