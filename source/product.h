#ifndef PRODUCT_H
#define PRODUCT_H

#include <QObject>

class Product
{
public:
    Product(QString name, QString manufacturer, long long int price, QString expiry_date);

private:
    QString name;
    QString manufacturer;
    long long int price;
    QString expiry_date;
};

#endif // PRODUCT_H
