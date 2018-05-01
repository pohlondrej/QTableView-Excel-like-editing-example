#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include "examplemodel.h"
#include "exampleview.h"

QT_BEGIN_NAMESPACE
class QVBoxLayout;
QT_END_NAMESPACE

class ExampleDialog : public QDialog
{
    Q_OBJECT

public:
    ExampleDialog(QWidget *parent = 0);
    ~ExampleDialog();

    QVBoxLayout *m_pVBoxLayout;
    ExampleView *m_pExampleView;
    QSharedPointer<ExampleModel> m_pExampleModel;
};

#endif // DIALOG_H
