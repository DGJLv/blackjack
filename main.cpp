#include <iostream>
#include "player.h"
#include <stdlib.h>
using namespace std;

int main()
{
bool ifContinue = true;
int choice;
Player player;
Player dealer;
Deck deck;
cout<<"////////<< Blackjack >>////////"<<endl;
do{
cout << endl;
cout<<"==============================="<<endl;
cout << "Choose an option:" << endl;
cout << "1. New Hand" << endl;
cout << "2. Hit Me" << endl;
cout << "3. Stand" << endl;
cout << "4. Hint" << endl;
cout << "5. Exit" << endl;
cout<<"==============================="<<endl;
cout.flush();

cout<< "Your Choice? > ";
cin >> choice;


if (choice == 1){
    if (!player.inGame){
    int num = 0;
     deck.shuffling(num);
     cout<< "Player"<<endl;
     player.newHand(deck, 2); 
     cout<< "Dealer" <<endl;
     dealer.newHand(deck, 1);
     cout<<endl;
    cout<<"==============================="<<endl;
    cout<<"Player value: "<<player.getValue() <<endl;
    cout<<"Dealer value: "<<dealer.getValue() <<endl;
    cout<<"==============================="<<endl;
  }else if (player.inGame){
  cout<< "You are already in game. Choose another option."<<endl;
}}
else if(choice == 2){
    player.hitMe(deck);
    cout<<"==============================="<<endl;
    cout<<"Player value: "<<player.getValue() <<endl;
    cout<<"Dealer value: "<<dealer.getValue() <<endl;
    cout<<"==============================="<<endl;
}
else if(choice == 3){
    cout << "Dealer"<<endl;
    dealer.stand(deck);
    player.inGame = false;
    cout<<"==============================="<<endl;
    cout<<"Player value: "<<player.getValue() <<endl;
    cout<<"Dealer value: "<<dealer.getValue() <<endl;
    cout<<"==============================="<<endl;
    if((player.getValue()<=21) && (dealer.getValue()<=21)){
    if (player.getValue() == dealer.getValue()){ 
        std::cout << "Match!" << std::endl;
        }
    if(player.getValue() > dealer.getValue()){
        cout<< "You win" << endl;
        }
    else if (player.getValue() < dealer.getValue()){
        cout<< "You lose" << endl;
        }}
    player.setValue(0);
    dealer.setValue(0);
}
else if(choice == 4){
    cout<< "hint"<<endl;
    player.hint(player.getValue(),dealer.getValue());
}else if(choice == 5){
    exit(0);
}
}while(ifContinue);

return 0;
    }

    