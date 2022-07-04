#include "product.h"

Product::Product(QString _name, QString _manufacturer, long long int _price, QString _expiry_date)
{
    this->name = _name;
    this->manufacturer = _manufacturer;
    this->price = _price;
    this->expiry_date = _expiry_date;
    return;

}
