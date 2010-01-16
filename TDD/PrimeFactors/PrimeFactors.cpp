#include "PrimeFactors.hpp"

//std::list<int> PrimeFactors::Generate(int n)
//{
//    std::list<int> primes;
//    if (n > 1)
//    {
//        int candidate = 2;
//        while (n > 1)
//        {
//            while (n % candidate == 0)
//            {
//                primes.push_back(candidate);
//                n /= candidate;
//            }
//            candidate++;
//        }
//        if (n > 1)
//        {
//            primes.push_back(n);
//        }
//    }
//    return primes;
//}

std::list<int> PrimeFactors::Generate(int n)
{
	std::list<int> primes;
    for (int candidate = 2; n > 1; candidate++)
    {
        for (; n % candidate == 0; n /= candidate)
        {
            primes.push_back(candidate);
        }
    }
    return primes;
}
