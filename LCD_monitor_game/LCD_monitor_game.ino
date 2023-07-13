#include <LiquidCrystal.h>
#define SCREEN_WIDTH 16
#define SCREEN_HEIGHT 2

const int maze[][2] = {{4,0},{8, 1},{11, 0},{2, 1}};
const int objective[2] = {SCREEN_WIDTH - 1, 0};

const int rs = 2, en = 4, d4 = 5, d5 = 6, d6 = 7, d7 = 8;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int cursorPos[2] = {0,0};
bool gameOn = true;

void setup() {
  lcd.begin(SCREEN_WIDTH, SCREEN_HEIGHT);
  Serial.begin(9600);
  lcd.print("P");
}

void drawMaze(){
  for(int i = 0; i<sizeof(maze)/sizeof(maze[0]); i++){
      lcd.setCursor(maze[i][0], maze[i][1]);
      lcd.print("X");
      lcd.setCursor(objective[0], objective[1]);
      lcd.print("O");
  }
}

void movement(char charInput){
  if(charInput == 'w' && cursorPos[1]>0){
      lcd.clear();
      cursorPos[1]-=1;
    }

  if(charInput == 'a' && cursorPos[0]>0){
    lcd.clear();
    cursorPos[0]-=1;
  }

  if(charInput == 'd' && cursorPos[0] < SCREEN_WIDTH - 1){
    lcd.clear();
    cursorPos[0]+=1;
  }

  if(charInput == 's' && cursorPos[1] < SCREEN_HEIGHT - 1){
    lcd.clear();
    cursorPos[1]+=1;
  }
}

void checkLoss(){
  for(int i = 0; i < sizeof(maze)/sizeof(maze[0]); i++){
    if(cursorPos[0] == maze[i][0] & cursorPos[1] == maze[i][1]){
      gameOn = false;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("You've Lost!");
      delay(2000);
      return;
    }
  }
}

void checkWin(){
  if(cursorPos[0] == objective[0] & cursorPos[1] == objective[1]){
    gameOn = false;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("You've Won!");
    delay(2000);
  }
}

void tryAgainScreen(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Try again?");
  lcd.setCursor(0, SCREEN_HEIGHT - 1);
  lcd.print("Y-yes");
  lcd.setCursor((int)(SCREEN_WIDTH/2), SCREEN_HEIGHT - 1);
  lcd.print("N-no");
  tryAgainPrompt();
  delay(500);
}

void tryAgainPrompt(){
  if(Serial.available()){
    char charInput = Serial.read();
    
    if(charInput == 'Y'){
      lcd.clear();
      gameOn = true;
      cursorPos[0] = 0;
      cursorPos[1] = 0;
      return;
    }

    if(charInput == 'N'){
      lcd.clear();
      lcd.setCursor((int)SCREEN_WIDTH/2 - 2, 0);
      lcd.print("Good");
      lcd.setCursor((int)SCREEN_WIDTH/2 - 2, 1);
      lcd.print("Bye!");
      exit(0);
    }
  }
}

void loop() {
  while(gameOn){
    drawMaze();
    if(Serial.available()){
      char charInput = Serial.read();

      movement(charInput);

      lcd.setCursor(cursorPos[0], cursorPos[1]);
      lcd.print("P");

      checkLoss();
      checkWin();
    }
  }

  tryAgainScreen();
}