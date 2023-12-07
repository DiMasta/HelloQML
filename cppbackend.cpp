#include "cppbackend.h"

CppBackend::CppBackend(QObject* parent):
    QObject(parent),
    frontValue(0),
    backValue(0),
    flipped(false),
    pendingUpdate(false)
{

}

void CppBackend::onQmlButtonClicked() {
    //qDebug() << "Button Clicked from C++!";
    setFlipped(!flipped);
    pendingUpdate = true;
}

void CppBackend::onAngleChanged(qreal angle) {
    //qDebug() << "Angle: " << angle;
    if (angle > MIDDLE_ANGLE && pendingUpdate && flipped) {
        setFrontValue(frontValue + 1);
        pendingUpdate = false;
    }

    if (angle < MIDDLE_ANGLE && pendingUpdate && !flipped) {
        setBackValue(backValue - 1);
        pendingUpdate = false;
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
