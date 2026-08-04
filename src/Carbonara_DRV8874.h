#ifndef CARBONARA_DRV8874_H
#define CARBONARA_DRV8874_H

#include <inttypes.h>

class Carbonara_DRV8874 {
    public:
        Carbonara_DRV8874(uint8_t enablePin, uint8_t phasePin, uint8_t sleepPin);
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
        // Nothing here just yet...
};

#endif