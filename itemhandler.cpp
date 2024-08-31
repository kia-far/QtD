#include "itemhandler.h"
#include "jsonhandler.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QJsonArray>
#include <QFile>
#include <QSqlQuery>

ItemHandler::ItemHandler(QObject *parent)
    : QAbstractItemModel(parent),
      db(DatabaseConnection::getInstance())
{
}

QJsonObject loadedObj;
QJsonObject loadedInfoObj;

void recieveData(){

    JsonHandler::loadJson();

}
QStringList ItemHandler::loadDevices(){
    QJsonObject objs = JsonHandler::loadJson();
    QJsonObject iObjs = JsonHandler::loadInfoJson();
    QStringList tempstr = objs.keys();
//    for( int i=0;i<tempstr.length();i++){
//        qDebug() << "device" << i << " is :" << tempstr[i];
//    }
    loadedObj = objs;
    loadedInfoObj = iObjs;
    return tempstr;
}
QStringList ItemHandler::loadItems(QString device){
//    qDebug() << "loadItems start";
    QJsonArray itemArr = loadedObj[device].toArray();
    QStringList tempstr;
    for (int i=0;i<itemArr.size();i++){
        tempstr.append(itemArr[i].toObject().begin().key());
    }
//    qDebug() <<"item loaded: "<< tempstr;
//    qDebug() << "loadItems end";
    return tempstr;
}
QStringList ItemHandler::loadOptions(QString device, QString item){

    QJsonArray itemArr = loadedObj[device].toArray();
    QStringList tempstr;
    QJsonArray newArr;
    bool iscorrect =false;
    int i =0;
    while(iscorrect == false){
        if (itemArr[i].toObject().begin().key()==item){
            newArr = itemArr[i].toObject().begin().value().toArray();
            iscorrect = true;
        }
        i+=1;
    }
    for (int j=0;j<newArr.size();j++){
        tempstr.append(newArr[j].toString());
    }
    return tempstr;
}

QStringList ItemHandler::loadbelongings(QString device) {
    if (!loadedInfoObj.contains("devices")) {
        qDebug() << "No devices found.";
        return QStringList();
    }
    QJsonArray devicesArray = loadedInfoObj["devices"].toArray();
    bool deviceFound = false;
    QStringList tempstr;
    for (const QJsonValue &deviceValue : devicesArray) {
        QJsonObject deviceObj = deviceValue.toObject();
        if (deviceObj.contains(device)) {
            QJsonArray deviceEntry = deviceObj[device].toArray();
            if (!deviceEntry.isEmpty()) {
                QJsonArray belongingsArr = deviceEntry[0].toObject().value("belongings").toArray();
                for (const QJsonValue &value : belongingsArr) {
                    tempstr.append(value.toString());
                }
                deviceFound = true;
                break;
            } else {
                qDebug() << "No belongings found for device:" << device;
                return QStringList();
            }
        }
    }
    if (!deviceFound) {
        qDebug() << "Device not found:" << device;
        return QStringList();
    }
//    qDebug() << "Belongings loaded: " << tempstr;
    return tempstr;
}



void ItemHandler::addDevices(QString deviceName,QString deviceAbr) {
    addNewInfoDevice(deviceName,deviceAbr);
    QJsonObject deviceObj = loadedObj;
    QJsonArray emptyArr;
    deviceObj.insert(deviceName,emptyArr);
    QJsonDocument updatedDoc(deviceObj);
    JsonHandler::saveJson(updatedDoc);
    DatabaseConnection& db = DatabaseConnection::getInstance();
    QSqlQuery query(db.getConnection());
    QString createTableQuery = QString("CREATE TABLE IF NOT EXISTS %1 (SerialNumber INTEGER PRIMARY KEY,CustomerName TEXT ,description TEXT, belongings TEXT)").arg(deviceName);

    if (!query.exec(createTableQuery)) {
        qDebug() << "Failed to create table:" << query.lastError().text();
    } else {
//        qDebug() << "Table created successfully:" << deviceName;
    }
}
void ItemHandler::addBelonging(QString device, QString itemName) {
    if (!loadedInfoObj.contains("devices")) {
        qDebug() << "No devices found.";
        return;
    }

    QJsonArray devicesArray = loadedInfoObj["devices"].toArray();
    bool deviceFound = false;

    for (int i = 0; i < devicesArray.size(); ++i) {
        QJsonObject deviceObj = devicesArray[i].toObject();
        if (deviceObj.contains(device)) {
            QJsonArray deviceEntry = deviceObj[device].toArray();
            QJsonArray belongingsArr = deviceEntry[0].toObject().value("belongings").toArray();
            belongingsArr.append(itemName);
            QJsonObject updatedDeviceObj = deviceEntry[0].toObject();
            updatedDeviceObj["belongings"] = belongingsArr;
            deviceEntry[0] = updatedDeviceObj;

            deviceObj[device] = deviceEntry;
            devicesArray[i] = deviceObj;

            deviceFound = true;
            break;
        }
    }
    if (!deviceFound) {
        qDebug() << "Device not found:" << device;
        return;
    }
    loadedInfoObj["devices"] = devicesArray;
    QJsonDocument someDoc(loadedInfoObj);
    JsonHandler::saveInfoJson(someDoc);

//    qDebug() << "Added item:" << itemName << "to device:" << device;
}



