/*
 * Qt5-UKUI's Library
 *
 * Copyright (C) 2020, Tianjin KYLIN Information Technology Co., Ltd.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this library.  If not, see <https://www.gnu.org/licenses/>.
 *
 * Authors: Yue Lan <lanyue@kylinos.cn>
 *
 */

#ifndef BLURHELPER_H
#define BLURHELPER_H

#include <QObject>
#include <QTimer>

class BlurHelper : public QObject
{
    Q_OBJECT
public:
    explicit BlurHelper(QObject *parent = nullptr);

    bool eventFilter(QObject *obj, QEvent *e);
    void registerWidget(QWidget *widget);
    void unregisterWidget(QWidget *widget);

    bool isApplicationInBlackList();
    const QStringList blackList();

    bool shouldSkip(QWidget *w);

Q_SIGNALS:

public Q_SLOTS:
    void onBlurEnableChanged(bool enable);
    void onWidgetDestroyed(QWidget *widget);
    void delayUpdate(QWidget *w, bool updateBlurRegionOnly = false);

protected:
    /*!
     * \brief confirmBlurEnableDelay
     * \note
     * some application start before kwin, such as peony-qt-desktop.
     * we have to ensure that the blurEnable protocol not effected by
     * the case. Delay a while and check it again is a normally way to
     * confirm.
     */
    void confirmBlurEnableDelay();

private:
    QList<QWidget *> m_blur_widgets;

    QList<QWidget *> m_update_list;
    QTimer m_timer;

    bool m_blur_enable = true;
};

#endif // BLURHELPER_H
