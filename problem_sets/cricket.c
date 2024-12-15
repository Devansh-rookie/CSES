#include <stdio.h>
#include <string.h>

typedef struct cricket {
  char player_name[20];
  char team_name[20];
  float batting_avg;
} cricketer;



int main(void) {
  int i = 0, j = 0, n = 10;
    cricketer player[50];
  for (i = 0; i < n; i++) {
    printf("\n Enter Player Name : ");
    scanf("%s", player[i].player_name);
    printf("\n Enter Team Name : ");
    scanf("%s", player[i].team_name);
    printf("\n Enter Batting Average : ");
    scanf("%f", & player[i].batting_avg);
  }

  return 0;
}

