#include "player.h"
void Player::newHand(Deck& deck, int repeat){
value = 0;
int num = 0;
inGame = true;
for(int i = 0; i < repeat; i++){
int cardval = deck.dealCard();
valueSet(cardval, value);}
if (value == 21){
cout<< "Blackjack, You win!"<<endl;
inGame = false;
}
}

void Player::hitMe(Deck& deck){
int cardval = deck.dealCard();
valueSet(cardval, value);
if (value > 21){
ifWin = false;}
if (!ifWin) {
cout <<"House busts! You lose." << std::endl;
inGame = false;
ifWin = true;
}

}

void Player::stand(Deck& deck){
do{
int cardval = deck.dealCard();
valueSet(cardval, value);
}while(value<17);
if (value > 21){
getValue();
ifWin = false;}
if (!ifWin) {
cout <<"House busts! You win." << std::endl;
ifWin = true;
}inGame = false;
    }
    
void Player::hint(int playerVal, int dealerVal){
ifstream inFile("suggestion.txt");
string line;
vector<vector<char>> hints;
while (getline(inFile, line)) {
    vector<char> row;
    for (char c : line) {
        row.push_back(c);
    }
    hints.push_back(row);
}
cout << endl;
    if(5<=playerVal && playerVal<=7){
    playerVal = 0;}
    else if(7<playerVal && playerVal<=17){
    playerVal-=7;}
    else if(17<playerVal){
    playerVal = 10;}
    int rowIdx = playerVal;
    int colIdx = dealerVal - 2;
    char hintChar = hints[rowIdx][colIdx];
    string hintStr;
    if (hintChar == 'H' || hintChar == 'h' || hintChar == 'D' || hintChar == 'd') {
        hintStr = "Hit";
    } else if (hintChar == 'S' || hintChar == 's') {
        hintStr = "Stand";
    } else {
        hintStr = "No suggestion available";
    }cout << "Suggestion: ["<< hintStr <<"]" <<endl;
cout << "^^^^^^^^^^^^^^^^Dealer Card^^^^^^^^^^^^^^^^" << endl;
cout << "Player 2 3 4 5 6 7 8 9 10 A" << endl;
for (int i = 7; i <= 17; i++) {
    cout << setw(4) << i << ":  ";
    for (int j = 0; j < 10; j++) {
            cout << hints[i - 7][j] << " ";
        }cout << endl;
    }
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    

    
    }
    
int Player::valueSet(int cardValue, int& value){
        int iResult = (cardValue-1)/13;
        switch (iResult){
            case 0:
                cout <<"picked a club";
                printCardNumber(cardValue);
                break;
            case 1:
                cout << "picked a diamond";
                printCardNumber(cardValue);
                break;
            case 2:
                cout << "picked a heart";
                 printCardNumber(cardValue);
                break;
            case 3:
                cout << "picked a spades";
                 printCardNumber(cardValue);
                break;
            
        }
        if(10<=cardValue%13||cardValue%13==0){
        value += 10;}
        else if(cardValue%13==1){
        if (value <= 10){
        value += 11;}
        else if (value >10){
        value += 1;}}
        else{ value += cardValue%13;}

    return value;
}

void Player::printCardNumber(int number){
    int cardNumber = number%13;
    string storeCardNumber = to_string(cardNumber);
    switch (cardNumber){
        case 1:
            cout << " of Ace"<<endl;
            break;
        case 11: 
                cout << " of Jack"<<endl;
                break;
        case 12:
                cout << " of Queen"<<endl;
                break;
        case 0:
                cout << " of King"<<endl;
                break;
    default:
        cout << " of " << storeCardNumber <<endl;
    }
}

int Player::getValue(){
    return value;}
    
void Player::setValue(int init){
    value = init;
}
