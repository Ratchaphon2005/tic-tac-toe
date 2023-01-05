#include <vector>

void draw(std::vector<int> player_a, std::vector<int> player_b);
bool check_win(std::vector<int> player);
bool check_position_available(std::vector<int> player_a, std::vector<int> player_b, int position);
int check_is_number_1_9(std::string check);
