#include <bits/stdc++.h>

#include <vector>
#include <algorithm>
using namespace std;
bool is_prime(int num)
{
    if (num <= 1)
    {
        return false;
    }
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n1, n2;
    std::cout << "Enter the range (n1, n2): ";
    std::cin >> n1 >> n2;

    std::vector<int> prime_numbers;
    for (int num = n1; num < n2; num++)
    {
        if (is_prime(num))
        {
            prime_numbers.push_back(num);
        }
    }

    if (prime_numbers.empty())
    {
        std::cout << "No prime numbers found in the given range." << std::endl;
    }
    // else if(prime_numbers.size()==1){
    //     return prime_numbers[0];
    // }
    else
    {
            int sum_diff = std::accumulate(prime_numbers.begin(), prime_numbers.end(), 0,
                                        [max_val = *std::max_element(prime_numbers.begin(), prime_numbers.end())](int sum, int num)
                                        {
                                            return sum + max_val - num;
                                        });
            if(prime_numbers.size()==1) sum_diff = prime_numbers[0];

            sum = sum_diff;

        std::cout << "Sum of differences between the largest array element and each of the remaining array element is: " << sum_diff << std::endl;yyyy
    }

    return 0;
}