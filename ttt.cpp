#include <iostream>
#include <vector>
#include "ttt_functions.hpp"

int main() {
  std::vector<int> player_a;
  std::vector<int> player_b;
  int mark;
  std::string check;
  char player = 'A';
  char player_win;
  bool error_message = false;
  std::string play_again;
  system("clear");
  while (true){
  for(int i = 0; i < 9; i++){
    if (player == 'A'){
      while(true){
        system("clear");
        if(error_message){
          std::cout << "There position is not available!\n";
          error_message = false;
        }
        draw(player_a,player_b);
        std::cout << "Player A select number: ";
        std::cin >> check;
        mark = check_is_number_1_9(check);
      
        if (check_position_available(player_a,player_b,mark)){
          player_a.push_back(mark);
          player = 'B';
          if(check_win(player_a)){
            player_win = 'A';
          }
          break;
      }
      else{
        error_message = true;
      }
    }
    }
    else{
      while(true){
        system("clear");
        if(error_message){
          std::cout << "There position is not available!\n";
          error_message = false;
        }
        draw(player_a,player_b);
        std::cout << "Player B select number: ";
        std::cin >> check;
        mark = check_is_number_1_9(check);

        if (check_position_available(player_a,player_b,mark)){
          player_b.push_back(mark);
          player = 'A';
          if(check_win(player_b)){
            player_win = 'B';
        }
        break;
      }
      else{
        error_message = true;
      }
    }
  }
  if (player_win == 'A'){
      system("clear");
      draw(player_a,player_b);
      std::cout << "Player A Won!\n";
      break;
  }
  else if (player_win == 'B'){
      system("clear");
      draw(player_a,player_b);
      std::cout << "Player B Won!\n";
      break;
  }
  else{
      if (i == 8){
        system("clear");
        draw(player_a,player_b);
        std::cout << "Draw!!\n";
        break;
      }
  }
  }
  std::cout << "Do you want to play again? [yes or no]: ";
  std::cin >> play_again;
  if(play_again == "yes"){
    player_a.clear();
    player_b.clear();
    player = player_win;
    player_win = ' ';
    continue;
    }
  else{
    break;
    }
  }
  return 0;
}
