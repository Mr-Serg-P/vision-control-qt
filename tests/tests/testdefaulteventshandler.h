#ifndef TEST_DEFAULTEVENTSHANDLER_H
#define TEST_DEFAULTEVENTSHANDLER_H

#include <QObject>

class Test_DefaultEventsHandler : public QObject
{
  Q_OBJECT
public:
  explicit Test_DefaultEventsHandler(QObject *parent = nullptr);

signals:

public slots:
};

#endif // TEST_DEFAULTEVENTSHANDLER_H
