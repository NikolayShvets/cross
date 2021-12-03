#include <iostream>
#include <random>
#include <time.h>
using namespace std;

void instruction();
bool input();
bool checkWin();

char p1[30], p2[30];
char table[3][3];
bool step {true};

int main() {
  instruction();

  cout << "Имя игрока 1: ";
  cin.getline(p1, 30);
  cout << "Имя игрока 2: ";
  cin.getline(p2, 30);

  srand(time(NULL));
  step = rand() % 2 == 0;

  while (!checkWin()){
    if (!input()) {
      cout << "Вы ввели неверные данные, повторите ...";
    }
  }

  if (step) cout << "Победил " << p2;
  else cout << "Победил " << p1;
}

void instruction(){
  cout << "Игра в крестики-нолики. Правила все знают." << endl;
  table[0][0] = '1'; table[0][1] = '2'; table[0][2] = '3';
  table[1][0] = '4'; table[1][1] = '5'; table[1][2] = '6';
  table[2][0] = '7'; table[2][1] = '8'; table[2][2] = '9'; 
}

bool input(){
  for (int i = 0; i < 3; ++i){
    for(int j = 0; j < 3; ++j){
      cout << "| " << table[i][j] << " ";
    }
    cout << "| " << endl;
  }

  if (step) cout << "Ходит " << p1 << ": ";
  else cout << "Ходит " << p2 << ": ";

  int n;
  cin >> n;
  if (n < 1 or n > 9)
    return false;

  int i, j;
  if (n % 3 == 0) {
    i = n / 3 - 1;
    j = 2;
  }
  else {
    i = n / 3;
    j = n % 3 - 1;
  }

  if (table[i][j] == 'O' || table[i][j] == 'X')
    return false;

  if (step){
    table[i][j] = 'X';
    step = !step;
  }
  else{
    table[i][j] = 'O';
    step = !step;
  }
  return true;
}

bool checkWin(){
  for (int i = 0; i < 3; ++i){
    if (table[i][0] == table[i][1] and table[i][0] == table[i][2])
      return true;
    else if (table[0][i] == table[1][0] and table[0][i] == table[2][i])
      return true;
    else if ((table[0][0] == table[1][1] and table[0][0] == table[2][2]) or \
             (table[0][2] == table[1][1] and table[0][2] == table[2][0]))
      return true;
  }
  return false;
}