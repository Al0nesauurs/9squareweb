#include <Arduino.h>
#include <driver/adc.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <Thread.h>
#include <ThreadController.h>
#include <pthread.h>
#include <CircularBuffer.h>

// Update these with values suitable for your network.
// const char* ssid = "GrowthChamberAIS";
// const char* password = "0123456789012";
const char* ssid = "MTN-MobileWiFi-E5573";
const char* password = "ET4F92MN";

CircularBuffer<int> myBuffer(64);


ThreadController controll = ThreadController();

//My Thread
Thread Thread1 = Thread();
//His Thread
Thread Thread2 = Thread();

ThreadController groupOfThreads = ThreadController();


int LastState1L = 0;
int LastState1R = 0;
int LastState2L = 0;
int LastState2R = 0;
int LastState3L = 0;
int LastState3R = 0;
int LastState4L = 0;
int LastState4R = 0;
int LastState5L = 0;
int LastState5R = 0;
int LastState6L = 0;
int LastState6R = 0;
int LastState7L = 0;
int LastState7R = 0;
int LastState8L = 0;
int LastState8R = 0;
int LastState9L = 0;
int LastState9R = 0;
int count = 0;

int buttonState1L = 0;
int buttonState1R = 0;
int buttonState2L = 0;
int buttonState2R = 0;
int buttonState3L = 0;
int buttonState3R = 0;
    
int buttonState4L = 0;
int buttonState4R = 0;
int buttonState5L = 0;
int buttonState5R = 0;
int buttonState6L = 0;
int buttonState6R = 0;
    
int buttonState7L = 0;
int buttonState7R = 0;
int buttonState8L = 0;
int buttonState8R = 0;
int buttonState9L = 0;
int buttonState9R = 0;
// Config MQTT Server
#define mqtt_server "192.168.8.102"
#define mqtt_port 1883
#define mqtt_user "admin"
#define mqtt_password "password"
#define TOPIC1 "/dev/1"
#define LED_PIN 2

WiFiClient espClient;
PubSubClient client(espClient);
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  String msg = "";
  int i=0;
  while (i<length) msg += (char)payload[i++];
  if (msg == "GET") {
    client.publish("/ESP/LED", (digitalRead(LED_PIN) ? "LEDON" : "LEDOFF"));
    Serial.println("Send !");
    return;
  }
  Serial.println(msg);
}

  void sendPress(){

    if (buttonState1L != LastState1L || buttonState1R != LastState1R) {
      if (buttonState1L == HIGH && buttonState1R == HIGH) {
        // turn LED on:
        Serial.println("1HIGH");
      } else if ((buttonState1L == LOW || buttonState1R == LOW)){
        // turn LED off:
        client.publish(TOPIC1, "1");
        Serial.println("1LOW");
        count += 1;
        Serial.println(count);
      }
      LastState1L = buttonState1L;
      LastState1R = buttonState1R;
    }
    if (buttonState2L != LastState2L || buttonState2R != LastState2R) {
      if (buttonState2L == HIGH && buttonState2R == HIGH) {
        // turn LED on:
        Serial.println("2HIGH");
      } else if ((buttonState2L == LOW || buttonState2R == LOW)){
        // turn LED off:
        client.publish(TOPIC1, "2");
        Serial.println("2LOW");
        count += 1;
        Serial.println(count);
      }
      LastState2L = buttonState2L;
      LastState2R = buttonState2R;
    }
    if (buttonState3L != LastState3L || buttonState3R != LastState3R) {
      if (buttonState3L == HIGH && buttonState3R == HIGH) {
        // turn LED on:
        Serial.println("3HIGH");
      } else if ((buttonState3L == LOW || buttonState3R == LOW)){
        // turn LED off:
        client.publish(TOPIC1, "3");
        Serial.println("3LOW");
        count += 1;
        Serial.println(count);
      }
      LastState3L = buttonState3L;
      LastState3R = buttonState3R;
    }
    if (buttonState4L != LastState4L || buttonState4R != LastState4R) {
      if (buttonState4L == HIGH && buttonState4R == HIGH) {
        // turn LED on:
        Serial.println("4HIGH");
      } else if ((buttonState4L == LOW || buttonState4R == LOW)){
        // turn LED off:
        client.publish(TOPIC1, "4");
        Serial.println("4LOW");
        count += 1;
        Serial.println(count);
      }
      LastState4L = buttonState4L;
      LastState4R = buttonState4R;
    }
    if (buttonState5L != LastState5L || buttonState5R != LastState5R) {
      if (buttonState5L == HIGH && buttonState5R == HIGH) {
        // turn LED on:
        Serial.println("5HIGH");
      } else if ((buttonState5L == LOW || buttonState5R == LOW)){
        // turn LED off:
        client.publish(TOPIC1, "5");
        Serial.println("5LOW");
        count += 1;
        Serial.println(count);
      }
      LastState5L = buttonState5L;
      LastState5R = buttonState5R;
    }
    if (buttonState6L != LastState6L || buttonState6R != LastState6R) {
      if (buttonState6L == HIGH && buttonState6R == HIGH) {
        // turn LED on:
        Serial.println("6HIGH");
      } else if ((buttonState6L == LOW || buttonState6R == LOW)){
        // turn LED off:
        client.publish(TOPIC1, "6");
        Serial.println("6LOW");
        count += 1;
        Serial.println(count);
      }
      LastState6L = buttonState6L;
      LastState6R = buttonState6R;
    }
    if (buttonState7L != LastState7L || buttonState7R != LastState7R) {
      if (buttonState7L == HIGH && buttonState7R == HIGH) {
        // turn LED on:
        Serial.println("7HIGH");
      } else if ((buttonState7L == LOW || buttonState7R == LOW)){
        // turn LED off:
        client.publish(TOPIC1, "7"); 
        Serial.println("7LOW");
        count += 1;
        Serial.println(count);
      }
      LastState7L = buttonState7L;
      LastState7R = buttonState7R;
    }
    if (buttonState8L != LastState8L || buttonState8R != LastState8R) {
      if (buttonState8L == HIGH && buttonState8R == HIGH) {
        // turn LED on:
        Serial.println("8HIGH");
      } else if ((buttonState8L == LOW || buttonState8R == LOW)){
        // turn LED off:
        client.publish(TOPIC1, "8");
        Serial.println("8LOW");
        count += 1;
        Serial.println(count);
      }
      LastState8L = buttonState8L;
      LastState8R = buttonState8R;
    }
    if (buttonState9L != LastState9L || buttonState9R != LastState9R) {
      if (buttonState9L == HIGH && buttonState9R == HIGH) {
        // turn LED on:
        Serial.println("9HIGH");
        count += 1;
        Serial.println(count);
      } else if ((buttonState9L == LOW || buttonState9R == LOW)){
        // turn LED off:
        client.publish(TOPIC1, "9");
        Serial.println("9LOW");
      }
      LastState9L = buttonState9L;
      LastState9R = buttonState9R;
    }
}
void subPress1() {
      client.publish(TOPIC1, 1 + "");
    }
