#include "cppbackend.h"

CppBackend::CppBackend(QObject* parent):
    QObject(parent)
{
    frontValue = nextCountingValue(countingIdx);
}

void CppBackend::onQmlButtonClicked() {
    //qDebug() << "Button Clicked from C++!";
    setFlipped(!flipped);
    pendingUpdate = true;
}

void CppBackend::onAngleChanged(qreal angle) {
    //qDebug() << "Angle: " << angle;
    if (angle > MIDDLE_ANGLE && pendingUpdate && flipped) {
        ++countingIdx;
        setBackValue(nextCountingValue(countingIdx));
        pendingUpdate = false;
    }

    if (angle < MIDDLE_ANGLE && pendingUpdate && !flipped) {
        ++countingIdx;
        setFrontValue(nextCountingValue(countingIdx));
        pendingUpdate = false;
    }
}

int CppBackend::nextCountingValue(const int idx) const {
    if (idx < 0) {
        return 0;
    }
    else if (idx <= 1) {
        return idx;
    } else {
        int a = 0;
        int b = 1;
        int fib = 0;
        for (int i = 2; i <= idx; ++i) {
            fib = a + b;
            a = b;
            b = fib;
        }
        return fib;
    }
}

int CppBackend::getFrontValue() const {
    return frontValue;
}

void CppBackend::setFrontValue(int value) {
    if (frontValue != value) {
        frontValue = value;
        emit frontValueChanged();
    }
}

int CppBackend::getBackValue() const {
    return backValue;
}

void CppBackend::setBackValue(int value) {
    if (backValue != value) {
        backValue = value;
        emit backValueChanged();
    }
}

bool CppBackend::getFlipped() const {
    return flipped;
}

void CppBackend::setFlipped(const bool value) {
    if (flipped != value) {
        flipped = value;
        emit flippedChanged();
    }
}
