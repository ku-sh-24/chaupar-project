#include<iostream>
#include<vector>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
using namespace std;

// take the input of the number of people playing


int throw_dias(){
  // here we will put a random value into the length 7 vector
  // sum the number of 1s we get 
  // compare the values (use switch clause)
  // return the final number of spaces to move
  vector<int> dias = {10,2,3,4,25,30,7,14};
  static bool seeded = false;
    if (!seeded) {
      srand(time(0));
      seeded = true;
    }
  int random_index = rand() % dias.size();
  // for (int i = 0; i < 7; ++i) {
  //   dias[i] = rand() % 2; // Generate random number (0 or 1)
  // }
  cout<<"YOUR ROLL LOOKS LIKE THIS: ";
  cout<<dias[random_index];
  // for (int i = 0; i < dias.size(); ++i) {
  //   sum += dias[i];
  //   cout << dias[i] << " ";
  // }
  cout<<endl;
  // switch (dias[random_index]) {
  // case 0:
  //   // all 0s
  //   cout<<"ALL OF THEM ARE CLOSED! YOU GOT THE SPECIAL ONE: ";
  //   return 7;
  // case 1:
  //   // only one 1
  //   cout<<"ONLY ONE IS OPEN!: ";
  //   return 10;
  // case 2:
  //   // two open
  //   cout<<"ONLY TWO ARE OPEN!: ";
  //   return 2;
  // case 3:
  //   // 3 open
  //   cout<<"ONLY THREE ARE OPEN!: ";
  //   return 3;
  // case 4:
  //   // 4 open OR 4 1s
  //   cout<<"ONLY FOUR ARE OPEN!: ";
  //   return 4;
  // case 5:
  //   // 5 open OR 5 1s
  //   cout<<"AYYAY! FIVE ARE OPEN! KYA PASAAA AYA HAI: ";
  //   return 25;
  // case 6:
  //   // 6 open OR 6 1s
  //   cout<<"AYYAY! SIX ARE OPEN! KYA PASAAA AYA HAI: ";
  //   return 30;
  // case 7:
  //   // 7 open OR 7 1s
  //   cout<<"ALL OF THEM ARE CLOSED! YOU GOT THE SPECIAL ONE: ";
  //   return 14;
  // }
  return dias[random_index];
}

void board(){
  for(int row=1;row<20;row++){
    for(int col =1;col<20;col++){
      if((row == 10 && col ==  9) || (row == 10 && col ==  10) || (row == 10 && col ==  11) || (row == 9 && col ==  9)
      || (row == 9 && col ==  10) || (row == 9 && col ==  11) || (row == 11 && col ==  9) || (row == 11 && col ==  10) || (row == 11 && col ==  11))
       cout<<"   ";
      else if(col == 9 || col == 10 || col == 11 || row == 9 || row == 10 || row == 11) cout<<" _ ";
      else cout<<"   ";
    }
    cout<<endl;
  }
}
int Pawn_on_board(vector<bool>& arr){
  // passing the player number
  //  passing its array of bools
  // 1 -> the pawn has enterd the game
  int count_pawns =0;
  for(int i=0;i<arr.size();i++){
    if(arr[i] == 1){
      count_pawns++;
    }
  }
  return count_pawns; // returns the number of pawns currently in the game
}


int enter_board(int player_num){
  int po =0;
  int moves = 0;

  int dias_value = throw_dias();
  if(dias_value ==  2 || dias_value == 3 || dias_value == 4){
    cout<<"no po => give chance to next player"<<endl;
  }
  else if(dias_value == 10 || dias_value == 25 || dias_value == 30){
    // call another function
    
  }
  else if(dias_value == 7 || dias_value == 14){
    // call another function
  }
}

int main(){
  // int number_of_players;
  // cout<<"enter the number of players: ";
  //cin>>number_of_players;
  // while(number_of_players>4 || number_of_players<2){
  //   cout<<"Number of players can only be 2, 3 or 4: ";
  //   cin>>number_of_players;
  // }
  cout<<"PLAYER 1: BLUE"<<endl;
  cout<<"PLAYER 2: GREEN"<<endl;

  vector<bool>player1_pawns(4);
  vector<bool> player2_pawns(4); // initially all the pawns are labelled 0 i.e. none of them have entered the game yet
  
  int player1_pawns_on_boards = Pawn_on_board(player1_pawns); // this function is going to check if any of the pawns are on the board
  
  bool game_on= true; // this variable is going to decide when the game ends
  int turn[] = {1,2}; // since rn i am only considering two players, chances can be of player 1 or player 2
  int player_number_chance = 1; // starting with the chance of player1

  while(game_on){
    while(player_number_chance == 1){ // this is when player 1 rolls the dias
      int player1_sum =0; // counts the number of steps the player can move based on the rolls
      int paase_sum1 =0; // this variable keeps count of the number of 10/25/30  the player got, if it exceeds 3 it resets itself to 0

      switch (throw_dias()){
        case 0:
        player_number_chance++;
        break;
        case 1:
        player_number_chance++;
        break;
        case 2:
        player1_sum += 2;
        player_number_chance++;
        cout<<player1_sum<<endl;
        break;
        case 3:
        player1_sum += 3;
        player_number_chance++;
        cout<<player1_sum<<endl;
        break;
        case 4:
        player1_sum += 4;
        player_number_chance++;
        cout<<player1_sum<<endl;
        break;
        case 5:
        player_number_chance++;
        break;
        case 6:
        player_number_chance++;
        break;
        case 7:
        player_number_chance++;
        break;
      }
    }
    //game_on = false;
  while(player_number_chance == 2){ // this is when player 1 rolls the dias
    int player2_sum =0; // counts the number of steps the player can move based on the rolls
    int paase_sum2 =0; // this variable keeps count of the number of 10/25/30  the player got, if it exceeds 3 it resets itself to 0

    switch (throw_dias()){
      case 0:
      player_number_chance--;
      break;
      case 1:
      player_number_chance--;
      break;
      case 2:
      player2_sum += 2;
      player_number_chance--;
      cout<<player2_sum<<endl;
      break;
      case 3:
      player2_sum += 3;
      player_number_chance--;
      cout<<player2_sum<<endl;
      break;
      case 4:
      player2_sum += 4;
      player_number_chance--;
      cout<<player2_sum<<endl;
      break;
      case 5:
      player_number_chance--;
      break;
      case 6:
      player_number_chance--;
      break;
      case 7:
      player_number_chance--;
      break;
    }
  }
    game_on = false;
  }
}