#include "deck.h"

void Deck::shuffling(int& numOfDecks){
card.clear();
do{cout<< "how many decks you want to use?"<<endl;
cin>> numOfDecks;}while(numOfDecks>4);
for(int i = 1; i<=52; i++){
for(int j = 0; j<numOfDecks; j++){
card.push_back(i);    
}}
shuffle(card.begin(), card.end(),default_random_engine(random_device()()));}

int Deck::dealCard(){
int cardValue = card[0];
card.erase(card.begin());
return cardValue;}
