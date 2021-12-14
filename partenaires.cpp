#include "partenaires.h"

partenaires::partenaires()
{
    IDENTIFIANT=0;
     NOM="";
     PERIODE_P="";
     MAIL="";
     NUM_TEL=0;
     NB_INTERACTION=0;
}
partenaires::partenaires (QString NOM, int IDENTIFIANT ,QString PERIODE_P, int NUM_TEL, QString MAIL ,int NB_INTERACTION )
{
    this->NOM=NOM;
    this->IDENTIFIANT=IDENTIFIANT;
    this->PERIODE_P=PERIODE_P;
    this->NUM_TEL=NUM_TEL;
    this->MAIL=MAIL;
    this->NB_INTERACTION=NB_INTERACTION;






}
bool partenaires::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(IDENTIFIANT);
    QString res1=QString::number(NUM_TEL);
    query.prepare("INSERT INTO PARTENAIRE (NOM,IDENTIFIANT,PERIODE_P,NUM_TEL,MAIL,NB_INTERACTION) "
                  "VALUES (:NOM,:IDENTIFIANT,:PERIODE_P,:NUM_TEL,:MAIL,:NB_INTERACTION)");
    query.bindValue(":NOM", NOM);
    query.bindValue(":IDENTIFIANT", res);
    query.bindValue(":PERIODE_P", PERIODE_P);
    query.bindValue(":NUM_TEL",res1);
    query.bindValue(":MAIL", MAIL);
    query.bindValue(":NB_INTERACTION", NB_INTERACTION);
    return query.exec();
}

bool partenaires::supprimer(int identifiant)
{
    QSqlQuery qry;
    qry.prepare("Delete from partenaire where IDENTIFIANT = :IDENTIFIANT");
    qry.bindValue(":IDENTIFIANT",identifiant);
    return qry.exec();
}



QSqlQueryModel *partenaires::afficher()
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM partenaire");
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("IDENTIFIANT"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PERIODE_P"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("NUM_TEL"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("MAIL"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("NB_INTERACTION"));
    return model;
}
QSqlQueryModel *partenaires::rechercher(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from partenaire where upper(IDENTIFIANT) LIKE upper ('%"+rech+"%') or upper(NOM) LIKE upper ('%"+rech+"%') or upper(NUM_TEL) LIKE upper ('%"+rech+"%')");


    return model;

}

QSqlQueryModel *partenaires::trier_id(){
    QSqlQuery *qry=new QSqlQuery();
    QSqlQueryModel *model=new QSqlQueryModel();
    qry->prepare("select * from partenaire order by IDENTIFIANT ASC");
    qry->exec();
    model->setQuery(*qry);
    return model;
}
QSqlQueryModel *partenaires::trier_nom(){
    QSqlQuery *qry=new QSqlQuery();
    QSqlQueryModel *model=new QSqlQueryModel();
    qry->prepare("select * from partenaire order by NOM ASC");
    qry->exec();
    model->setQuery(*qry);
    return model;
}

void partenaires::imprimerpdf(QTableView *table)
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append("partenaires.pdf"); }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);
    QAbstractItemModel *model =  table->model();
    QTextDocument doc;
    QSqlQuery q;
    q.prepare("SELECT * FROM partenaire ");
    q.exec();
    QString pdf="<br> <img src='C:/Users/My-PC/Downloads/image.png' height='42' width='144'/> <h1  style='color:red'>LISTE DES PARTENAIRES  <br></h1>\n <br> <table>  <tr>  <th> NOM </th> <th> IDENTIFIANT </th> <th> PERIODE_P </th> <th> NUM_TEL </th> <th> MAIL </th> <th> NB_INTERACTION </th>  </tr>" ;


    while ( q.next()) {

        pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+"    </td>   <td>   " + q.value(1).toString() +"</td>   <td>" +q.value(2).toString() +"  "" " "</td>   <td>"+q.value(3).toString()+"</td>    <td>"+q.value(4).toString()+" </td>" "    </td>   <td>   " + q.value(5).toString() +" ""</td>" "<td>"+q.value(6).toString()+" </td>" ;

    }
    doc.setHtml(pdf);
    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
    doc.print(&printer); }

void partenaires::exporter(QTableView *table)
{
    QString filters("CSV files (*.csv);;All files (*.*)");
    QString defaultFilter("CSV files (*.csv)");
    QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                                    filters, &defaultFilter);
    QFile file(fileName);
    QAbstractItemModel *model =  table->model();
    if (file.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream data(&file);
        QStringList strList;
        for (int i = 0; i < model->columnCount(); i++) {
            if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
            else
                strList.append("");
        }
        data << strList.join(";") << "\n";
        for (int i = 0; i < model->rowCount(); i++) {
            strList.clear();
            for (int j = 0; j < model->columnCount(); j++) {

                if (model->data(model->index(i, j)).toString().length() > 0)
                    strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                else
                    strList.append("");
            }
            data << strList.join(";") + "\n";
        }
        file.close();
    }
}
QVector<double> partenaires::getData()
{
    QVector<double>testData;

    QSqlQuery query("select AVG(NB_INTERACTION)from PARTENAIRE where PERIODE_P='1'");
    while(query.next()){
        int erreur=0;
        int e3=0;
        int e4=0;
        int e5=0;
        int errerE=query.value(0).toInt();
        QSqlQuery query2("select AVG(NB_INTERACTION)from PARTENAIRE where PERIODE_P='2'");
        while(query2.next()){
            erreur=query2.value(0).toInt();
            QSqlQuery query3("select AVG(NB_INTERACTION)from PARTENAIRE where PERIODE_P='3'");
            while (query3.next())
            { e3=query3.value(0).toInt();
                QSqlQuery query4("select AVG(NB_INTERACTION)from PARTENAIRE where PERIODE_P='4'");
                while (query4.next()) {
                    e4=query4.value(0).toInt();
                    QSqlQuery query5("select AVG(NB_INTERACTION)from PARTENAIRE where PERIODE_P='5'");
                    while (query5.next())
                    {e5=query5.value(0).toInt();
                    break;}
                    break;}

                break; }
            break;}
        testData<< errerE << erreur << e3 << e4 <<e5;
        break;}

    return testData;
}

int partenaires::calculInter(int id)
{
    QSqlQuery statq;
    int totalInter=0;
    int inter;
    statq.prepare("SELECT NB_INTERACTION FROM PARTENAIRE WHERE IDENTIFIANT=:id");
    statq.bindValue(":id",id);
    statq.exec();
    while (statq.next())
    {
        inter = statq.value(0).toInt();
        totalInter+=inter;
    }
    return totalInter;
}

