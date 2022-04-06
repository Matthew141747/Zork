#include "diceroll.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
   // seed the random number generator
   // do it once, do it before generating a random number
   srand((unsigned) time(0));

   double total_number_of_rolls { };
   double total_number_of_sixes { };
   int again                    { };

   while (true)
   {
      int number_of_rolls { };
      int roll            { };

      do
      {
         roll = rand() % 6 + 1;

         std::cout << roll << ' ';

         number_of_rolls++;
      }
      while (roll != 6);
      std::cout << "\t(number of rolls): " << number_of_rolls << "\n\n";

      total_number_of_rolls += number_of_rolls;

      total_number_of_sixes += 1;

      std::cout << "Do you want to go again? (Enter a number, 0 to quit): ";
      std::cin >> again;
      std::cout << '\n';

      if (again == 0) { break; }
   }

   std::cout << "Total number of sixes: " << total_number_of_sixes << '\n';
   std::cout << "Total number of rolls: " << total_number_of_rolls << '\n';
   std::cout << "Average number of rolls: " << total_number_of_rolls / total_number_of_sixes << '\n';
}
