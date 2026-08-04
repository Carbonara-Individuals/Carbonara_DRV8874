#ifndef CARBONARA_DRV8874_H
#define CARBONARA_DRV8874_H

#include <inttypes.h>

class Carbonara_DRV8874 {
    public:
        Carbonara_DRV8874(int enablePin, int phasePin, int sleepPin);
        // -- Initialization Functions --
        void begin();
        void FAILSAFE(bool enable);

        // -- Motor Control Functions --
        void set(float output);
        void setInverted(bool isInverted);
        void setBrakeMode(bool isbrakeMode);

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
        int faultPin;
        int iPropIPin;

        // Motor Driver State Variables
        bool Inverted = false;
        bool brakeMode = false;
};

#endif