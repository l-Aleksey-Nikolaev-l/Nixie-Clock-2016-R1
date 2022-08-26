int a,b,c,d,e,f,g = 0;
int regym = 0;
void setup() 
{
DDRB = DDRB | 0B00111100; // Katod
DDRC = DDRC | 0B00111111; // Anod
}

char katod[10][1] = {{0B00000000},  // 0
                     {0B00100000},  // 1
                     {0B00010000},  // 2
                     {0B00110000},  // 3
                     {0B00001000},  // 4
                     {0B00101000},  // 5
                     {0B00011000},  // 6
                     {0B00111000},  // 7
                     {0B00000100},  // 8
                     {0B00100100}}; // 9
                     
  char anod[6][1] = {{0B00000001},  // 1 единицы секунд
                     {0B00000010},  // 2 десятки секунд
                     {0B00000100},  // 3 единицы минут
                     {0B00001000},  // 4 десятки минут
                     {0B00010000},  // 5 единицы часов
                     {0B00100000}}; // 6 десятки часов
//=========================================================
void loop() 
{
      
while (g != 125)
{

  PORTC = anod[0][0];
  PORTB = katod[a][0];
  delay(1);
  
  PORTC = anod[1][0];
  PORTB = katod[b][0];
  delay(1);
  
  PORTC = anod[2][0];
  PORTB = katod[c][0];
  delay(1);
  
  PORTC = anod[3][0];
  PORTB = katod[d][0];
  delay(1);
  
  PORTC = anod[4][0];
  PORTB = katod[e][0];
  delay(1);
  
  PORTC = anod[5][0];
  PORTB = katod[f][0];
  delay(1);
  
  PORTC = 0B00000000;
  PORTB = 0B00000000;
  delay(1);
  
  PORTC = 0B00000000;
  PORTB = 0B00000000;
  delay(1);
  
  g += 1;
  
  
  
  
 
 
  while (digitalRead(0) == HIGH)  { // выбор режима
  if(digitalRead(0) == HIGH)//если кнопка нажата ... 
      { 
        regym++; 
        PORTC = 0B00000011;
        perebeg();
        if (regym > 4)
        {regym = 0;}      
      }
  }
 //=================================================== 
 
  if (regym == 1)  { // режим 1
    g = 0;
	
  while (g == 0){
     PORTC = anod[0][0];
     PORTB = katod[a][0];
     delay(5);
  
     PORTC = anod[1][0];
     PORTB = katod[b][0];
     delay(5);
     
  if (digitalRead(2) == HIGH)  {
  a--;
    if (a < 0) {
        a = 9;
        b -= 1;
      }
    if (b < 0) {
        b = 5;
      }
    delay(200);
   }
  
  if (digitalRead(1) == HIGH)  {
  a++;
    if (a > 9) {
        a = 0;
        b += 1;
      }
    if (b > 5) {
        b = 0;
      }
    delay(200);
   }
   
   
   if (digitalRead(0) == HIGH)  {
        g = 1;
	regym = 2;
        PORTC = 0B00001100;
        perebeg();
   }
 }
}

  if (regym == 2)  { // режим 2
    g = 0;
	
  while (g == 0){
     PORTC = anod[2][0];
     PORTB = katod[c][0];
     delay(5);
  
     PORTC = anod[3][0];
     PORTB = katod[d][0];
     delay(5);
     
  if (digitalRead(2) == HIGH)  {
  c--;
    if (c < 0) {
        c = 9;
        d -= 1;
      }
    if (d < 0) {
        d = 5;
      }
    delay(200);
   }
  
  if (digitalRead(1) == HIGH)  {
  c++;
    if (c > 9) {
        c = 0;
        d += 1;
      }
    if (d > 5) {
        d = 0;
      }
    delay(200);
   }
   
   if (digitalRead(0) == HIGH)  {
        g = 1;
	regym = 3;
        PORTC = 0B00110000;
        perebeg();
        
   }
 }
}

  if (regym == 3)  { // режим 3
    g = 0;
	
  while (g == 0){
     PORTC = anod[4][0];
     PORTB = katod[e][0];
     delay(5);
  
     PORTC = anod[5][0];
     PORTB = katod[f][0];
     delay(5);
     
  if (digitalRead(2) == HIGH)  {
  e--;
    if (e < 0) {
        e = 9;
        f -= 1;
      }
    if (f < 0) {
        f = 2;
        e = 3;
      }

    delay(200);
   }
  
  if (digitalRead(1) == HIGH)  {
  e++;
    if (e > 9) {
        e = 0;
        f += 1;
      }
    if (f > 2) {
        f = 0;
      }
    if (e == 4 && f == 2)
    {
      e = 0;
      f = 0;
    }
    delay(200);
   }
   
   
   if (digitalRead(0) == HIGH)  {
        g = 1;
	regym = 0;
        PORTC = 0B00111111;
        perebeg();
   }
 }
}


 //=================================================== 
}
g = 0;
a += 1;
if (a > 9)
{
  a = 0;
  b += 1;
}
if (b > 5)
{
  b = 0;
  c += 1;
}
if (c > 9)
{
  c = 0;
  d += 1;
}
if (d > 5)
{
  d = 0;
  e += 1;
}
if (e > 9)
{
  e = 0;
  f += 1;
}
if (e == 4 && f == 2)
{
  e = 0;
  f = 0;
}
}

void perebeg()
{
  for (int perebeg = 0; perebeg <= 9; perebeg++)
  {
   PORTB = katod[perebeg][0];
   delay(50);
  }
}
