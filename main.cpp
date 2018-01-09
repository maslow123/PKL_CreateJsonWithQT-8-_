#include <QApplication>
#include <QTreeView>
#include <QFile>
#include <string>
#include "qjsonmodel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTreeView * view   = new QTreeView;
    QJsonModel * model = new QJsonModel;

    view->setModel(model);

    std::string json = R"({
                       "Nama_Depan": "Fadhly",
                       "Nama_Belakang": "NR",
                       "Usia": 16,
                       "address":
                       {
                           "Kota": "Bogor",
                           "Kecamatan": "Cileungsi",
                           "Kelurahan": "Cipeucang",
                           "KodePos": "16820"
                       },
                       "No.Telepon":"087775758983",
                       "makanan fav":[
                            "Ketoprak",
                            "Nasi Uduk",
                            "Mie Goreng"
                           ]
                       })";



    model->loadJson(QByteArray::fromStdString(json));
    view->show();

    return a.exec();
}
