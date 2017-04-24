/*
*  Copyright 2016  Smith AR <audoban@openmailbox.org>
*                  Michail Vourlakos <mvourlakos@gmail.com>
*
*  This file is part of Latte-Dock and is a Fork of PlasmaCore::IconItem
*
*  Latte-Dock is free software; you can redistribute it and/or
*  modify it under the terms of the GNU General Public License as
*  published by the Free Software Foundation; either version 2 of
*  the License, or (at your option) any later version.
*
*  Latte-Dock is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef PLASMOIDBACKEND_H
#define PLASMOIDBACKEND_H

#include <QObject>
#include <QThread>

namespace Latte {
class PlasmoidBackend : public QObject {
    Q_OBJECT

    QThread workerThread;
public:
    PlasmoidBackend(QObject *parent = 0);
    ~PlasmoidBackend();

public slots:
    Q_INVOKABLE void newInstance(QString filepath);

signals:
    void operate(const QString &);
};

}

#endif
