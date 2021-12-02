// 
// 
// 

#include "libButton.h"

void libButton::scanState() {
    if (flagPress == (!digitalRead(_pin))) {
        _buttonCount = 0;
    }
    else {
        _buttonCount++;

        if (_buttonCount >= _timeButton) {
            flagPress = !flagPress;
            _buttonCount = 0;
            if (flagPress == true) flagClick = true;
        }
    }
}

void libButton::setPinTime(byte pin, byte timeButton) 
{
    _pin = pin;
    _timeButton = timeButton;
    pinMode(_pin, INPUT_PULLUP);
}

libButton::libButton(byte pin, byte timeButton)
{
    _pin = pin;
    _timeButton = timeButton;
    pinMode(_pin, INPUT_PULLUP);
}

void libButton::filterAvarage() {
    if (flagPress != digitalRead(_pin)) {
        //  состояние кнопки осталось прежним
        if (_buttonCount != 0) _buttonCount--; // счетчик подтверждений - 1 с ограничением на 0 
    }
    else {
        // состояние кнопки изменилось
        _buttonCount++;   // +1 к счетчику подтверждений
        if (_buttonCount >= _timeButton) {
            // состояние сигнала достигло порога _timeButton
            flagPress = !flagPress; // инверсия признака состояния
            _buttonCount = 0;  // сброс счетчика подтверждений
            if (flagPress == true) flagClick = true; // признак клика кнопки       
        }
    }
}


