#include <SD.h>

static bool hasSD = false;
File uploadFile;

void readFile(String filename) {
  File html = SD.open("/" + filename);
  String htmlPage = "";
  while(html.available()) {
    int x = html.read();
    htmlPage += x;
    Serial.write(x);
  }
  html.close();
  html.rewindDirectory();
}

void listDir() {
  File root = SD.open("/");
  while(1) {
    File nxt = root.openNextFile();
    if(!nxt) {
      break;
    }
    Serial.print(nxt.name());
    Serial.println(" - ");
    Serial.println(nxt.size());
    nxt.close();
  }
  root.close();
}

void removeFile(String filename) {
  SD.remove(filename);
}

void writeFile(String filename, String msg) {
  File myFile = SD.open(filename);
  myFile.println(msg);
}


void setup() {
  Serial.begin(115200);
  if (SD.begin(5)) {
    Serial.println("SD Card Connected");
  } else {
    Serial.println("SD Card NOT Connected");
  }
}

void loop() {
  
}
