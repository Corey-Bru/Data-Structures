#ifndef PART_H
#define PART_H

#include <iostream>
#include <string>

class Part {
private:
    int SKU;
    std::string Description;
    double Price;
    std::string UOM;
    int QuantityOnHand;
    int LeadTime;

public:
    // Constructor
    Part(int sku, std::string desc, double price, std::string uom, int qty = 0, int lead = 0)
        : SKU(sku), Description(desc), Price(price), UOM(uom), QuantityOnHand(qty), LeadTime(lead) {
    }

    std::string GetPartInfo() const {
        return std::to_string(SKU) + " - " + Description;
    }

    double GetPrice() const {
        return Price;
    }

    bool InStock() const {
        return QuantityOnHand > 0;
    }

    bool Available(int requestedDate) const {
        return (QuantityOnHand > 0) || (requestedDate > LeadTime);
    }

    // Operator Overloads for comparison
    bool operator>(const Part& other) const {
        return SKU > other.SKU;
    }

    bool operator<(const Part& other) const {
        return SKU < other.SKU;
    }

    bool operator==(const Part& other) const {
        return SKU == other.SKU;
    }

    // Display function for ASCII art representation
    void Display() const {
        std::cout << "----------------------------------\n";
        std::cout << "| SKU: " << SKU << "\n";
        std::cout << "| Desc: " << Description << "\n";
        std::cout << "| Price: $" << Price << "\n";
        std::cout << "| UOM: " << UOM << "\n";
        std::cout << "| Qty: " << QuantityOnHand << "\n";
        std::cout << "| Lead Time: " << LeadTime << " days\n";
        std::cout << "----------------------------------\n";
    }
};

#endif
