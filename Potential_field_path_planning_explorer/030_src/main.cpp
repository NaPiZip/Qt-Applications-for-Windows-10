#include "mainwindow.h"
#include <QtWidgets>


int main(int argc, char *argv[])
{    
    QApplication a(argc, argv);
    QWidget window;

    QLabel *queryLabel = new QLabel(QCoreApplication::translate("windowlayout","Query:"));
    QLineEdit *queryEdit = new QLineEdit();
    QTableView *resultView = new QTableView();


    QHBoxLayout *queryLayout = new QHBoxLayout();
    queryLayout->addWidget(queryLabel);
    queryLayout->addWidget(queryEdit);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(queryLayout);
    mainLayout->addWidget(resultView);

    window.setLayout(mainLayout);

    window.setWindowTitle(QCoreApplication::translate("windowlayout","Title"));
    window.show();
    return a.exec();

}
