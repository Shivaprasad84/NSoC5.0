#include <SD.h>

static bool hasSD = false;
File uploadFile;

void readFile(String filename) {
  Serial.println();
  Serial.println("Content in " + filename);
  File html = SD.open("/" + filename);
  String htmlPage = "";
  while(html.available()) {
    int x = html.read();
    htmlPage += char(x);
    Serial.print(char(x));
  }
  html.close();
  html.rewindDirectory();
}

void listDir() {
  Serial.println();
  Serial.println("Current Directory");
  File root = SD.open("/");
  while(1) {
    File nxt = root.openNextFile();
    if(!nxt) {
      break;
    }
    Serial.println(nxt.name());
    nxt.close();
  }
  root.close();
}

void removeFile(String filename) {
  SD.remove("/" + filename);                                      
}

void writeFile(String filename, String msg) {
  File myFile = SD.open("/" + filename, FILE_WRITE);
  myFile.println(msg);
  myFile.close();
}


void setup() {
  Serial.begin(115200);
  if (SD.begin(5)) {
    Serial.println("SD Card Connected");
  } else {
    Serial.println("SD Card NOT Connected");
  }
  listDir();
  writeFile("hello.txt","hello");
  readFile("hello.txt");
  removeFile("hello.txt");
  
}

void loop() {
  
}
