#ifndef EXAMPLEMODEL_H
#define EXAMPLEMODEL_H

#include <QAbstractTableModel>

class ExampleModel : public QAbstractTableModel
{
public:
    ExampleModel(QObject * pParent = Q_NULLPTR) : QAbstractTableModel(pParent)
    {
        // pre-populate the model (for demonstration purpose only)
        QStringList arrExampleRow1;
        arrExampleRow1.append("A1");
        arrExampleRow1.append("B1");
        arrExampleRow1.append("C1");
        QStringList arrExampleRow2;
        arrExampleRow2.append("A2");
        arrExampleRow2.append("B2");
        arrExampleRow2.append("C2");
        QStringList arrExampleRow3;
        arrExampleRow3.append("A3");
        arrExampleRow3.append("B3");
        arrExampleRow3.append("C3");
        m_arrData.append(arrExampleRow1);
        m_arrData.append(arrExampleRow2);
        m_arrData.append(arrExampleRow3);
    }

    int rowCount(const QModelIndex &) const override
    {
        return 3;
    }

    int columnCount(const QModelIndex &) const override
    {
        return 3;
    }

    QVariant data(const QModelIndex &index, int role) const override
    {
        if (role != Qt::DisplayRole && role != Qt::EditRole)
        {
            return QVariant();
        }
        return m_arrData[index.row()][index.column()];
    }

    QVariant headerData(int nSection, Qt::Orientation eOrientation, int nRole) const override
    {
        if (eOrientation != Qt::Horizontal || nRole != Qt::DisplayRole)
        {
            return QVariant();
        }
        switch (nSection)
        {
        case 0:
            return "Section1";
        case 1:
            return "Section2";
        case 2:
            return "Section3";
        default:
            return QVariant();
        }
    }

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override
    {
        if (role == Qt::EditRole)
        {
            m_arrData[index.row()][index.column()] = value.toString();
        }
        return true;
    }

    Qt::ItemFlags flags(const QModelIndex &index) const
    {
        if (!index.isValid())
        {
            return Qt::ItemIsEnabled;
        }

        return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
    }

private:
    QList<QStringList> m_arrData;
};

#endif // EXAMPLEMODEL_H
