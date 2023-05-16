/*#include "U8glib.h"

U8GLIB_SSD1306_128X64 oled(U8G_I2C_OPT_NONE);

void setup() {
  oled.begin();
  Serial.begin(9600);
  pinMode(A3, INPUT);
  pinMode(7, INPUT_PULLUP); // add button input pin
}

void loop(void) {
  int potValue = analogRead(A3);
  Serial.println(potValue);
  int page;
  if (potValue >= 800) {
    page = 3;
  } else if (potValue >= 600) {
    page = 2;
  } else if (potValue >= 400) {
    page = 1;
  } else {
    page = 0;
  }

  Serial.println(digitalRead(7));
  
  // check if button is pressed
  if (digitalRead(7) == LOW) {
    page = 4; // switch to Page 5
  }

  oled.firstPage();
  do {
    draw(page);
  } while (oled.nextPage());
  delay(10);
}

void draw(int page) {
  oled.setFont(u8g_font_helvB10);
  switch(page) {
    case 0:
      oled.drawStr(40, 40, "Page 1");
      break;
    case 1:
      oled.drawStr(40, 40, "Page 2");
      break;
    case 2:
      oled.drawStr(40, 40, "Page 3");
      break;
    case 3:
      oled.drawStr(40, 40, "Page 4");
      break;
    case 4:
      oled.drawStr(40, 40, "Page 5"); // add case for Page 5
      break;
  }
}
*/

#include "U8glib.h"

U8GLIB_SSD1306_128X64 oled(U8G_I2C_OPT_NONE);

int selectedPage;

void setup() {
  oled.begin();
  Serial.begin(9600);
  pinMode(A3, INPUT);
  pinMode(7, INPUT_PULLUP); // add button input pin
}

void loop(void) {
  int potValue = analogRead(A3);
  Serial.println(potValue);
  int page;
  if (potValue >= 800) {
    page = 3;
  } else if (potValue >= 600) {
    page = 2;
  } else if (potValue >= 400) {
    page = 1;
  } else {
    page = 0;
  }

  Serial.println(digitalRead(7));
  
  // check if button is pressed
  if (digitalRead(7) == LOW) {
    selectedPage = page; // store the selected page number
    page = 4; // switch to Page 5
  }

  oled.firstPage();
  do {
    draw(page, selectedPage);
  } while (oled.nextPage());
  delay(10);
}

void draw(int page, int selectedPage) {
  oled.setFont(u8g_font_helvB10);
  switch(page) {
    case 0:
      oled.drawStr(40, 40, "Page 1");
      break;
    case 1:
      oled.drawStr(40, 40, "Page 2");
      break;
    case 2:
      oled.drawStr(40, 40, "Page 3");
      break;
    case 3:
      oled.drawStr(40, 40, "Page 4");
      break;
    case 4:
      oled.drawStr(0, 40, "You chose Page ");
      oled.drawStr(120, 40, String(selectedPage + 1).c_str());
      break;
  }
}


/* #include "U8glib.h"

U8GLIB_SSD1306_128X64 oled(U8G_I2C_OPT_NONE);

void setup() {
  oled.begin();
  Serial.begin(9600);
  pinMode(A3, INPUT);
}

void loop(void) {
  int potValue = analogRead(A3);
  Serial.println(potValue);
  int page;
  if (potValue >= 800) {
    page = 3;
  } else if (potValue >= 600) {
    page = 2;
  } else if (potValue >= 400) {
    page = 1;
  } else {
    page = 0;
  }

  oled.firstPage();
  do {
    draw(page);
  } while (oled.nextPage());
  delay(10);
}

void draw(int page) {
  oled.setFont(u8g_font_helvB10);
  switch(page) {
    case 0:
      oled.drawStr(40, 40, "Page 1");
      break;
    case 1:
      oled.drawStr(40, 40, "Page 2");
      break;
    case 2:
      oled.drawStr(40, 40, "Page 3");
      break;
    case 3:
      oled.drawStr(40, 40, "Page 4");
      break;
  }
}
*/
