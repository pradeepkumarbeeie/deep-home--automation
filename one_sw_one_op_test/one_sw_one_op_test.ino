int output_responseofsw = 2;
int button = 23;

boolean output_state = false;


long buttonTimer = 1;
long longPressTime = 500;

boolean buttonActive = false;
boolean longPressActive = false;

void setup() {

  pinMode(output_responseofsw, OUTPUT);
  pinMode(button, INPUT);

}

void loop() {

  if (digitalRead(button) == HIGH) {

    if (buttonActive == false) {

      buttonActive = true;
      buttonTimer = millis();

    }

    if ((millis() - buttonTimer > longPressTime) && (longPressActive == false)) {

      longPressActive = true;
      output_state = !output_state;
      digitalWrite(output_responseofsw, output_state);

    }

  } else {

   if (buttonActive == true) {

      if (longPressActive == true) {

        longPressActive = false;

      } 

      buttonActive = false;

    }

  }
}