void subPress2() {
      client.publish(TOPIC1, 2 + "");
    }
void subPress3() {
      client.publish(TOPIC1, 3 + "");
    }
void pushPressAll() {
  int readPin  = myBuffer.read();
  client.publish(TOPIC1, readPin + "");
}
void getPress1() {
  myBuffer.write(1); // 1 = all
  pushPressAll();
}
void getPress2() {
  myBuffer.write(2); // 1 = all
  pushPressAll();
}
void getPress3() {
  myBuffer.write(3); // 1 = all
  pushPressAll();
}
void getPressAll() {
  myBuffer.write(1); // 1 = all
  pushPressAll();
}


void setup() {
  attachInterrupt(digitalPinToInterrupt(0), 	getPressAll, FALLING);

  attachInterrupt(digitalPinToInterrupt(36), 	getPress1, FALLING);
  attachInterrupt(digitalPinToInterrupt(39), 	getPress1, FALLING);
  attachInterrupt(digitalPinToInterrupt(34), 	getPress2, FALLING);
  attachInterrupt(digitalPinToInterrupt(35), 	getPress2, FALLING);
  attachInterrupt(digitalPinToInterrupt(32), 	getPress3, FALLING);
  attachInterrupt(digitalPinToInterrupt(33), 	getPress3, FALLING);
  // attachInterrupt(0, 	checkPress(), FALLING);
  // attachInterrupt(0, 	checkPress(), FALLING);
  // attachInterrupt(0, 	checkPress(), FALLING);
  // attachInterrupt(0, 	checkPress(), FALLING);
  // attachInterrupt(0, 	checkPress(), FALLING);
  // attachInterrupt(0, 	checkPress(), FALLING);
  // attachInterrupt(0, 	checkPress(), FALLING);
  // attachInterrupt(0, 	checkPress(), FALLING);
  // attachInterrupt(0, 	checkPress(), FALLING);
  // attachInterrupt(0, 	checkPress(), FALLING);
  // attachInterrupt(0, 	checkPress(), FALLING);
  // attachInterrupt(0, 	checkPress(), FALLING);
  


    // buttonState1L = digitalRead(36);
    // buttonState1R = digitalRead(39);
    // buttonState2L = digitalRead(34);
    // buttonState2R = digitalRead(35);
    // buttonState3L = digitalRead(32);
    // buttonState3R = digitalRead(33);
    
    // buttonState4L = digitalRead(25);
    // buttonState4R = digitalRead(26);
    // buttonState5L = digitalRead(27);
    // buttonState5R = digitalRead(14);
    // buttonState6L = digitalRead(12);
    // buttonState6R = digitalRead(19);
    
    // buttonState7L = digitalRead(18);
    // buttonState7R = digitalRead(5);
    // buttonState8L = digitalRead(17);
    // buttonState8R = digitalRead(16);
    // buttonState9L = digitalRead(4);
    // buttonState9R = digitalRead(2);
	// Configure Thread1
	// Thread1.onRun(checkPress);

	// Configure Thread2
	Thread2.onRun(sendPress);

	// Adds Thread1 to the controll
	// Adds Thread1 to the controll

	// Adds Thread2 and blinkLedThread to groupOfThreads

	// Add groupOfThreads to controll
	controll.add(&Thread1);
  controll.add(&Thread2);
  
  pinMode(LED_PIN, OUTPUT);
  pinMode(36, INPUT);
  pinMode(39, INPUT);  
  pinMode(34, INPUT);
  pinMode(35, INPUT);  
  pinMode(32, INPUT);
  pinMode(33, INPUT); 

  pinMode(25, INPUT);
  pinMode(26, INPUT);
  pinMode(27, INPUT);
  pinMode(14, INPUT);
  pinMode(12, INPUT);
  pinMode(19, INPUT);

  pinMode(18, INPUT);
  pinMode(5, INPUT);
  pinMode(17, INPUT);
  pinMode(16, INPUT);
  pinMode(4, INPUT);
  pinMode(2, INPUT);
                                                                                                                                 
  Serial.begin(9600);
  delay(10);

  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("ESP8346Client")) {
      Serial.println("connected");
      client.subscribe("/ESP/LED");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
      return;
    }
  }
	controll.run();

    delay(200);
  client.loop();
}
