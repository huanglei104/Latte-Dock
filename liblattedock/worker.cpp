#include "worker.h"

#include <QApplication>
#include <QDesktopWidget>

#include <KRun>
#include <KStartupInfo>

#if HAVE_X11
    #include <QX11Info>
    #include <KWindowSystem>
#endif

Worker::Worker(QObject *parent)
    : QObject(parent)
{
}

Worker::~Worker()
{
}

void Worker::newInstanceThread(const QString &filepath)
{
    const QUrl url(filepath);

    quint32 timeStamp = 0;

#if HAVE_X11

    if (KWindowSystem::isPlatformX11()) {
        timeStamp = QX11Info::appUserTime();
    }

#endif

    new KRun(url, 0, false, KStartupInfo::createNewStartupIdForTimestamp(timeStamp));
}
