#include "dnstester.h"

DnsTester::DnsTester(QObject *parent) :
    QObject(parent)
{

    m_jdns = new QJDns(this);

    connect(m_jdns, SIGNAL(resultsReady(int,QJDns::Response)),
            this, SLOT(resultsReady(int,QJDns::Response)));

    m_jdns->init(QJDns::Multicast, QHostAddress::Any);

    m_jdns->queryStart("_sane-port._tcp", QJDns::Any);
}

void DnsTester::resultsReady(int id, const QJDns::Response &results)
{
    qDebug() << "result" << id;
}
