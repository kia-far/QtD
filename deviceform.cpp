#include "deviceform.h"
#include "ui_deviceform.h"
#include "itemhandler.h"
#include "myfunctions.h"
#include <QShortcut>
#include <QKeyEvent>
#include <QBoxLayout>
#include <QDebug>
#include <QAction>
#include "QSqlRecord"
#include <QMessageBox>

DeviceForm::DeviceForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceForm),
    db(DatabaseConnection::getInstance())
{
    ui->setupUi(this);
    admiMode=false;
    setup();
    if(!admiMode){ui->AddItemBtn->hide();}
//    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q), this, SLOT(this.close()));
    keyBinds();

}
int indexx;
int indexcounter = 0;
DeviceForm::~DeviceForm()
{

    delete ui;
}

void DeviceForm::trigger(QString device){
    clearPage();
    admiMode = false;
    currentDevice = device;
    this->show();
    setup();
}

void DeviceForm::setup(){
    if(!admiMode){ui->AddItemBtn->hide();}
    else {ui->AddItemBtn->show();}
    edit = false;
    // admiMode = false;
    QString curDev = currentDevice;
    QStringList devices = ItemHandler::loadDevices();
    ui->comboBox->clear();
    for(int i=0;i<devices.length();i++){
    ui->comboBox->addItem(devices[i]);}
    ui->comboBox->setCurrentText(curDev);
    if(admiMode){
    ui->comboBox->addItem("دستگاه جدید");}
    ui->comboBox->setFixedWidth(120);
    ui->pushButton->setFixedWidth(25);
}
void DeviceForm::editDevice(QString device , int id){
    this->show();
    currentDevice = device;
    admiMode = false;
    setup();
    ui->comboBox->setCurrentText(device);
    ui->lineEdit->setText(MyFunctions::intToStr(id));
    populateEdit(device,id);
}
void DeviceForm::refresh(){
    clearLayout(ui->vb);
    labels.clear();
    comboBoxes.clear();
    addBtns.clear();
    QStringList currentItems = ItemHandler::loadItems(currentDevice);
    for (int i=0;i<currentItems.size() ;i++ ) {
        createNewItem(currentItems[i] , i);
    }
}
void DeviceForm::on_comboBox_currentIndexChanged(const QString &arg1)
{
    if(arg1=="دستگاه جدید"){
        addDevice();
        ui->comboBox->setCurrentIndex(0);
    }
    else{
    clearLayout(ui->vb);
    clearLayout(ui->cbg);
    labels.clear();
    comboBoxes.clear();
    addBtns.clear();
    checkBoxes.clear();
    currentDevice = arg1;
    QStringList currentItems = ItemHandler::loadItems(arg1);
    for (int i=0;i<currentItems.size() ;i++ ) {
        createNewItem(currentItems[i] , i);
    }
    QStringList belongings = ItemHandler::loadbelongings(arg1);
    for (int i=0;i<belongings.size();i++){
        createBelonging(belongings[i],i);
    }
    if(admiMode){
    QPushButton *newBelBtn = new QPushButton();
    QString buttonName = QString("افزودن متعلقات");
    newBelBtn->setObjectName("newBelBtn");
    newBelBtn->setText("افزودن متعلقات");
//    newBelBtn->setFixedWidth(25);
    connect(newBelBtn, &QPushButton::clicked, this, [this ,arg1](){addBelonging (arg1);});
    indexx++;
    ui->cbg->addWidget(newBelBtn,indexx/2,indexx%2);}
}}
void DeviceForm::createBelonging(QString itemName,int index){
    QCheckBox *checkBox = new QCheckBox(itemName);
    QString checkBoxName = QString("check_%1").arg(index);
    checkBox->setObjectName(checkBoxName);
    checkBox->setMinimumHeight(25);
//    checkBox->setText(itemName);
    checkBoxes.append(checkBox);
    ui->cbg->addWidget(checkBox,index/2,index%2);
    indexx = index;
    ui->cbg->setRowMinimumHeight(index/2,30);
}

