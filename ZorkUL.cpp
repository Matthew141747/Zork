#include <iostream>

using namespace std;
#include "ZorkUL.h"
Room *ptr[9];
int main(int argc, char *argv[]) {
	ZorkUL temp;
	temp.play();
	return 0;
}

ZorkUL::ZorkUL() {
	createRooms();
}

void ZorkUL::createCharacters(){

};

void ZorkUL::createRooms()  {

    ptr[0] = new Room("a");
        ptr[0]->addItem(new Item("x", 1, 11));
        ptr[0]->addItem(new Item("y", 2, 22));

    ptr[1] = new Room("b");
        ptr[1]->addItem(new Item("xx", 1, 11));
        ptr[1]->addItem(new Item("yy", 1, 11));
    ptr[2] = new Room("c");
    ptr[3] = new Room("d");
    ptr[4] = new Room("e");
    ptr[5] = new Room("f");
    ptr[6] = new Room("g");
    ptr[7] = new Room("h");
    ptr[8] = new Room("i");


    // N S E W
    ptr[0]->setExits(ptr[5], ptr[1], ptr[3], ptr[2]);
    ptr[1]->setExits(NULL, NULL, NULL, ptr[0]);
    ptr[2]->setExits(NULL, ptr[0], NULL, NULL);
    ptr[3]->setExits(ptr[0], ptr[4], NULL, ptr[8]);
    ptr[4]->setExits(NULL, NULL, NULL, ptr[3]);
    ptr[5]->setExits(NULL, ptr[6], ptr[0], ptr[7]);
    ptr[6]->setExits(NULL, NULL, NULL, ptr[5]);
    ptr[7]->setExits(NULL, ptr[6], NULL, NULL);
    ptr[8]->setExits(NULL, ptr[3], NULL, NULL);

    currentRoom = ptr[0];


}

/**
 *  Main play routine.  Loops until end of play.
 */
void ZorkUL::play() {
	printWelcome();

	// Enter the main command loop.  Here we repeatedly read commands and
	// execute them until the ZorkUL game is over.

	bool finished = false;
	while (!finished) {
		// Create pointer to command and give it a command.
		Command* command = parser.getCommand();
		// Pass dereferenced command and check for end of game.
		finished = processCommand(*command);
		// Free the memory allocated by "parser.getCommand()"
		//   with ("return new Command(...)")
		delete command;
	}
	cout << endl;
	cout << "end" << endl;
}

void ZorkUL::printWelcome() {
	cout << "start"<< endl;
	cout << "info for help"<< endl;
	cout << endl;
	cout << currentRoom->longDescription() << endl;
    //cout << characterx->description() << endl;
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
bool ZorkUL::processCommand(Command command) {
	if (command.isUnknown()) {
		cout << "invalid input"<< endl;
		return false;
	}

	string commandWord = command.getCommandWord();
	if (commandWord.compare("info") == 0)
		printHelp();

	else if (commandWord.compare("map") == 0)
		{
        cout << "[h] --- [f] --- [g]" << endl;
		cout << "         |         " << endl;
        cout << "         |         " << endl;
		cout << "[c] --- [a] --- [b]" << endl;
		cout << "         |         " << endl;
		cout << "         |         " << endl;
		cout << "[i] --- [d] --- [e]" << endl;
		}

	else if (commandWord.compare("go") == 0)
		goRoom(command);

    else if (commandWord.compare("take") == 0)
    {
       	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
         if (command.hasSecondWord()) {
        cout << "you're trying to take " + command.getSecondWord() << endl;
        int location = currentRoom->isItemInRoom(command.getSecondWord());
        if (location  < 0 )
            cout << "item is not in room" << endl;
        else{
            cout << "item is in room" << endl;
            cout << "index number " << + location << endl;
            cout << endl;
            cout << currentRoom->longDescription() << endl;
        }

        }
    }

    else if (commandWord.compare("put") == 0)
    {

    }
    /*
    {
    if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
            if (command.hasSecondWord()) {
            cout << "you're adding " + command.getSecondWord() << endl;
            itemsInRoom.push_Back;
        }
    }
*/
    else if (commandWord.compare("quit") == 0) {
		if (command.hasSecondWord())
			cout << "overdefined input"<< endl;
		else
			return true; /**signal to quit*/
	}
	return false;
}
/** COMMANDS **/
void ZorkUL::printHelp() {
	cout << "valid inputs are; " << endl;
	parser.showCommands();

}

void ZorkUL::goRoom(Command command) {
	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
		return;
	}

	string direction = command.getSecondWord();

	// Try to leave current room.
	Room* nextRoom = currentRoom->nextRoom(direction);

	if (nextRoom == NULL)
		cout << "underdefined input"<< endl;
	else {
		currentRoom = nextRoom;
		cout << currentRoom->longDescription() << endl;
	}
}
//Teleport
/*void ZorkUL::teleportRoom(Command command) {
    if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
        return;
    }

     string direction = command.getSecondWord();

    // Try to leave current room.
    Room* nextRoom = currentRoom->nextRoom(direction);


        currentRoom = nextRoom;
        cout << currentRoom->longDescription() << endl;

}

*/
void ZorkUL::teleport(Command command)
{
     string s = command.getSecondWord();
     if(s.compare("east")||s.compare("west")||s.compare("north")||s.compare("south"))
     {
         this->goRoom(command);
     }
     else if(s.compare("a"))
     {
         currentRoom = ptr[0];
     }
     else if(s.compare("b"))
    {
         currentRoom = ptr[1];
     }
     else if(s.compare("c"))
     {
         currentRoom = ptr[2];
     }
     else if(s.compare("d"))
     {
         currentRoom = ptr[3];
     }
     else if(s.compare("e"))
     {
         currentRoom = ptr[4];
     }
     else if(s.compare("f"))
     {
         currentRoom = ptr[5];
     }
     else if(s.compare("g"))
     {
         currentRoom = ptr[6];
     }
     else if(s.compare("h"))
     {
         currentRoom = ptr[7];
     }
     else if(s.compare("i"))
     {
         currentRoom = ptr[8];
     }

     cout<<currentRoom->longDescription()<< endl;
}




/*
void ZorkUL::teleport(){

    currentRoom = ptr[0];
    cout << currentRoom->longDescription();

}
*/
string ZorkUL::go(string direction) {
	//Make the direction lowercase
	//transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
	//Move to the next room
	Room* nextRoom = currentRoom->nextRoom(direction);
	if (nextRoom == NULL)
		return("direction null");
	else
	{
		currentRoom = nextRoom;
		return currentRoom->longDescription();
	}
}
