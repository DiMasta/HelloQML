#ifndef CPPBACKEND_H
#define CPPBACKEND_H

#include <QObject>
#include <QDebug>

static const qreal MIDDLE_ANGLE = 90.0;

class CppBackend : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int frontValue READ getFrontValue WRITE setFrontValue NOTIFY frontValueChanged)
    Q_PROPERTY(int backValue READ getBackValue WRITE setBackValue NOTIFY backValueChanged)
    Q_PROPERTY(bool flipped READ getFlipped WRITE setFlipped NOTIFY flippedChanged)

public:
    explicit CppBackend(QObject* parent = nullptr);

    int getFrontValue() const;
    void setFrontValue(const int value);

    int getBackValue() const;
    void setBackValue(const int value);

    bool getFlipped() const;
    void setFlipped(const bool value);

signals:
    void frontValueChanged();
    void backValueChanged();
    void flippedChanged();

public slots:
    void onQmlButtonClicked();
    void onAngleChanged(qreal angle);

private: ///< Function members

    /// Return the counting value based on the counting index reached
    int nextCountingValue(const int idx) const;

private: ///< Data members
    int frontValue = 0;
    int backValue = 0;
    int countingIdx = 8; ///< The index to which the counting have reached
    bool flipped = false;
    bool pendingUpdate = false;
};

#endif // CPPBACKEND_H
