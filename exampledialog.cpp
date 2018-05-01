#include "exampledialog.h"

#include <QtWidgets>

ExampleDialog::ExampleDialog(QWidget *parent)
    : QDialog(parent)
{
    m_pExampleModel.reset(new ExampleModel(this));
    QAbstractTableModel *pTableModel = dynamic_cast<QAbstractTableModel*>(m_pExampleModel.data());

    m_pExampleView = new ExampleView(this);
    m_pExampleView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    m_pExampleView->setModel(pTableModel);

    m_pVBoxLayout = new QVBoxLayout(this);
    m_pVBoxLayout->addWidget(m_pExampleView);
}

ExampleDialog::~ExampleDialog()
{

}
