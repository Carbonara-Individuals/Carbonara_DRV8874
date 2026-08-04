
/*
NOTES:
1. enPin uses PWM therefore uses analogWrite() .
2. phasePin is on or off based so it uses digitalWrite().
*/
#include "Carbonara_DRV8874.h"


float constrainSetInputs(float &output) {
    output = constrain(output, -1.0f, 1.0f);
    output *= 255.0f;
    return output;
}

Carbonara_DRV8874::Carbonara_DRV8874(int enablePin, int phasePin, int sleepPin) {
    this->enablePin = enablePin;
    this->phasePin = phasePin;
    this->sleepPin = sleepPin;
}

void Carbonara_DRV8874::begin() {
    pinMode(enablePin, OUTPUT);
    pinMode(phasePin, OUTPUT);
    pinMode(sleepPin, OUTPUT);

    digitalWrite(sleepPin, HIGH); // Wake motor driver
}

void Carbonara_DRV8874::FAILSAFE(bool enable) {
    // Failsafe code here
}

void Carbonara_DRV8874::set(float output) {
    // Constrain and rescale the output range
    float motorPower = constrainSetInputs(output);
    motorPower = Inverted ? -motorPower : motorPower;

    // Normal operation code here
    analogWrite(enablePin, abs(motorPower));
    digitalWrite(phasePin, motorPower >= 0 ? HIGH : LOW);
}


// --- Motor Driver State Functions ---
void Carbonara_DRV8874::setInverted(bool isInverted) {
    Inverted = isInverted;
}

void Carbonara_DRV8874::setBrakeMode(bool isbrakeMode) {
    brakeMode = isbrakeMode;
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
    // Check for fault code here
    return false; // Placeholder return value
}

float Carbonara_DRV8874::getCurrent() {
    // Get current code here
    return 0.0f; // Placeholder return value
}