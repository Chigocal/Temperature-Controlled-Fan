#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// --- SETTINGS ---
#define I2C_ADDRESS 0x27  
#define DHTPIN 7          
#define DHTTYPE DHT11     
#define MOTOR_PIN_ENA 9   
#define MOTOR_PIN_IN1 10  
#define MOTOR_PIN_IN2 11  

// Updated Thresholds
#define TEMP_OFF 28
#define TEMP_LOW 35
#define TEMP_HIGH 40 

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(I2C_ADDRESS, 16, 2); 

void setup() {
  // Give the LCD time to stabilize after power-on
  delay(2000); 

  Serial.begin(9600);
  dht.begin();
  
  // Initialize LCD
  lcd.init();
  lcd.backlight();
  
  // Boot Screen
  lcd.setCursor(0, 0);
  lcd.print("  SMART FAN    ");
  lcd.setCursor(0, 1);
  lcd.print("  INITIALIZING  ");
  
  pinMode(MOTOR_PIN_ENA, OUTPUT);
  pinMode(MOTOR_PIN_IN1, OUTPUT);
  pinMode(MOTOR_PIN_IN2, OUTPUT);

  // Set motor direction (L298N)
  digitalWrite(MOTOR_PIN_IN1, LOW); 
  digitalWrite(MOTOR_PIN_IN2, HIGH); 
  
  delay(2000);
  lcd.clear();
}

void loop() {
  float temp = dht.readTemperature(); 

  if (isnan(temp)) {
    // Error handling for sensor disconnection
    lcd.setCursor(0, 0);
    lcd.print("SENSOR ERROR    ");
    lcd.setCursor(0, 1);
    lcd.print("CHECK WIRING    ");
    Serial.println("[ERROR] DHT11 Sensor Glitch");
  } 
  else {
    int speed = 0;
    String label = "";

    // --- REVISED CONTROL LOGIC ---
    if (temp >= TEMP_HIGH) {
      speed = 255;       // 100% PWM
      label = "MAXIMUM";
    }
    else if (temp >= TEMP_LOW) {
      speed = 185;       // ~72% PWM
      label = "MEDIUM "; 
    }
    else if (temp >= TEMP_OFF) {
      speed = 140;       // ~55% PWM (enough torque to start)
      label = "LOW    "; 
    }
    else {
      speed = 0;         // Fan OFF
      label = "OFF    "; 
    }

    analogWrite(MOTOR_PIN_ENA, speed);

    // --- LCD DISPLAY UPDATES ---
    lcd.setCursor(0, 0);
    lcd.print("Temp:"); 
    lcd.print(temp, 1); 
    lcd.print((char)223); // Degree symbol
    lcd.print("C  "); 
    
    lcd.setCursor(0, 1);
    lcd.print("Fan: "); 
    lcd.print(label);

    // Serial Monitor backup for debugging
    Serial.print("Temp: "); Serial.print(temp); Serial.print("C | ");
    Serial.print("Fan: "); Serial.println(label);
  }

  // Refresh rate: 2 seconds is optimal for DHT11
  delay(2000); 
}