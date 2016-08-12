/*
Program for driving a servo motor with an Arduino.
For testing (the minimal) period with which the servo can be controlled.
It continuously moves the servo between two positions.
 */

int REFRESH_INTERVAL = 3500; 
/* Refresh interval should not be above 16383, because above that the
 *  delayMicroseconds may not be accurate any more.
 *  Source: https://www.arduino.cc/en/Reference/DelayMicroseconds
 */
int SPIN = 9; // servo pin number

void setup() {
  pinMode(SPIN, OUTPUT);
  pinMode(6, OUTPUT); // Additional output, that shows to which position the servo is going (0 or 1).
  noInterrupts();
}

void loop() {
  // Option to change REFRESH_INTERVAL every max_j repetitions.
  // REFRESH_INTERVAL += 1000;
  int max_j = 10;
  for (int j = 0; j < max_j; j++){
    int short_pulse = 544;
    int long_pulse = 2400;
    int short_pause = REFRESH_INTERVAL - short_pulse;
    int long_pause = REFRESH_INTERVAL - long_pulse;
  
    int N = 1000000/REFRESH_INTERVAL; // Switch position every second. 

    // Going to position 0.
    digitalWrite(6, LOW);
    for (int i = 0; i < N; i++){
      digitalWrite(SPIN, HIGH);
      delayMicroseconds(short_pulse);
      digitalWrite(SPIN, LOW);
      delayMicroseconds(short_pause);
    }

    // Going to position 1.
    digitalWrite(6, HIGH);
    for (int i = 0; i < N; i++){
      digitalWrite(SPIN, HIGH);
      delayMicroseconds(long_pulse);
      digitalWrite(SPIN, LOW);
      delayMicroseconds(long_pause);
    }
  }
}
