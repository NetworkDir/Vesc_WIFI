#include "Arduino.h"
#include <WiFi.h>
#include <WiFiAP.h>
#include <CircularBuffer.h>

// Vesc serial connection
#define VESC_RX 15 // RX PIN OUT = D15
#define VESC_TX 13  // TX PIN OUT = D13

//SSID name and password and vesc port
const char *ssid = "INSERT SSID NAME HERE";
const char *password = "INSERT PASSWORD HERE";
const int vescDefaultPort = 65102; // IF YOU WANT CUSTOM PORT PUT HERE

static WiFiServer server(vescDefaultPort);
static WiFiClient client;

static CircularBuffer<uint8_t, 2048> elshanToSend;
const size_t max_buf = 2048;
uint8_t buf[max_buf];


void setup(){
  // Vesc serial
  Serial1.begin(115200, SERIAL_8N1, VESC_TX, VESC_RX); // Start Vesc serial
  // WiFi Access Point
  WiFi.softAP(ssid, password, 2, 0, 4);
  IPAddress myIP = WiFi.softAPIP();
  server.begin();
} 

// This is the Arduino main loop function.
void appendToElshan(uint8_t *buf, size_t len){
  if (elshanToSend.available() >= len){
    for (int i = 0; i < len; i++)
      elshanToSend.push(buf[i]);
  }
}

static int loopStep = 0;

void loop(){
  if (!(loopStep % 200000))
  loopStep++;

  if (!client){
    client = server.available();

    if (client){
      client.setNoDelay(true);
    }
  }
  size_t len, avail;
  // Wifi client data available?
  avail = client.available();
  if (avail){
    len = client.readBytes(buf, avail < max_buf ? avail : max_buf);
    size_t written = Serial1.write(buf, len); // Send to Vesc
  }
  // Vesc data available?
  avail = Serial1.available();
  if (avail){
    len = Serial1.readBytes(buf, avail < max_buf ? avail : max_buf);
    if (client){
      size_t written = client.write(buf, len);
      if (written != len){
        client.stop();
        appendToElshan(buf, len);
      }
    }
    else
      appendToElshan(buf, len);
  }
}
