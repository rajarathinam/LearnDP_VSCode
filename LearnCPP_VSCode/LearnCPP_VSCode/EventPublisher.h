// EventPublisher.h
#pragma once
#include <functional>
#include <vector>
#include <memory>
#include "ATMEvents.h"

class EventPublisher {
private:
    std::vector<std::function<void(std::shared_ptr<ATMEvent>)>> subscribers;

public:
    // Subscribe to an event
    void subscribe(const std::function<void(std::shared_ptr<ATMEvent>)>& handler) {
        subscribers.push_back(handler);
    }

    // Publish an event to all subscribers
    void publish(const std::shared_ptr<ATMEvent>& event) {
        for (const auto& subscriber : subscribers) {
            subscriber(event);
        }
    }
};
