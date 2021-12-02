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
        //  ��������� ������ �������� �������
        if (_buttonCount != 0) _buttonCount--; // ������� ������������� - 1 � ������������ �� 0 
    }
    else {
        // ��������� ������ ����������
        _buttonCount++;   // +1 � �������� �������������
        if (_buttonCount >= _timeButton) {
            // ��������� ������� �������� ������ _timeButton
            flagPress = !flagPress; // �������� �������� ���������
            _buttonCount = 0;  // ����� �������� �������������
            if (flagPress == true) flagClick = true; // ������� ����� ������       
        }
    }
}


