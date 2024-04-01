#ifndef INTERFACES_TAXABLE_HPP
#define INTERFACES_TAXABLE_HPP

class Taxable {
    public:
    virtual int calculate_tax() = 0;
};

#endif