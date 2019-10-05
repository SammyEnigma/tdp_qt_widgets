#ifndef tp_qt_widgets_ProgressBar_h
#define tp_qt_widgets_ProgressBar_h

#include "tp_qt_widgets/Globals.h"

#include <QProgressBar>

namespace tp_qt_utils
{
class Progress;
}

namespace tp_qt_widgets
{

//##################################################################################################
//! Used for displaying the progress of a task.
/*!
This is a progress bar that automatically updates when the tp_qt_utils::Progress class is changed.
*/
class TP_QT_WIDGETS_SHARED_EXPORT ProgressBar: public QProgressBar
{
  Q_OBJECT
public:
  //################################################################################################
  ProgressBar(tp_qt_utils::Progress* progress, QWidget* parent=nullptr);

  //################################################################################################
  virtual ~ProgressBar();

private slots:
  //################################################################################################
  void progressChanged();

private:
  struct Private;
  Private* d;
  friend struct Private;
};

}

#endif