#ifndef tp_qt_widgets_BusyAnimationGenerator_h
#define tp_qt_widgets_BusyAnimationGenerator_h

#include "tp_qt_widgets/Globals.h"

#include <QImage>

namespace tp_qt_widgets
{

//##################################################################################################
//! An animation made up from key frames
/*!

*/
class TP_QT_WIDGETS_SHARED_EXPORT BusyAnimationGenerator
{
  TP_NONCOPYABLE(BusyAnimationGenerator);
  TP_DQ;
public:
  //################################################################################################
  BusyAnimationGenerator();

  //################################################################################################
  virtual ~BusyAnimationGenerator();

  //################################################################################################
  QImage generateImage(int size) const;

  //################################################################################################
  void setColor(const QColor& color);

  //################################################################################################
  //0 -> 1
  void setMaxAngle(float maxAngle);

  //################################################################################################
  //0 -> 1
  void setLineWidth(float lineWidth);

  //################################################################################################
  void setClockwise(bool clockwise);

  //################################################################################################
  void setRepeat(int repeat);
};

}

#endif
