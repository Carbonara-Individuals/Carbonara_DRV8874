/*
NOTES:
1. enPin uses PWM therefore uses analogWrite().
2. phasePin & sleepPin is on or off based so it uses digitalWrite().
3. faultPin uses is on or of therefore uses digitalRead().
4. iPropIPin uses PWM therefore uses analogRead().
*/
#include "Carbonara_DRV8874.h"


Carbonara_DRV8874::Carbonara_DRV8874(int enablePin, int phasePin, int sleepPin) {
    this->enablePin = enablePin;
    this->phasePin = phasePin;
    this->sleepPin = sleepPin;
}

float constrainSetInputs(float &output) {
    float constrainedOutput = constrain(output, -1.0f, 1.0f);
    constrainedOutput *= 255.0f;
    return constrainedOutput;
}

void Carbonara_DRV8874::begin() {
    // Inititalize the pins
    pinMode(enablePin, OUTPUT);
    pinMode(phasePin, OUTPUT);
    pinMode(sleepPin, OUTPUT);

    digitalWrite(sleepPin, HIGH); // Wake motor driver
}

void Carbonara_DRV8874::beginSensing() {
    pinMode(faultPin, INPUT);
    pinMode(iPropIPin, INPUT);
    isSensingActive = true;
}

void Carbonara_DRV8874::FAILSAFE(bool enable) {
    if (isSensingActive && enable && isFaultActive) {
        digitalWrite(sleepPin, LOW);
    } else {
        digitalWrite(sleepPin, HIGH);
    }
}

void Carbonara_DRV8874::set(float output) {
    // Constrain and rescale the output range
    float motorPower = constrainSetInputs(output);
    motorPower = Inverted ? -motorPower : motorPower;

    if (motorPower == 0 && brakeMode) {
        // Brake mode operation code
        analogWrite(enablePin, 255);
        digitalWrite(phasePin, LOW);
    } else {
        // Normal operation code
        analogWrite(enablePin, abs(motorPower));
        digitalWrite(phasePin, motorPower >= 0 ? HIGH : LOW);
    }
}


// --- Motor Driver State Functions ---
void Carbonara_DRV8874::setInverted(bool isInverted) {
    inverted = isInverted;
}

void Carbonara_DRV8874::setBrakeMode(bool isBrakeMode) {
    brakeMode = isBrakeMode;
}


// --- Pin Configuration Functions ---
void Carbonara_DRV8874::configEnablePin(int enablePin) {
    this->enablePin = enablePin;
}

void Carbonara_DRV8874::configPhasePin(int phasePin) {
    this->phasePin = phasePin;
}

void Carbonara_DRV8874::configSleepPin(int sleepPin) {
    this->sleepPin = sleepPin;
}

void Carbonara_DRV8874::configFaultPin(int faultPin) {
   this->faultPin = faultPin;
}

void Carbonara_DRV8874::configIpropIPin(int iPropIPin) {
    this->iPropIPin = iPropIPin;
}


// --- Feedback Functions ---
bool Carbonara_DRV8874::isFault() {
    if (isSensingActive) {
        isFaultActive = !digitalRead(faultPin);
        return isFaultActive;
    } else {
        return false;
    }
}

float Carbonara_DRV8874::getCurrent() {
    if (isSensingActive) {
        motorCurrent = analogRead(iPropIPin);
        return motorCurrent;
    } else {
        return 0.0f;
    }
}