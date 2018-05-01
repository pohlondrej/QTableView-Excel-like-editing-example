#ifndef EXAMPLEVIEW_H
#define EXAMPLEVIEW_H

#include <QTableView>
#include <QKeyEvent>

class ExampleView : public QTableView
{
public:
    ExampleView(QWidget *pParent = Q_NULLPTR) : QTableView(pParent) {}

private:
    void keyPressEvent(QKeyEvent *pEvent) override
    {
        if (pEvent->key() == Qt::Key_Return)
        {
            // we captured the Enter key press, now we need to move to the next row
            qint32 nNextRow = currentIndex().row() + 1;
            if (nNextRow + 1 > model()->rowCount(currentIndex()))
            {
                // we are all the way down, we can't go any further
                nNextRow = nNextRow - 1;
            }

            // now it's time to determine action
            if (state() == QAbstractItemView::EditingState)
            {
                // if we are editing, confirm and move to the row below
                QModelIndex oNextIndex = model()->index(nNextRow, currentIndex().column());
                setCurrentIndex(oNextIndex);
                selectionModel()->select(oNextIndex, QItemSelectionModel::ClearAndSelect);
            }
            else
            {
                // if we're not editing, start editing
                edit(currentIndex());
            }
        }
        else
        {
            // any other key was pressed
            QAbstractItemView::keyPressEvent(pEvent);
        }
    }
};

#endif // EXAMPLEVIEW_H
