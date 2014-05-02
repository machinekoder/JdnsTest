#include "dnstester.h"

DnsTester::DnsTester(QObject *parent) :
    QObject(parent)
{

    m_jdns = new QJDns(this);

    connect(m_jdns, SIGNAL(resultsReady(int,QJDns::Response)),
            this, SLOT(resultsReady(int,QJDns::Response)));

    m_jdns->init(QJDns::Multicast, QHostAddress::Any);

    m_jdns->queryStart("_sane-port._tcp.local", QJDns::Ptr);
}

void DnsTester::debugRecord(const QJDns::Record &record)
{
    qDebug() << "Address:" << record.address.toString();
    qDebug() << "Cpu:" << record.cpu;
    qDebug() << "OS:" << record.os;
    qDebug() << "Name:" << record.name;
    qDebug() << "Port:" << record.port;
    qDebug() << "Texts:" << record.texts;
    qDebug() << "Type:" << record.type;
    qDebug() << "Priority:" << record.priority;
    qDebug() << "Owner:" << record.owner;
    qDebug() << "Have known:" << record.haveKnown;
    qDebug() << "RData:" << record.rdata;
    qDebug() << "TTL:" << record.ttl;
    qDebug() << "Weight:" << record.weight;
}

void DnsTester::resultsReady(int id, const QJDns::Response &results)
{
    qDebug() << "result" << id;

    qDebug() << "------------------ Records --------------------";
    foreach(QJDns::Record record, results.answerRecords)
    {
        debugRecord(record);
    }

    qDebug() << "--------------- Authority Records --------------";
    foreach(QJDns::Record record, results.authorityRecords)
    {
        debugRecord(record);
    }

    qDebug() << "-------------- Additional Records --------------";
    foreach(QJDns::Record record, results.additionalRecords)
    {
        debugRecord(record);
    }
}