//void ItemHandler::addDevices(QString deviceName,QJsonArray itemList) {
//    QJsonObject deviceObj = loadedObj;
//    deviceObj.insert(deviceName,itemList);
//    QJsonDocument updatedDoc(deviceObj);
//    JsonHandler::saveJson(updatedDoc);
//}

void ItemHandler::addItems(QString deviceName, QString itemName){
    QJsonArray deviceArr =loadedObj[deviceName].toArray();
    QJsonObject newItem;
    QJsonArray emptyArr;
    newItem.insert(itemName,emptyArr);
    deviceArr.append(newItem);
    QJsonObject deviceObj = loadedObj;
    deviceObj[deviceName] = deviceArr;
    QJsonDocument updatedDoc(deviceObj);
    JsonHandler::saveJson(updatedDoc);
    DatabaseConnection& db = DatabaseConnection::getInstance();
    QSqlQuery query(db.getConnection());
    QString addColumnQuery = QString("ALTER TABLE %1 ADD COLUMN %2 TEXT").arg(deviceName, itemName);

    if (!query.exec(addColumnQuery)) {
        qDebug() << "Failed to add column:" << query.lastError().text();
    } else {
//        qDebug() << "Column added successfully:" << itemName << "to table:" << deviceName;
    }
}
void ItemHandler::addOptions(QString deviceName , QString itemName , QString optionName){
    QJsonArray itemArr = loadedObj[deviceName].toArray();
    QStringList tempstr;
    QJsonArray newArr;
    bool iscorrect =false;
    int i =0;
    while(iscorrect == false){
        if (itemArr[i].toObject().begin().key()==itemName){
            newArr = itemArr[i].toObject().begin().value().toArray();
            iscorrect = true;
        }
        i+=1;
    }
    newArr.append(optionName);
    QJsonObject updatedItemObj = itemArr[i - 1].toObject(); // Use i-1 because i was incremented after the last match
    updatedItemObj[itemName] = newArr;
    itemArr[i - 1] = updatedItemObj;
    loadedObj[deviceName] = itemArr;
    QJsonDocument updatedDoc(loadedObj);
    JsonHandler::saveJson(updatedDoc);
}

void ItemHandler::insertDataIntoTable(const QString& tableName, const QStringList& columnNames, const QVariantList& dataValues) {
    DatabaseConnection& db = DatabaseConnection::getInstance();



    // Construct the SQL query for inserting data
    QStringList placeholders;
    for (int i = 0; i < dataValues.size(); ++i) {
        placeholders << "?"; // Use placeholders for prepared statement
    }

    QString insertQuery = QString("INSERT INTO %1 (%2) VALUES (%3)")
                          .arg(tableName)
                          .arg(columnNames.join(", "))
                          .arg(placeholders.join(", "));
    QSqlQuery query(db.getConnection());


    query.prepare(insertQuery);
    for (int i = 0; i < dataValues.size(); ++i) {
        query.bindValue(i, dataValues[i]);
    }
    if (!query.exec()) {
        qDebug() << "Failed to insert data:" << query.lastError().text();
    } else {
//        qDebug() << "Data inserted successfully into table:" << tableName;
    }
}

void ItemHandler::addNewInfoDevice(QString deviceName, QString deviceAbr) {
    QJsonArray devicesArray = loadedInfoObj["devices"].toArray();
    for (const QJsonValue &device : devicesArray) {
        if (device.toObject().contains(deviceName)) {
            qDebug() << "Device already exists:" << deviceName;
            return;
        }
    }
    QJsonObject newDeviceObj;
    QJsonArray emptyBelongings;
    newDeviceObj["belongings"] = emptyBelongings;

    QJsonArray newDeviceEntry;
    newDeviceEntry.append(newDeviceObj);
    newDeviceEntry.append(deviceAbr);

    QJsonObject deviceObject;
    deviceObject[deviceName] = newDeviceEntry;

    devicesArray.append(deviceObject);

    loadedInfoObj["devices"] = devicesArray;
    QJsonDocument somedoc(loadedInfoObj);

    JsonHandler::saveInfoJson(somedoc);

//    qDebug() << "Added new device:" << deviceName << "with abbreviation:" << deviceAbr;
}


QStringList ItemHandler::readLetters() {
    QStringList res = {};
    QJsonArray deviceArr = loadedInfoObj["devices"].toArray(); // Assuming loadedInfoObj is a QJsonObject
    QStringList objNames;
    QStringList allDevices ={};
    for (int i=0;i<deviceArr.size();i++){
        objNames = deviceArr[i].toObject().keys();
        res.append(deviceArr[i].toObject().value(objNames[0]).toArray()[1].toString());
    }
//    qDebug() << "Whole letters:" << res;
    return res;
}

