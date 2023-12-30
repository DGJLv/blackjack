#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

class Deck{
public: 
void shuffling(int& numOfDecks); // random generate number 1-52 without repetition and push back to array
int dealCard(); // first card  (card[0]), card[i+1] = card[i] and resize size-1
// call dealCard() in member functions of Player class
//output int of the cardValue e.g. diamond 7: 20
private:
vector<int> card;
};


