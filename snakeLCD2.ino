#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // set the LCD address to 0x27 for a 20x4 display


#define TRAI  0
#define PHAI  1
#define TREN  2
#define DUOI  3
#define IDLE - 1

#define ROWS 2
#define COLS 16
byte Field[8*ROWS*COLS] ={0};

unsigned long time, timeNow; 
int gameSpeed;
int dir;

int diem = 0;

struct Snake{
  int x;
  int y;
};
int size = 5;
Snake *snake = new Snake[size]; 
Snake point ;
bool ate = 1;
class Controller{
  public:
    int bientroX ;
    int bientroY ;
    int nutnhan ;

    int giatriX;
    int giatriY;
    int giatrinut;

    Controller(){
      bientroX = A0;
      bientroY = A1;
      nutnhan = 3;
    }

    void input(){
      giatriX = analogRead(bientroX);
      giatriY = analogRead(bientroY);
      giatrinut = digitalRead(nutnhan);
    }

    int output(){
      if(giatriY > 900){
        return TRAI;
      }
      if(giatriY < 300){
        return PHAI;
      }
      if(giatriX < 300){
        return TREN;
      }
      if(giatriX > 900){
        return DUOI;
      }
      return IDLE;
    }

    ~Controller(){};

};
void draw(){
  byte chara[8];
  boolean status ;
  int cc = 0;
  for(int r = 0; r < ROWS;r++){
    for(int c = 0 ; c < COLS; c++){
      status = 0;
      for(int i = 0 ; i < 8; i++){
        byte b=B00000;

        if ((Field[16 * (r*8+i) + (c*5+0)/5] & (1 << ((c*5+0) % 5))) >> ((c*5+0) % 5)) {b+=B10000; status = true;}
        if ((Field[16 * (r*8+i) + (c*5+1)/5] & (1 << ((c*5+1) % 5))) >> ((c*5+1) % 5)) {b+=B01000; status = true;}
        if ((Field[16 * (r*8+i) + (c*5+2)/5] & (1 << ((c*5+2) % 5))) >> ((c*5+2) % 5)) {b+=B00100; status = true;}
        if ((Field[16 * (r*8+i) + (c*5+3)/5] & (1 << ((c*5+3) % 5))) >> ((c*5+3) % 5)) {b+=B00010; status = true;}
        if ((Field[16 * (r*8+i) + (c*5+4)/5] & (1 << ((c*5+4) % 5))) >> ((c*5+4) % 5)) {b+=B00001; status= true;}        
 
         chara[i] = b;
      }
      if(status){
        lcd.createChar(cc, chara);
        lcd.setCursor(c,r);
        lcd.write(byte(cc));
        cc++; 
      }else{
        lcd.setCursor(c,r);
        lcd.write(128);
      }
    } 
  }
}

Controller * controller = new Controller();
void ChangeDot(unsigned int RowVal, unsigned int ColVal, boolean NewVal)
{
  Field[16 * RowVal + ColVal/5] &= ~(1 << (ColVal % 5));
  if (NewVal)
    Field[16 * RowVal + ColVal/5] |= 1 << (ColVal % 5);
}

void (*resetFunc)(void) = 0; 
void moveDir(){
  int dir1 = controller->output();
  if(dir1 == IDLE && dir != IDLE) return;
  if(dir1 ==PHAI && dir == TRAI 
  ||dir1 ==TRAI && dir == PHAI 
  ||dir1 ==TREN && dir == DUOI
  ||dir1 ==DUOI && dir == TREN) return;

  dir= dir1;

}
void moveHead(){
    controller->input();
    if((dir) == PHAI){
      snake[0].x++;
    }else if(dir == TRAI){
      snake[0].x--;
    }else if(dir == TREN){
      snake[0].y--;
    }else if(dir == DUOI){
      snake[0].y++;
    }
     ChangeDot(snake[0].y, snake[0].x, true);
}

void moveAll(){
  if(dir == IDLE) return;
   ChangeDot(snake[size-1].y, snake[size-1].x, false);
    for(int i = size-1 ; i > 0; i--){
      snake[i].x= snake[i -1].x;
      snake[i].y= snake[i -1].y;
      ChangeDot(snake[i].y, snake[i].x, true);
    }
    moveHead();
}

bool checkWall(){
  if(snake[0].x == 80 
  || snake[0].x == -1 
  || snake[0].y == 16
  || snake[0].y == -1){
    return true;
  }
  return false;
  
}
Snake* incrSize(){
  size;
  Snake* newSnake = new Snake[size + 1];
  for (int i = 0; i < size; i++) {
        newSnake[i] = snake[i];
    }
    size++;
    delete []snake;
    return newSnake;
}
void eaten (){
  if(snake[0].x == point.x && snake[0].y == point.y){
    ate = true;
    snake =incrSize();
    snake =incrSize();
    diem++;
    gameSpeed +=diem *3;
  }
}
bool trung(int x, int y){
  for(int i = 0; i < size; i++){
    if(x == snake[i].x && y== snake[i].y)
    {
      return true;
    }
  }
  return false;
}
void newPoint(){
  eaten();
  if(!ate) return;
  int x = random(79);
  int y = random(16);

  while(trung(x,y)){
     x = random(79);
     y = random(16);
  }
   
  point.x = x;
  point.y = y;
  ChangeDot(y,x,true);
  ate = 0;
}
bool isGameOver(){
  if(checkWall()) return true;
  for(int i = 2 ; i < size; i++){
    if(snake[i].x == snake[0].x &&snake[i].y == snake[0].y){
      return true;
    }
  }
  return false;
}
void gameOver(){
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Point: ");
  lcd.print(diem);
  int s = 5;
  while(s > -1){
    lcd.setCursor(0, 1);
    lcd.print("Starts later :");
    lcd.print(s);
    s--;
    delay(1000);
  }
  

  delete[] snake;
  snake = NULL;

  diem = 0;
  size = 5;
  ate = true;
  gameSpeed = 50;
  dir = PHAI;
  
  snake = new Snake[size];
  for (int i = 0; i < size; i++) {
    snake[i].x = size - 1 - i;
    snake[i].y = 0;
  }
  
  for (int i = 0; i < 8 * ROWS * COLS; i++) {
    Field[i] = 0;
  }
  
 
  draw();
  
}

void start(){
  lcd.setCursor(3,0);
  lcd.print("SNAKE GAME");
  lcd.setCursor(4,1);
  lcd.print("KINH LUP");
  delay(5000);
  lcd.clear();
}
void setup(){ 
  lcd.init();         
  lcd.backlight();   
  Serial.begin(9600); 
  pinMode(controller->bientroX, INPUT);
  pinMode(controller->bientroY, INPUT);
  pinMode(controller->nutnhan, INPUT_PULLUP);
  start();
  Field[0]=  B11111;
  gameSpeed = 50;
  dir= PHAI;
    for (int i = 0; i < size; i++) {
      snake[i].x = size - 1 - i; // Giảm dần theo trục x
      snake[i].y = 0;
    }
    draw();
}

int f = 0;
void loop() {
 
 
  timeNow = millis();
     if (timeNow - time > 1000 / gameSpeed)
     {  
        moveDir();
        moveAll();
        newPoint();
        if(isGameOver()){
          //hien thi diem
          
          gameOver();
          
          //cho 5s 
          // khoi tao ra ran// bat dau game moi
        }
        draw();
        time = millis();
     }
  
}


