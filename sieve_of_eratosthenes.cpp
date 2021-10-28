//
// Simple "Sieve of Eratosthenes" by SowaZ3
//

#include <iostream>
#include <vector>

int main()
{
    std::vector <int> primes;
    int low_range, high_range;
    bool trigger = true;    // allows 2 in primes vector

    std::cout << "Enter a low and high range (an integers, scope 2 to 99999, separate them with a space)\n";

    std::cin >> low_range >> high_range;

    while(std::cin.fail() || low_range < 2 || high_range > 99999)  // err catching
    {
      std::cin.clear();
      std::cin.ignore();
      std::cout << "Bad entry. Follow the above recommendations :)\n";
      std::cin >> low_range >> high_range;
    }

    for (int i = 2; i < high_range || trigger; i++)    // checks for divisibility by lower primes. 2 is first prime number
    {
        for (int j = 0; j < primes.size(); j++)
        {
            trigger = true;
            if (i % primes[j] == 0){ trigger = false; break;}
        }

        if (trigger) primes.push_back(i);   // Adds a new prime to vecotr

    }

    std::cout << "\n";

    for (int i = 0; i < primes.size(); i++) // printer
    {
        if (primes[i] >= low_range) std::cout << primes[i] << "\n";
    }

    system("pause");    // if the console closes automatically

    return 0;
}
