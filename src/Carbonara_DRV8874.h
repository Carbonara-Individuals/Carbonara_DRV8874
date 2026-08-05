// Self Definition
#ifndef CARBONARA_DRV8874_H
#define CARBONARA_DRV8874_H

// Dependenices
#include <Arduino.h>
#include <inttypes.h>

class Carbonara_DRV8874 {
    public:
        Carbonara_DRV8874(int enablePin, int phasePin, int sleepPin);
        // -- Initialization Functions --
        void begin();
        void beginSensing();
        void FAILSAFE(bool enable);

        // -- Motor Control Functions --
        void set(float output);
        void setInverted(bool isInverted);
        void setBrakeMode(bool isBrakeMode);

        // -- Pin Configuration Pins -- 
        void configEnablePin(int enablePin);
        void configPhasePin(int phasePin);
        void configSleepPin(int sleepPin);

        // Advance pin configurations
        void configFaultPin(int faultPin);
        void configIpropIPin(int iPropIPin);

        // -- Status Functions --
        bool isFault();
        float getCurrent();

    private:
        // Pin Configuration Variables
        int enablePin;
        int phasePin;
        int sleepPin;
        // Advanced sensing pins
        int faultPin = -1;
        int iPropIPin = -1;

        // Motor Driver State Variables
        bool inverted = false;
        bool brakeMode = false;
        bool isSensingActive = false;
        bool isFaultActive = false;
        float motorCurrent = 0;
};

#endif
