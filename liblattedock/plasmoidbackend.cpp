#include "plasmoidbackend.h"

#include "../app/config-latte.h"
#include "worker.h"

namespace Latte {


PlasmoidBackend::PlasmoidBackend(QObject *parent)
    : QObject(parent)
{
    Worker *worker = new Worker(this);
    worker->moveToThread(&workerThread);
    connect(&workerThread, &QThread::finished, worker, &QObject::deleteLater);
    connect(this, &PlasmoidBackend::operate, worker, &Worker::newInstanceThread);
    workerThread.start();
}

PlasmoidBackend::~PlasmoidBackend()
{
    workerThread.quit();
    workerThread.wait();
}

void PlasmoidBackend::newInstance(QString filepath)
{
    const QString f1(filepath);
    emit operate(f1);
}

}
