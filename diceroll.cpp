#include "diceroll.h"
//preprocessor directive
//operator overloading attempt
#define random rand() % 6 +1
using namespace d;



diceRoll::diceRoll(int a, int b){
    a = redDie;
    b = blueDie;
    /*
    diceRoll operator + (diceRoll const &obj){
        diceRoll res;
        res.redDie = redDie + obj.redDie;
        res.blueDie = blueDie + obj.blueDie;
        return res;

    }*/
}


int diceRoll::roll()
{

   // seed the random number generator



    srand ((unsigned) time(0));

   while (true)
   {
      int number_of_rolls { };
      int roll            { };

      do
      {
         roll = random;

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

   add <int>(2, 4, 8);
   add <double>(44, 55, 66);


   std::cout << "Total number of sixes, you attacked with maximum damage for each 6 rolled: " << total_number_of_sixes << '\n';
   std::cout << "Total number of rolls: " << total_number_of_rolls << '\n';

   return 0;

}

