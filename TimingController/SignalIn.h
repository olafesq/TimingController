//#pragma once
class SignalIn{ //class for input signal
public:
	SignalIn(uint8_t SENSOR, uint8_t SPARK)	{ //pinnumber as input variable
		this->sparkPin = SPARK;
		this->sensorPin = SENSOR;
	}

	void makeSpark() {
		digitalWrite(sparkPin, HIGH);
		delayMicroseconds(1000);
		digitalWrite(sparkPin, LOW);
		counter++;
			Serial.println(counter);
		
		if (counter == marks) {
			calcRPM(); 
			counter = 0;
		}
		
}

private:
	uint8_t marks = 4; //number of marks/shutter vanes on the VR sensor
	uint32_t counter = 0; //counts the marks
	uint8_t sparkPin = 13;
	uint8_t sensorPin = 2;
	uint32_t time = 0;

	void calcRPM() {
		uint8_t duration = millis() - time;
		time = time + duration;
		uint8_t rpm = (60 * 1000) / duration;
		
		Serial.println(rpm);
	}
};

