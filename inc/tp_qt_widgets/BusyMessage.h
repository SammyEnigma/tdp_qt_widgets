#ifndef tp_qt_widgets_BusyMessage_h
#define tp_qt_widgets_BusyMessage_h

#include "tp_qt_widgets/Globals.h"
#include "tp_qt_widgets/Animation.h"

#include <QFrame>

namespace tp_qt_utils
{
class Progress;
}

namespace tp_qt_widgets
{
//################################################################################################
typedef void (*TaskCallback)(tp_qt_utils::Progress* progress, void* opaque);

//##################################################################################################
struct BusyMessageConfiguration
{
  TaskCallback taskCallback;
  void* opaque;

  Animation animation;
  int fps;

  bool showProgress;

  BusyMessageConfiguration():
    taskCallback(nullptr),
    opaque(nullptr),
    fps(12),
    showProgress(true)
  {

  }
};

//##################################################################################################
//! Performs a task while displaying a busy screen
/*!

*/
class TP_QT_WIDGETS_SHARED_EXPORT BusyMessage: public QFrame
{
  Q_OBJECT
  TP_DQ;
public:
  //################################################################################################
  //! Construct the widget but dont start the task
  /*!
  This widget places itself on top of its parent and displays a busy message while it waits for a
  task to be processes. The task will not be started untill exec() is called.

  \param configuration - Contains details of the task to perform.
  \param parent - This is the widget that this will be placed on top of.
  */
  BusyMessage(const BusyMessageConfiguration& configuration, QWidget* parent=nullptr);

  //################################################################################################
  virtual ~BusyMessage();

  //################################################################################################
  //! A helper method that performs the task and blocks untill it is finished.
  static void performTask(const BusyMessageConfiguration& configuration, QWidget* parent=nullptr);

  //################################################################################################
  //! Call this to start the task.
  /*!
  This will start the task in a thread and block untill that task is completed.
  */
  void exec();
};

}

#endif
