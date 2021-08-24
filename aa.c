#include <stdio.h>
#include <stdlib.h>
 
struct param
{
  char name[8];
  int life, attack, defense;
};
 
void act(struct param* actor, struct param* target, int command)
{
  int point;
  switch (command)
  {
    case 0:
      point = actor->attack - target->defense;
      target->life -= point;
      printf("%s attacks! %s takes %d damage points!\n", actor->name, target->name, point);
      break;
    case 1:
      point = 20;
      actor->attack += point;
      printf("%s casts Boost! %s's Attack increases by %d!\n", actor->name, actor->name, point);
      break;
    case 2:
      point = 50;
      actor->life += point;
      printf("%s casts Heal! %s's Life increases by %d!\n", actor->name, actor->name, point);
      break;
  }
}
 
int main(void)
{
  struct param you = { "Kuina", 100, 100, 100 };
  struct param enemy = { "Demon", 100, 100, 100 };
  printf("%s appears!\n", enemy.name);
  for (; ; )
  {
    int command;
    printf("%s: Life=%d, Attack=%d, Defense=%d\n", you.name, you.life, you.attack, you.defense);
    printf("%s: Life=%d, Attack=%d, Defense=%d\n", enemy.name, enemy.life, enemy.attack, enemy.defense);
    printf("(0) Attack\n(1) Boost\n(2) Heal\n");
    printf("Command:");
    scanf("%d", &command);
    act(&you, &enemy, command);
    if (enemy.life <= 0)
    {
      printf("%s is defeated!\n", enemy.name);
      return 0;
    }
    act(&enemy, &you, rand() % 3);
    if (you.life <= 0)
    {
      printf("%s has been killed...\n", you.name);
      return 0;
    }
  }
}
