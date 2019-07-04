#ifndef GPIOOUTPUT_H
#define GPIOOUTPUT_H

/* Class to set the value of a gpio output using /sys/class/gpio
 *
 */

#include <QByteArray>

class GpioOutput 
{
public:
    GpioOutput(int number);
    virtual ~GpioOutput();
    bool value(bool value);

protected:
    int _number;
    QByteArray _numberStr;
};

#endif // GPIOOUTPUT_H
