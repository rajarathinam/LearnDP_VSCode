// ATMEvents.h
#pragma once
#include <string>

// Base class for all events
class ATMEvent {
public:
    virtual ~ATMEvent() {}
};

// Event for card insertion
class CardInsertedEvent : public ATMEvent {
public:
    std::string cardNumber;
    CardInsertedEvent(const std::string& cardNum) : cardNumber(cardNum) {}
};

// Event for PIN entry
class PinEnteredEvent : public ATMEvent {
public:
    std::string pin;
    PinEnteredEvent(const std::string& p) : pin(p) {}
};

// Event for withdrawal request
class WithdrawalRequestEvent : public ATMEvent {
public:
    float amount;
    WithdrawalRequestEvent(float amt) : amount(amt) {}
};

// Event for cash dispensed
class CashDispensedEvent : public ATMEvent {
public:
    float dispensedAmount;
    CashDispensedEvent(float amt) : dispensedAmount(amt) {}
};
