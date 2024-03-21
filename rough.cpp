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
}

vector<int> play(){
  vector<int> moves;
  while(true){
    int value = throw_dias();
    if(value == 3 || value==2 || value==4){
      moves.push_back(value);
      break;
    }
    moves.push_back(value);
  }
  return moves;
} 

vector<int> analyse(vector<int>& moves){
  vector<int> final_moves;

  int moves_2_3_4 =0 ;
  vector<int> moves_10_25_30;
  vector<int> moves_7_14;

  int continous_count = 0;
  int total_paase =0;
  
  for(int i=0;i<moves.size();i++) // iterating through the rolls
  {
    if(moves[i] == 10 || moves[i] == 25 || moves[i] == 30)
    {
      int j =i;
      int count = 1;
      while(j+1<moves.size() && (moves[j+1] == 10 || moves[j+1] == 25 || moves[j+1] == 30)) // checks the continous occurance
      {
        count++;
        j++;
      }

     // cout<<"count: "<<count<<endl;
      if(count >=7) // more than 7 10/25/30 occur continously
      {
        for(int k =i;k<=i+6;k++){
          moves_10_25_30.push_back(moves[k]);
        }
        i=i+6;
        // else if((count)%3 == 0){
        //   i = j+1;
        //   cout<<endl;
        // }
        // else if((count)%3 == 1 && (count)%7 != 0){
        //   moves_10_25_30.push_back(moves[j]);
        //   i = j;
        // }
        // else if((count)%3 == 2){ // 2,5,8 -> insert the last 2 elements.
        //   moves_10_25_30.push_back(moves[j-1]);
        //   moves_10_25_30.push_back(moves[j]);
        //   i = j;
        // }
        count -= 7;
      }
      else if(count%3 == 0){ // 3,6,9
        i = j+1;
        cout<<endl;
      }
      else if(count %3 == 1){ //1,4,7 -> insert the last 1 element, special case when count == 7  
        moves_10_25_30.push_back(moves[j]);
        i = j;
        
      }
      else if(count%3 == 2){ // 2,5,8 -> insert the last 2 elements.
        moves_10_25_30.push_back(moves[j-1]);
        moves_10_25_30.push_back(moves[j]);
        i = j;
      }
  }
  if(moves[i] == 7 || moves[i] == 14)
  {
    continous_count = 0;
    total_paase =0;
    moves_7_14.push_back(moves[i]);
  }
}
  
  if(moves_7_14.size()!=0)
  {
    for (int i = 0; i < moves_7_14.size(); i++)
    {
      final_moves.push_back(moves_7_14[i]);
    }
  }

  if(moves_10_25_30.size()!=0)
  {
    for (int i = 0; i < moves_10_25_30.size(); i++)
    {
      final_moves.push_back(moves_10_25_30[i]);
    }
  }
  final_moves.push_back(moves[moves.size()-1]);

  return final_moves;
}

// till here the code is final!


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
  vector<int> rolls;
  vector<int> final;
  int po_count =0;
  rolls = play();
  for(int i =0; i<rolls.size();i++){
    cout<<rolls[i]<<" ";
  }
  cout<<endl;
  cout<<endl;
  cout<<"final playable moves: ";
  final = analyse(rolls);
  for(int i =0; i<final.size();i++){
    cout<<final[i]<<" ";
  }
  for(int i =0; i<final.size();i++){
    if(final[i] == 10 || final[i] == 25 || final[i] == 30){
      po_count++;
    }
  }
 cout<<"PO: "<<po_count<<endl;
}