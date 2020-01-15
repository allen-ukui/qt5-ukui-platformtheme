#ifndef UKUITABWIDGETANIMATORPLUGINIFACE_H
#define UKUITABWIDGETANIMATORPLUGINIFACE_H

#include <QString>
#include "animator-plugin-iface.h"
#include "ukui-tabwidget-animator-iface.h"

#define UKUITabWidgetAnimatorPluginInterface_iid "org.ukui.style.animatons.TabWidgetPluginInterface"

/*!
 * \brief The UKUITabWidgetAnimatorPluginIface class
 * \details
 * This class is used to create a tabwidget animator instace.
 *
 * UKUI Animation's frameworks is desgined to be extensiable.
 * And this interface is an entry of plugin.
 *
 * \see UKUITabWidgetAnimatorIface
 */
class UKUITabWidgetAnimatorPluginIface : public UKUIAnimatorPluginIface
{
public:
    virtual ~UKUITabWidgetAnimatorPluginIface() {}

    /*!
     * \brief key
     * \return
     * A key word of plugin, such as "slide".
     */
    virtual const QString key() = 0;

    /*!
     * \brief description
     * \return
     * A description for animator. For example, "Animator for do a horizon slide
     * for tab widget."
     */
    virtual const QString description() = 0;

    /*!
     * \brief createAnimator
     * \return
     * an animator instance, for example a UKUI::TabWidget::DefaultSlideAnimator.
     */
    virtual UKUITabWidgetAnimatorIface *createAnimator() = 0;
};

Q_DECLARE_INTERFACE(UKUITabWidgetAnimatorPluginIface, UKUITabWidgetAnimatorPluginInterface_iid)

#endif // UKUITABWIDGETANIMATORPLUGINIFACE_H