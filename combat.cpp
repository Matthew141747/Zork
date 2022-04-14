#include "combat.h"
int combat::phealth = 100;

inline int combat::showPlayerhp(){
    return phealth;
}

int combat::showMonsterhp(){
    return mhealth;
}



combat::combat(int attackValue, int defenceValue):attackValue(attackValue),defenceValue(defenceValue)
{

    mhealth = 40;
    try{
        int action;
        cout << "enter an action (1 = Attack)";
        cin >> action;
        if(action != 1){
            MyException z;
            throw z;
        } else
            while (true) {
            mhealth = mhealth - attackValue;



            }

             while(mhealth > 1 && phealth > 1);



    }
    catch(exception& e){
         cout << e.what();
     }


}

