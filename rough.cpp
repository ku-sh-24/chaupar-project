#include<iostream>
#include<numeric>

using namespace std;

int throw_dias(){
  vector<int> dias = {10,2,3,4,25,30,7,14};
  // int ans;
  // cin>>ans;
  static bool seeded = false;
    if (!seeded) {
      srand(time(0));
      seeded = true;
    }
  int random_index = rand() % dias.size();
  return dias[random_index];
  //return ans;
}

int analyse(vector<int>& moves){
  // make a new array
  int po_count = 0;
  int continous_count =0, paase_count =0, total_paase = 0;
  for(int i=0;i<moves.size();i++){
    if(moves[i] == 10 || moves[i] == 25 || moves[i] == 30){
      continous_count++;
      paase_count++;
      total_paase++;
    }
    if(moves[i] == 7 || moves[i] == 14){
      continous_count = 0;
      // need to make the case that if the next three are 10/25/30 
    }
    if(continous_count == 3 || continous_count > 7){
      paase_count =0;
    }
    if(total_paase == 7){
      total_paase = 7;
    }
  }
  for(int i=0;i<moves.size();i++){
    if(moves[i] == 10 || moves[i] == 25 || moves[i] == 30){
      po_count++;
    }
  }
  return paase_count;
}

vector<int> play(){
  vector<int> moves;
  while(true){
    int value;
    cin>>value;
    //int value = throw_dias();
    if(value == 3 || value==2 || value==4){
      moves.push_back(value);
      break;
    }
    moves.push_back(value);
  }
  return moves;
} 

// the function below was an approach i was taking, wasnt very fruitful let's try another way to approach the problem
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
  vector<int> moves;
  moves = play();
  int final_moves;
  final_moves = analyse(moves);
  for(int i =0; i<moves.size();i++){
    cout<<moves[i]<<" ";
  }
  cout<<endl;
  cout<<"the total number of applicable 10/25/30 are: "<<final_moves;
}