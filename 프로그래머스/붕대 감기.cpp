#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
  int s_time = bandage[0];
  int s_heal = bandage[1];
  int a_heal = bandage[2];

  int sz_attacks = attacks.size();
  int i = 0;
  int cont_skill = 0;

  int max_health = health;

  int cur_time = 0;  // 현재 시간

  while (true) {
    if (attacks[i][0] == cur_time) {
      // 공격 받음
      health -= attacks[i][1];
      cont_skill = 0;
      i++;
      if (health <= 0) return -1;
    } else {
      health += s_heal;
      cont_skill++;
      if (cont_skill == s_time) {
        cont_skill = 0;
        health += a_heal;
      }
      if (health >= max_health) {
        health = max_health;
      }
    }

    if (cur_time == attacks[sz_attacks - 1][0]) break;
    cur_time++;
  }

  return health;
}