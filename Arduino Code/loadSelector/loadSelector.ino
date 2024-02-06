/*
This program is made for switching Capacitor Bank, Resistance Bank or other load Banks
The arduino pins 10,11,12 are connected to two cascaded SIPO Shift Register as follows:
    +------------------------+
    | 12 -> Serial Data Pin  |
    | 11 -> Serial clock pin |
    | 10 -> Latch Pin        |
    +------------------------+
*/

#define sdk 12
#define clk 11
#define slk 10
#define Open true
#define Close false
unsigned int val;
boolean gate = Open;
boolean Available = false;
boolean ctrl[16]={false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false};


void launchLoad(){
  digitalWrite(slk,LOW);// Latch LOW
  
  digitalWrite(sdk,LOW);
  for(int i=0; i<16; i++){
    digitalWrite(clk,LOW);
    delay(1);
    digitalWrite(sdk,ctrl[i]);
    delay(1);
    digitalWrite(clk,HIGH);
    delay(1);
  }
  
  digitalWrite(slk,HIGH);// Latch HIGH
}

int POW(int x,int EXP){
    int y = 1;
    for(int i=1;i<=EXP;i++){
        y *= x;
    }
    return y;
}

void prepareLoad(unsigned int n){
  int i = 1;
  for (int j=4; j >= 0; j--)
  {
    if(j>0){
      // for 5th place value -----------------------
      int a = POW(10,j)/2;
      if(n/a == 1){
        ctrl[i-1] = true;
        n = n%a;
      }
      else{
        ctrl[i-1] = false;
      }
      i++;

      // for 2nd places value -----------------------
      a = POW(10,j)/5;
      if(n/a == 2){
        ctrl[i-1] = true;
        ctrl[i] = true;
        n = n%a;
      }
      else if(n/a == 1){
        ctrl[i-1] = false;
        ctrl[i] = true;
        n = n%a;
      }
      else{
        ctrl[i-1] = false;
        ctrl[i] = false;
        n = n%a;
      }
      i += 2;

      // for 1st place value -----------------------
      a = POW(10,j-1);
      if(n/a == 1){
        ctrl[i-1] = true;
        n = n%a;
      }
      else{
        ctrl[i-1] = false;
      }
      i++;
    }
    else{
      // for place value of 1 -----------------------
      if(n == 1){
        ctrl[i-1] = true;
      }
    }
  }
}

void setup() {
  pinMode(sdk,OUTPUT);
  pinMode(clk,OUTPUT);
  pinMode(slk,OUTPUT);
  
  digitalWrite(sdk,LOW);
  for(int i=0; i<16; i++){
    digitalWrite(clk,LOW);
    delay(1);
    digitalWrite(clk,HIGH);
    delay(1);
  }
  digitalWrite(sdk,HIGH);
  Serial.begin(9600);
  Serial.println("Machine is ON !");
}

void loop() {
  // read the incoming user given value
  if(Serial.available()){
    int i = Serial.parseInt();
    if (gate == Open){
      val = i;
      Available = true;
    }
    gate = !gate;
  }
  // end [reading the incoming user given value]

  if(Available){
    prepareLoad(val);
    launchLoad();
  }
}