void DeviceForm::createNewItem(QString itemName, int index) {
    adder = 0;
    indexcounter += 1;

    QLabel *label = new QLabel(itemName);
    QString labelName = QString("label_%1").arg(index + 10 * indexcounter);
    label->setObjectName(labelName);

    // Set size policy to adjust based on content
    label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    label->setAlignment(Qt::AlignCenter);
    label->adjustSize();

    labels.append(label);

    QComboBox *comboBox = new QComboBox();
    QString comboBoxName = QString("comboBox_%1").arg(index + 10 * indexcounter);
    comboBox->insertItem(0, "هیچ کدام");
    comboBox->insertItems(1, setupOptions(itemName));

    if (admiMode) {
        comboBox->insertItem(setupOptions(itemName).size() + 1, "افزودن گزینه");
        connect(comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [this, itemName](int index) {
            if (index == setupOptions(itemName).size() + 1) {
                addOption(currentDevice, itemName);
            }
        });
    }

    // Set size policy and adjust combo box as well
    comboBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    comboBox->adjustSize();

    comboBoxes.append(comboBox);

    QString hbName = QString("hb_%1").arg(index);
    QHBoxLayout *hb = new QHBoxLayout;

    // Set alignment and add widgets to layout
    label->setAlignment(Qt::AlignCenter);
    hb->addWidget(comboBox);
    hb->addWidget(label);

    ui->vb->addLayout(hb);
    hb->setObjectName(hbName);
}


QStringList DeviceForm::setupOptions(QString itemName){
    return ItemHandler::loadOptions(currentDevice,itemName);
}

void DeviceForm::clearLayout(QLayout *layout) {

    if (layout == NULL)
        return;
    QLayoutItem *item;
    while((item = layout->takeAt(0))) {
        if (item->layout()) {
            clearLayout(item->layout());
            delete item->layout();
        }
        if (item->widget()) {
           delete item->widget();
        }
        //delete item;
    }
}
void DeviceForm::populateEdit(QString device,int id){
    edit = true;
    QString newText="";
    QSqlQuery query(db.getConnection());

    QStringList res;

    query.prepare("SELECT * FROM " + device + " WHERE SerialNumber LIKE "+QString::number(id));

    if (query.exec()) {
        QSqlRecord record = query.record();
        int numCols = record.count();
//        qDebug() << "Fetch the results";
        while (query.next()) {
            for (int i=0;i<numCols;i++){
            res.append( query.value(i).toString());
        }}
    } else {
        qDebug() << "Query execution failed:" << query.lastError().text();
    }

    ui->CustomerCombo->setCurrentText(res[1]);
    ui->textEdit->setText(res[2]);
    QStringList columns={"SerialNumber", "CustomerName" ,"description","belongings"};

    QString checks = "";
    for (QCheckBox *checkBox : checkBoxes){
//        if(checkBox->isChecked()){
//        checks.append(checkBox->text()+" ");}
        if(res[3].contains(checkBox->text())){checkBox->setChecked(true);}
        else{checkBox->setChecked(false);}
    }
    int count =4;
//    QVariantList givenData = {MyFunctions::reverseSN( ui->lineEdit->text()).toInt(),ui->CustomerCombo->currentText(),ui->textEdit->toPlainText(), checks};
    for (QComboBox *comboBox : comboBoxes) {
//        QString text = comboBox->currentText();
//        qDebug() << "Data" << comboBox->objectName() << ":" << text;
//        givenData.append(text);
    comboBox->setCurrentText(res[count]);
    count++;
    }

//    ItemHandler::insertDataIntoTable(currentDevice,columns,givenData);

}
void DeviceForm::on_SubmitBtn_clicked()
{

    if(MyFunctions::checkSN( ui->lineEdit->text())){
        if(!MyFunctions::deviceFromLetter(ui->lineEdit->text(),currentDevice)){
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle("Error");
            msgBox.setText("شماره سریال با نوع دستگاه مطابقت ندارد"
                           "آیا مطمئنید؟");
            msgBox.setStandardButtons(QMessageBox::Yes| QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::No);
            int res = msgBox.exec();
            switch(res) {
            case QMessageBox::Yes :{
                submit();
                break;
            }
            case QMessageBox::No :{
                break;
            }
            default :
                break;

            }
        }
        else{
            submit();

        }
}
    else{        QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.setWindowTitle("Error");
    msgBox.setText("شماره سریال صحیح نمیباشد");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();}
}

void DeviceForm::addOption(QString deviceName,QString itemName){
//    qDebug() << "option possibly added : " << itemName;
    emit optionPage(deviceName,itemName);
}
void DeviceForm::addItem(QString deviceName){
    emit itemPage(deviceName);
}
void DeviceForm::addDevice(){
    emit devicePage();
}

