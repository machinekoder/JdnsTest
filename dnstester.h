#ifndef DNSTESTER_H
#define DNSTESTER_H

#include <QObject>
#include <qjdns.h>

class DnsTester : public QObject
{
    Q_OBJECT
public:
    explicit DnsTester(QObject *parent = 0);
    ~DnsTester();

signals:

public slots:

private:
    QJDns *m_jdns;

    void debugRecord(const QJDns::Record &record);

private slots:
    void resultsReady(int id, const QJDns::Response &results);
    void published(int id);
    void error(int id, QJDns::Error e);
    void shutdownFinished();
    void debugLinesReady();
};

#endif // DNSTESTER_H
