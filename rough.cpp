#include<iostream>
#include<numeric>

using namespace std;

int throw_dias(){
  vector<int> dias = {10,2,3,4,25,30,7,14};
  int ans;
  cin>>ans;
  // static bool seeded = false;
  //   if (!seeded) {
  //     srand(time(0));
  //     seeded = true;
  //   }
  // int random_index = rand() % dias.size();
  //return dias[random_index];
  return ans;

}

int enter_board(int &throws, vector<int> &moves, int& po){
  int po_count =0;
  for(int i =0;i<moves.size();i++){
    if(moves[i]== 2 || moves[i] == 3 || moves[i]== 4){
      po_count++;
    }
    else if(moves[i] == 2 || moves[i] == 3 || moves[i] == 4){
      po_count = 0;
    }
    else if(moves[i] == 7 || moves[i] == 14){
      
    }
  }
  int safe_values = 0;
  while(po<3){
    int value = throw_dias();
    cout<<"throw number "<<throws<<" value is: "<<value<<endl;
    throws++;
    if(value == 10 || value == 25 || value == 30){
      po++;
      moves.push_back(value);
      cout<<"the number moves till now: "<<accumulate(moves.begin(),moves.end(),0)<<endl;
    }
    else if(value == 2 || value == 3 || value == 4){
      moves.push_back(value);
      throws++;
      cout<<"the number moves till now: "<<accumulate(moves.begin(),moves.end(),0)<<endl;
      break;
    }
    else if(value == 7 || value == 14){
      moves.push_back(value);
      throws++;
      safe_values++;
      cout<<"the number moves till now: "<<accumulate(moves.begin(),moves.end(),0)<<endl;
      // how to account for this??
    }
  }
  if(po == 3){
    po = 0;
    moves.clear();
    cout<<"Reset moves to: "<<accumulate(moves.begin(),moves.end(),0)<<endl;
    enter_board(throws,moves,po);
  }
  return accumulate(moves.begin(),moves.end(),0);
}


int main(){
  int first_move_value = throw_dias();
  int throws = 1,final_blocks_move=0, po=0;
  vector<int> moves;
  moves.push_back(first_move_value);
  cout<<"throw number "<<throws<<" value is: "<<first_move_value<<endl;
  if(first_move_value == 2 || first_move_value == 3 || first_move_value == 4){
    cout<<"can't enter the board!"<<endl;
  }
  else if(first_move_value == 10 || first_move_value == 25 || first_move_value == 30){
    po =1;
    final_blocks_move = enter_board(throws,moves,po);
  }
  else{
    // call another function
  }
  cout<<"total number of blocks it can move: "<<final_blocks_move;
}