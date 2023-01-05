#include <iostream>
#include <vector>

void draw(std::vector<int> player_a, std::vector<int> player_b){
  int position = 1;
  char mark;
  for(int i = 1; i <= 3; i++){
    for(int j = 1; j <= 3; j++){
      for(int o = 0; o < player_a.size(); o++){
        if (player_a[o] == position){
          mark = 'A';
        }
      }
      for(int o = 0; o < player_b.size(); o++){
        if (player_b[o] == position){
          mark = 'B';
        }
      }
      if (mark == 'A'){
        std::cout << " \033[31mX " << " \u001b[0m| ";
      }
      else if (mark == 'B'){
        std::cout << " \u001b[36mO " << " \u001b[0m| ";
      }
      else{
        std::cout << " " << position << " " << " | ";
      }
      position++;
      mark = 'C';
    }
    std::cout << "\n-----------------\n";
  }
}

std::vector<int> sort(std::vector<int> player){
  std::vector<int> new_player;
  int min;
  int last = 0;
  for(int i = 0; i < player.size(); i++){
    min = 10;
    for (int j = 0; j < player.size(); j++){
      if (player[j] < min && player[j] > last){
        min = player[j];
      }
    }
    new_player.push_back(min);
    last = min;
  }
  return new_player;
}

bool check_win(std::vector<int> player){
  int win[8][3] = {{1,2,3},{1,4,7},{1,5,9},{2,5,8},{3,5,7},{3,6,9},{4,5,6},{7,8,9}};
  bool is_win = false;
  if(player.size() >= 3){
    player = sort(player);
    while(!is_win){
      for (int i1 = 0;i1 < player.size();i1++){
        for(int j = 0;j < 8;j++){
          if(win[j][0] == player[i1]){
            for (int i2 = i1+1;i2 < player.size();i2++){
              if(win[j][1] == player[i2]){
                for (int i3 = i2+1;i3 < player.size();i3++){
                  if(win[j][2] == player[i3]){
                    is_win = true;
                    break;
                  }
                }
              }
            }
          }
        }
      }
      break;
    }
    return is_win;
    }
  else{
    return false;
  }
}

bool check_position_available(std::vector<int> player_a, std::vector<int> player_b, int position){
  if (position == 0){
    return false;
  }
  for(auto & i : player_a){
    if (i == position){
      return false;
    }
  }
  for(auto & i : player_b){
    if (i == position){
      return false;
    }
  }
  return true;
}

int check_is_number_1_9(std::string check){
    int mark;
     for(auto & i : std::vector<std::string> {"1","2","3","4","5","6","7","8","9"}){
          if (i == check){
              mark = stoi(i);
              break;
            }
      else{
          if(i == "9"){
                mark = 0;
                break;
              }
            }
          }
      return mark;
}
