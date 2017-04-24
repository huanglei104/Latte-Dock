
#include <QObject>

class Worker : public QObject {
    Q_OBJECT

public:
    Worker(QObject *parent = 0);
    ~Worker();

public slots:
    void newInstanceThread(const QString &filepath);

signals:
    void resultReady(const QString &result);
};
