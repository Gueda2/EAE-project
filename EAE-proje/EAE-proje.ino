
int buttonPin=7;
int ledPin=13;
int say = 0;
int buttonState = 0;         
int a=0;
int b=0;
bool islem = false;
void setup() {
  pinMode(buttonState, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  kisa();
}
 
void loop() {
  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);
  while (buttonState == 1)
  {
    delay(100);
    say++; 
    buttonState = digitalRead(buttonPin); //butonu tekrar okuyoruz ki while takılı kalmasın. aksi halde 
    islem = true;                        // deger değişkeni hep 1 olduğu için while sonsuz döngüye girer
  }
  Serial.println(say);
  if (islem == true)  // saniyenin uzunluğuna göe seçim belirliyoruz
  {
        if (say >0 && say <= 30) 
        {
          kisa();
        }
       
        if(say>30) 
          {  
            uzun();
          }
           say=0; 
           islem = false;
  }
}

//modlara girebilmesi için butonun bırakılması lazım
void kisa (){
  
  Serial.println("kısa loop");
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
  digitalWrite(ledPin, HIGH);
  delay(2000);
  digitalWrite(ledPin, LOW);
  delay(2000);
  digitalWrite(ledPin, HIGH);
  delay(2000);
  digitalWrite(ledPin, LOW);
  delay(2000);
  buttonState = digitalRead(buttonPin);
  if(buttonState == 0){
     say=0; 
     islem = false;
     loop();}
  if(buttonState == 1){
      kisa();}
  
  }

void uzun (){
  Serial.println("uzun loop");
  say=0;
 for(a=0;a<4;a=a+1){
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);}
    buttonState = digitalRead(buttonPin);  // kısa moda dönmesi gerekirse butonun bırakılması yetecektir. uzun moda devam edilecekse butona basılmaya devam edecektir.
    Serial.println(buttonState);
    if(buttonState == 1){
 for(b=0;b<4;b=b+1){
  digitalWrite(ledPin, HIGH);
  delay(2000);
  digitalWrite(ledPin, LOW);
  delay(2000);
  }
  uzun();}
  if(buttonState == 0){
    loop();}
 }

    
