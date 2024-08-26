#include "tables.h"
#include "ui_tables.h"
#include "myfunctions.h"
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QtDebug>
#include <QApplication>
#include <QFile>
#include <QTextStream>


int lastClicked =0;
int currentTable =0;
int editSelect =0;
int clickedID =0;
//bool inSearch=false;
QString searchParam;

Tables::Tables(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tables),
    View(new ProxyView(this)),
    Product(new ProductProxy(this))

{

    ui->setupUi(this);
//    ui->Edit->hide();
//    QSqlDatabase db;
//    db = QSqlDatabase ::addDatabase("QSQLITE");
//    db.setDatabaseName("C:\\Users\\kiafa\\Desktop\\Job\\DB\\sqlitestudio_x64-3.4.4\\SQLiteStudio\\InfoDB");
//    db.open();

    ui->tableView->setModel(Product);
    QFile file("C:/Users/kiafa/Documents/build-QtDBS-Desktop_Qt_5_12_12_MinGW_64_bit-Debug/style/Style.qss"); // Use resource system or provide a direct path
    if (file.open(QFile::ReadOnly)) {
        QTextStream stream(&file);
        QString styleSheet = stream.readAll();
        this->setStyleSheet(styleSheet);
        file.close();
    }

    ui->tableView->setAlternatingRowColors(true);
    currentTable = 3;
}

Tables::~Tables()
{
    delete ui;
}

void Tables::searchInfo(QString currentSearchParam,QString searchText){
    searchParam = currentSearchParam;
    qDebug()<<QString::number(currentTable)+"  "  + "  "+ searchParam+ "   " +searchText;
    if(currentTable==0){





//        QSqlQuery query;
        QString res;
        if (searchText==""){res = "SELECT * FROM CustomerInfo";}
        else{res = "SELECT * FROM CustomerInfo WHERE "+searchParam+" LIKE '%"+searchText+"%'";}
        QSqlQuery query(dbConnection.getConnection());
        query.exec(res);
        QSqlQueryModel *m = new QSqlQueryModel;
        m -> setQuery(query);

        ui->tableView->setModel(m);

    }
    else if (currentTable==1) {
        QSqlQuery query(dbConnection.getConnection());
        QString res;
        if(searchText==""){res = "SELECT * FROM ServiceInfo";}
        else{res = "SELECT * FROM ServiceInfo WHERE "+searchParam+" LIKE '%"+searchText+"%'";}
        query.exec(res);
        QSqlQueryModel *m = new QSqlQueryModel;
        m -> setQuery(query);
        ui->tableView->setModel(m);

    }
    else if(currentTable==2){

        View->setSearchParameters(searchParam, searchText);
        ui->tableView->setModel(View);

    }
    else {
        Product->setSearchParameters(searchParam,searchText);
        ui->tableView->setModel(Product);

    }
}
void Tables::on_comboBox_currentIndexChanged(const QString &arg1)
{
    if(arg1 == "Products"){
        ui->tableView->setModel(Product);


        currentTable =3;
    }
    else if(arg1 == "Customers"){
        QSqlQuery q(dbConnection.getConnection());
        q.exec("SELECT * FROM CustomerInfo");
        QSqlQueryModel *m = new QSqlQueryModel;
        m -> setQuery(q);
        ui->tableView->setModel(m);

        currentTable = 0;
    }
    else if (arg1 == "Services"){
        QSqlQuery q(dbConnection.getConnection());
        q.exec("SELECT * FROM ServiceInfo");
        QSqlQueryModel *m = new QSqlQueryModel;
        m -> setQuery(q);
        ui->tableView->setModel(m);
        currentTable =1;
    }
    else if (arg1 == "Devices") {
        QString aa = "SerialNum";
        QString bb = "";
        View->setSearchParameters(aa, bb);

        ui->tableView->setModel(View);
        currentTable = 2;
    }
}


void Tables::on_EditBtn_clicked()
{
    if (currentTable == 0){emit editCustomer(clickedID);}
    else if (currentTable == 1){emit editService(clickedID);}
    else if (currentTable == 2){emit editDevice(lastClicked);}
    else {emit editProduct(lastClicked );}
}


void Tables::on_tableView_clicked(const QModelIndex &index)
{
    int selectedRow = index.row();
//    qDebug() << "Selected row:" << selectedRow;
    QVariant data = ui->tableView->model()->data(ui->tableView->model()->index(selectedRow, 0));
//    qDebug() << "Data in the first column of the selected row:" << data.toString();
    lastClicked = (MyFunctions ::reverseSN(data.toString())).toInt();
    clickedID = data.toInt();
}


void Tables::on_SearchBtn_clicked()
{
    emit searchActive(currentTable);
}


void Tables::on_AddBtn_clicked()
{
    if (currentTable==3){emit addProduct();}
    else if(currentTable==2){emit addDevice();}
    else if(currentTable==1){emit addService();}
    else{emit addCustomer();}
}


void Tables::on_RefreshBtn_clicked()
{
    emit refreshActive(currentTable);
}

