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

#ifndef BOXANIMATIONHELPER_H
#define BOXANIMATIONHELPER_H

#include <QObject>
#include "animation-helper.h"
#include "animator-iface.h"
#include "box-animator.h"

class BoxAnimationHelper : public AnimationHelper
{
    Q_OBJECT
public:
    BoxAnimationHelper(QObject *parent = nullptr);
    bool registerWidget(QWidget *w);
    bool unregisterWidget(QWidget *w);

    AnimatorIface *animator(const QWidget *w);

Q_SIGNALS:

public Q_SLOTS:
};

#endif // BOXANIMATIONHELPER_H
