// EventHandlers.h
#pragma once
#include "EventPublisher.h"
#include "ATMEvents.h"
#include <iostream>

class ATMEventHandler {
public:
    static void handleCardInserted(std::shared_ptr<ATMEvent> event) {
        auto cardInsertedEvent = std::dynamic_pointer_cast<CardInsertedEvent>(event);
        if (cardInsertedEvent) {
            std::cout << "Card inserted with number: " << cardInsertedEvent->cardNumber << std::endl;
            // Trigger the next event (PIN entry, in real ATM this would wait for user input)
        }
    }

    static void handlePinEntered(std::shared_ptr<ATMEvent> event) {
        auto pinEnteredEvent = std::dynamic_pointer_cast<PinEnteredEvent>(event);
        if (pinEnteredEvent) {
            std::cout << "PIN entered: " << pinEnteredEvent->pin << std::endl;
            // Trigger next event (like a balance check)
        }
    }

    static void handleWithdrawalRequest(std::shared_ptr<ATMEvent> event) {
        auto withdrawalRequestEvent = std::dynamic_pointer_cast<WithdrawalRequestEvent>(event);
        if (withdrawalRequestEvent) {
            std::cout << "Withdrawal requested: " << withdrawalRequestEvent->amount << std::endl;
            // Check balance and trigger cash dispense
        }
    }

    static void handleCashDispensed(std::shared_ptr<ATMEvent> event) {
        auto cashDispensedEvent = std::dynamic_pointer_cast<CashDispensedEvent>(event);
        if (cashDispensedEvent) {
            std::cout << "Cash dispensed: " << cashDispensedEvent->dispensedAmount << std::endl;
            // Print receipt
        }
    }
};
#pragma once
