#include <AFMotor.h>
int stop_distance = 12;// Khoảng cách phát hiện vật cản
//Kết nối SRF 05 OR 04
const int trigPin = 11; // kết nối chân trig với chân 11 arduino
const int echoPin = 12; // kết nối chân echo với chân 12 arduino

//L293d kết nối arduino
AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);


//kết nối của 3 cảm biến hồng ngoại (dò line )
const int L_S = 9; // cb dò line phải
const int R_S = 10; //cb dò line trái

int left_sensor_state;// biến lưu cảm biến hồng ngoại line trái
int s_sensor_state;   // biến lưu cảm biến hồng ngoại line giữa
int right_sensor_state;// biến lưu cảm biến hồng ngoại line phải

long duration; //
int distance;  // biến khoảng cách


void setup() {
  pinMode(L_S, INPUT); // chân cảm biến khai báo là đầu vào
  pinMode(R_S, INPUT);
 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
  delay(2000);

}

void loop() {
  //khối đo khoảng cách 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);

  // khối cảm biến hồng ngoại 
  left_sensor_state = digitalRead(L_S);
  right_sensor_state = digitalRead(R_S);

  if ((digitalRead(L_S) == 0) && (digitalRead(R_S) == 0)) {
    forword(); // đi tiến
  }

  if ((digitalRead(L_S) == 1) && (digitalRead(R_S) == 0)) {
    turnLeft(); // rẻ trái
  }
  if ((digitalRead(L_S) == 0) && (digitalRead(R_S) == 1)) {
    turnRight(); // rẻ phải
  }

  if ((digitalRead(L_S) == 1) && (digitalRead(R_S) == 1)) {
    Stop(); // stop
  }



  if (distance < stop_distance) // nếu khoảng cách nhỏ hơn giới hạn
  {
      // cho xe chạy lùi 1 đoạn
    motor1.run(BACKWARD);
    motor1.setSpeed(100);
    motor2.run(BACKWARD);
    motor2.setSpeed(100);
    motor3.run(BACKWARD);
    motor3.setSpeed(100);
    motor4.run(BACKWARD);
    motor4.setSpeed(100);
    delay(350);
      // cho xe dừng lại 300 micro giây
    motor1.run(RELEASE);
    motor1.setSpeed(0);
    motor2.run(RELEASE);
    motor2.setSpeed(0);
    motor3.run(RELEASE);
    motor3.setSpeed(0);
    motor4.run(RELEASE);
    motor4.setSpeed(0);
    delay(300);


    //rẽ trái 
    motor1.run(FORWARD);
    motor1.setSpeed(100);
    motor2.run(FORWARD);
    motor2.setSpeed(100);
    motor3.run(BACKWARD);
    motor3.setSpeed(100);
    motor4.run(BACKWARD);
    motor4.setSpeed(100);
    delay(400);
   //dừng lại 
    motor1.run(RELEASE);
    motor1.setSpeed(0);
    motor2.run(RELEASE);
    motor2.setSpeed(0);
    motor3.run(RELEASE);
    motor3.setSpeed(0);
    motor4.run(RELEASE);
    motor4.setSpeed(0);
    delay(200);
    // cho xe đi thẳng 1 đoạn
    motor1.run(FORWARD);
    motor1.setSpeed(100); 
    motor2.run(FORWARD); 
    motor2.setSpeed(100);
    motor3.run(FORWARD);
    motor3.setSpeed(100);
    motor4.run(FORWARD);
    motor4.setSpeed(100);
    delay(600);

   //dừng lại 
    motor1.run(RELEASE);
    motor1.setSpeed(0);
    motor2.run(RELEASE);
    motor2.setSpeed(0);
    motor3.run(RELEASE);
    motor3.setSpeed(0);
    motor4.run(RELEASE);
    motor4.setSpeed(0);
    delay(200);


     //rẽ phải 
    motor1.run(BACKWARD);
    motor1.setSpeed(100);
    motor2.run(BACKWARD);
    motor2.setSpeed(100);
    motor3.run(FORWARD);
    motor3.setSpeed(100);
    motor4.run(FORWARD);
    motor4.setSpeed(100);
    delay(550);

   //dừng lại 
    motor1.run(RELEASE);
    motor1.setSpeed(0);
    motor2.run(RELEASE);
    motor2.setSpeed(0);
    motor3.run(RELEASE);
    motor3.setSpeed(0);
    motor4.run(RELEASE);
    motor4.setSpeed(0);
    delay(200);

    ///////////////////
   // Robot di chuyển tiến 
    motor1.run(FORWARD);
    motor1.setSpeed(100); // tốc độ di chuyển của robot phạm vi từ 0 đến 255
    motor2.run(FORWARD); 
    motor2.setSpeed(100);// tốc độ di chuyển của robot phạm vi từ 0 đến 255
    motor3.run(FORWARD);
    motor3.setSpeed(100);// tốc độ di chuyển của robot phạm vi từ 0 đến 255
    motor4.run(FORWARD);
    motor4.setSpeed(100);
    delay(600); 
   //dừng lại 
    motor1.run(RELEASE);
    motor1.setSpeed(0);
    motor2.run(RELEASE);
    motor2.setSpeed(0);
    motor3.run(RELEASE);
    motor3.setSpeed(0);
    motor4.run(RELEASE);
    motor4.setSpeed(0);
    delay(200);

    ////////////////////////
     motor1.run(BACKWARD);
    motor1.setSpeed(100);
    motor2.run(BACKWARD);
    motor2.setSpeed(100);
    motor3.run(FORWARD);
    motor3.setSpeed(100);
    motor4.run(FORWARD);
    motor4.setSpeed(100);
    delay(500);
   //dừng lại 
    motor1.run(RELEASE);
    motor1.setSpeed(0);
    motor2.run(RELEASE);
    motor2.setSpeed(0);
    motor3.run(RELEASE);
    motor3.setSpeed(0);
    motor4.run(RELEASE);
    motor4.setSpeed(0);
    delay(200);

    motor1.run(FORWARD);
    motor1.setSpeed(100); // tốc độ di chuyển của robot phạm vi từ 0 đến 255
    motor2.run(FORWARD); 
    motor2.setSpeed(100);// tốc độ di chuyển của robot phạm vi từ 0 đến 255
    motor3.run(FORWARD);
    motor3.setSpeed(100);// tốc độ di chuyển của robot phạm vi từ 0 đến 255
    motor4.run(FORWARD);
    motor4.setSpeed(100);

    while (left_sensor_state == LOW) {

      left_sensor_state = digitalRead(L_S);
      right_sensor_state = digitalRead(R_S);
      Serial.println("in the first while");

    }

  }
}