void DeviceForm::submit(){
    QString newText="";
    QStringList columns={"SerialNumber", "CustomerName" ,"description","belongings"};
    //description TEXT, belongings TEXT
    for (QLabel *label : labels) {
        QString text = label->text(); // Get the text from the QLineEdit
        //        qDebug() << "column" << label->objectName() << ":" << text;
        for(int i=0;i<text.size(); i++){
            if (text.at(i)==" "){newText.append("_");}
            else{newText.append(text.at(i));}
        }
        columns.append(text);
    }
    QString checks = "";
    for (QCheckBox *checkBox : checkBoxes){
        if(checkBox->isChecked()){
            checks.append(checkBox->text()+" ");}
    }
    QVariantList givenData = {MyFunctions::reverseSN( ui->lineEdit->text()).toInt(),ui->CustomerCombo->currentText(),ui->textEdit->toPlainText(), checks};
    for (QComboBox *comboBox : comboBoxes) {
        QString text = comboBox->currentText();
        //        qDebug() << "Data" << comboBox->objectName() << ":" << text;
        givenData.append(text);
    }
    if (!edit){
        QSqlQuery q(db.getConnection());
        q.prepare("INSERT INTO ProductInfo (SerialNO , ProductName) VALUES (? ,?)");
        q.addBindValue(givenData[0].toString());
        q.addBindValue(currentDevice);

        bool er = q.exec();
        if (!er) {
            qDebug() << "Error in ProductInfo insert:" << q.lastError().text();
        }
        q.prepare("INSERT INTO ProductSecInfo (SerialNO) VALUES (?)");
        q.addBindValue(givenData[0].toString());

        bool err = q.exec();
        if (!err) {
            qDebug() << "Error in ProductSecInfo insert:" << q.lastError().text();
        }
        if(er&&err){
            ItemHandler::insertDataIntoTable(currentDevice,columns,givenData);
            this->close();
        }
        else{
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setWindowTitle("Error");
            msgBox.setText("شماره سریال تکراری است");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();
        }

    }
    else {
        ItemHandler::updateTable(currentDevice,columns,givenData);
        this->close();
    }
}

void DeviceForm::addBelonging(QString deviceName){
    emit belongingPage(deviceName);
}
void DeviceForm::clearPage(){
    for (QCheckBox *checkbox : checkBoxes){checkbox->setChecked(false);}
    for (QComboBox *combobox : comboBoxes){combobox->setCurrentIndex(0);}
    ui->CustomerCombo->setCurrentText("");
    ui->textEdit->setText("");
    ui->lineEdit->setText("");
}
void DeviceForm::on_AddItemBtn_clicked()
{
    addItem(currentDevice);
}


QStringList DeviceForm::getCustomers(QString halfText) {
    QSqlQuery query(db.getConnection());

    QStringList res;

    query.prepare("SELECT Name FROM CustomerInfo WHERE Name LIKE :halfText LIMIT 5");
    query.bindValue(":halfText", "%" + halfText + "%");  // Use wildcards for partial match

    // Execute the query
    if (query.exec()) {
//        qDebug() << "Fetch the results";
        while (query.next()) {
            res << query.value(0).toString();  // Assuming 'name' is the first column
        }
    } else {
        qDebug() << "Query execution failed:" << query.lastError().text();
    }

    return res;
}

void DeviceForm::on_CustomerCombo_editTextChanged(const QString &arg1) {
    ui->CustomerCombo->blockSignals(true);
    ui->CustomerCombo->clear();
    QStringList customers = getCustomers(arg1);
    ui->CustomerCombo->addItems(customers);
    ui->CustomerCombo->setCurrentText(arg1);
    ui->CustomerCombo->blockSignals(false);
}



void DeviceForm::on_pushButton_clicked()
{
    emit addCustomer();
}



void DeviceForm::adminMode(){
    admiMode= !admiMode;
    // if(!admiMode){ui->AddItemBtn->hide();}
    // else {ui->AddItemBtn->show();}
    setup();
}




void DeviceForm::keyBinds(){
    QAction *f0 = new QAction(this);
    f0->setShortcut(Qt::Key_Q | Qt::CTRL);

    connect(f0, SIGNAL(triggered()), this, SLOT(close()));
    this->addAction(f0);
    QAction *f1 = new QAction(this);
    f1->setShortcut(Qt::Key_S | Qt::CTRL);

    connect(f1, SIGNAL(triggered()), this, SLOT(on_SubmitBtn_clicked()));
    this->addAction(f1);
    QAction *f2 = new QAction(this);
    f2->setShortcut(Qt::Key_M | Qt::CTRL);

    connect(f2, SIGNAL(triggered()), this, SLOT(adminMode()));
    this->addAction(f2);

}

