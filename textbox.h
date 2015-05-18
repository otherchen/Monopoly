#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <QtGui>
#include <QDockWidget>
#include <QPlainTextEdit>


class TextBox : public QDockWidget {
  Q_OBJECT

  private:
  QPlainTextEdit textBox;

  public:
  TextBox();
};

#endif
