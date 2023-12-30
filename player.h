#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include "deck.h"
using namespace std;

class Player{
public:
void newHand(Deck& deck, int repeat); // call dealcard to dealer and Player
//accept int 
void hitMe(Deck& deck); //call dealCard to get number //call valueSet to decide value
//if value > 21 return false and end program
void stand(Deck& deck);//call dealCard until value gets 17 or higher 
void hint(int playerVal, int dealerVal);//open hint file and match H D S //if H,h,D: hit S: stand
int valueSet(int cardValue, int& value);
int getValue();
void printCardNumber(int number);
void setValue(int init);
bool inGame = false;
private:
int value = 0;
bool ifWin = true;

};