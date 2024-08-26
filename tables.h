#ifndef TABLES_H
#define TABLES_H

#include <QWidget>
#include "proxyview.h"
#include "productproxy.h"
#include <DatabaseConnection.h>

namespace Ui {
class Tables;
}

class Tables : public QWidget
{
    Q_OBJECT

public:
    explicit Tables(QWidget *parent = nullptr);
    ~Tables();
    void searchInfo(QString searchParam,QString searchText);


signals:
    void editDevice(int serialNum);
    void edit(int serialNum,int index);
    void searchActive(int current);
    void editProduct(int serialNum);
    void refreshActive(int current);
    void addProduct();
    void addDevice();
    void addService();
    void editService(int serialNum);
    void addCustomer();
    void editCustomer(int serialNum);

private slots:
    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_EditBtn_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_SearchBtn_clicked();

    void on_AddBtn_clicked();

    void on_RefreshBtn_clicked();


private:
    Ui::Tables *ui;
    ProxyView *View;
    ProductProxy *Product;
    DatabaseConnection& dbConnection = DatabaseConnection::getInstance();

};

#endif // TABLES_H