void forword() { // chương trình con xe robot đi tiến

    motor1.run(FORWARD);
    motor1.setSpeed(100); // tốc độ di chuyển của robot phạm vi từ 0 đến 255
    motor2.run(FORWARD); 
    motor2.setSpeed(100);// tốc độ di chuyển của robot phạm vi từ 0 đến 255
    motor3.run(FORWARD);
    motor3.setSpeed(100);// tốc độ di chuyển của robot phạm vi từ 0 đến 255
    motor4.run(FORWARD);
    motor4.setSpeed(100);// tốc độ di chuyển của robot phạm vi từ 0 đến 255
}


void turnRight() {

//rẽ phải 
    motor1.run(BACKWARD);
    motor1.setSpeed(100);
    motor2.run(BACKWARD);
    motor2.setSpeed(100);
    motor3.run(FORWARD);
    motor3.setSpeed(100);
    motor4.run(FORWARD);
    motor4.setSpeed(100);
}

void turnLeft() {
//rẽ trái 
    motor1.run(FORWARD);
    motor1.setSpeed(100);
    motor2.run(FORWARD);
    motor2.setSpeed(100);
    motor3.run(BACKWARD);
    motor3.setSpeed(100);
    motor4.run(BACKWARD);
    motor4.setSpeed(100);
}

void Stop() {

 //dừng lại 
    motor1.run(RELEASE);
    motor1.setSpeed(0);
    motor2.run(RELEASE);
    motor2.setSpeed(0);
    motor3.run(RELEASE);
    motor3.setSpeed(0);
    motor4.run(RELEASE);
    motor4.setSpeed(0);
   
}