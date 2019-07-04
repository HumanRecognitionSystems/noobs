#include "gpiooutput.h"
#include <QFile>
#include <QDebug>

/* Class to set the value of a gpio output using /sys/class/gpio
 *
 */

GpioOutput::GpioOutput(int number)
    : _number(number)
{
    if(_number == 0){
        return;
    }
    _numberStr = QByteArray::number(_number);
    QFile f("/sys/class/gpio/export");
    f.open(f.WriteOnly);
    f.write(_numberStr+"\n");
    f.close();
    f.setFileName("/sys/class/gpio/gpio"+_numberStr+"/direction");
    f.open(f.WriteOnly);
    f.write("out\n");
    f.close();
}

GpioOutput::~GpioOutput()
{
    if(_number == 0){
        return;
    }
    QFile f("/sys/class/gpio/unexport");
    f.open(f.WriteOnly);
    f.write(_numberStr+"\n");
    f.close();
}

bool GpioOutput::value(bool value)
{
    if(_number == 0){
        return false;
    }
    bool ok;

    QFile f("/sys/class/gpio/gpio"+_numberStr+"/value");
    f.open(f.WriteOnly);
    f.write(QByteArray::number(value) +"\n");
    f.close();
    qDebug() << "gpio" << _number << "value" << value;
    return ok;
}
