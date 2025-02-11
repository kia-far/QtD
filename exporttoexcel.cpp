#include "exporttoexcel.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QAbstractItemModel>
#include "xlsxdocument.h"

ExportExcel::ExportExcel(QObject *parent) : QObject(parent) {}

void ExportExcel::exportToXlsx(QTableView *tableView) {
    // Get the model from the table view

    QAbstractItemModel *model = tableView->model();
    if(model->rowCount()==0){
        emit loadEmpty();
        return;
    }
    if (!model) {
        loadEmpty();
        emit exportError("No model found in the table view.");
        return;
    }
    // Get file path to save the Excel file
    QString filePath = getSaveFilePath();
    if (filePath.isEmpty()) {
        emit exportError("No file selected for export.");
        return;
    }

    // Create an xlsx document
    QXlsx::Document xlsx;

    // Write headers to the first row
    for (int col = 0; col < model->columnCount(); ++col) {
        QString headerText = model->headerData(col, Qt::Horizontal).toString();
        xlsx.write(1, col + 1, headerText); // Headers in the first row
    }

    // Write data rows
    for (int row = 0; row < model->rowCount(); ++row) {
        for (int col = 0; col < model->columnCount(); ++col) {
            QVariant cellData = model->data(model->index(row, col));
            xlsx.write(row + 2, col + 1, cellData); // Data starts from the second row
        }
    }

    // Save the document and check success
    if (xlsx.saveAs(filePath)) {
        emit exportSuccess(filePath);
        QMessageBox::information(nullptr, "Export", "Data exported successfully to " + filePath);
    } else {
        emit exportError("Failed to save the file.");
        QMessageBox::warning(nullptr, "Export", "Failed to save the file.");
    }
}
QList<QVariant> ExportExcel::getRowData(QTableView *tableView, int row) {
    QList<QVariant> rowData;
    QAbstractItemModel *model = tableView->model();

    // Check if row is within valid bounds
    if (!model || row < 0 || row >= model->rowCount()) {
        emit exportError("Invalid row index.");
        emit loadEmpty();
        return rowData;  // Return empty if invalid
    }

    // Retrieve data from each column in the specified row
    for (int col = 0; col < model->columnCount(); ++col) {
        rowData.append(model->data(model->index(row, col)));
    }

    return rowData;
}
QString ExportExcel::getSaveFilePath() {
    // Show file dialog to get the desired file path for the Excel file
    return QFileDialog::getSaveFileName(nullptr, "Save as Excel", "", "Excel files (*.xlsx)");
}
