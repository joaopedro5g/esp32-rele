#include <WiFi.h>

const char *ssid = "<ssid-wifi>";
const char *password = "<senha-wifi>";

NetworkServer server(80);

void setup() {
  Serial.begin(115200);
  pinMode(5, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  delay(10);



  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
  }

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {
  NetworkClient client = server.accept();

  int t1 = touchRead(27);

  if (t1 <= 20) {
    digitalWrite(5, HIGH);
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(5, LOW);
    digitalWrite(13, LOW);
  }

  if (client) {
    Serial.println("New Client.");
    String currentLine = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        if (c == '\n') {



          if (currentLine.length() == 0) {


            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();


            client.print("Click <a href=\"/H\">here</a> to turn the LED on pin 5 off.<br>");
            client.print("Click <a href=\"/L\">here</a> to turn the LED on pin 5 on.<br>");


            client.println();

            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }


        if (currentLine.endsWith("GET /5/H")) {
          digitalWrite(5, HIGH);
        }
        if (currentLine.endsWith("GET /5/L")) {
          digitalWrite(5, LOW);
        }
        if (currentLine.endsWith("GET /13/H")) {
          digitalWrite(13, HIGH);
        }
        if (currentLine.endsWith("GET /13/L")) {
          digitalWrite(13, LOW);
        }
      }
    }

    client.stop();
  }
}
