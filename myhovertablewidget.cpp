#include "myhovertablewidget.h"
#include <QMouseEvent>
#include <QDebug>

myHoverTableWidget::myHoverTableWidget(QWidget *parent)
    : QTableWidget (parent)
    , mHoverRow(-1)
    , mHoverColumn(-1)
{
    setMouseTracking(true);
    setSelectionBehavior(SelectRows);
}


void myHoverTableWidget::mouseMoveEvent(QMouseEvent *event)
{
    QTableWidget::mouseMoveEvent(event);

    QModelIndex index = indexAt(event->pos());
    int oldHoverRow = mHoverRow;
    int oldHoverColumn = mHoverColumn;
    mHoverRow = index.row();
    mHoverColumn = index.column();

    if (selectionBehavior() == SelectRows && oldHoverRow != mHoverRow) {
        for (int i = 0; i < model()->columnCount(); ++i){
            update(model()->index(mHoverRow, i));
            update(model()->index(oldHoverRow, i));
        }
    }
    if (selectionBehavior() == SelectColumns && oldHoverColumn != mHoverColumn) {
        for (int i = 0; i < model()->rowCount(); ++i) {
            update(model()->index(i, mHoverColumn));
            update(model()->index(i, oldHoverColumn));       // �����в�������ˢ�£����������update�����Ǳ����
        }
    }
}

void myHoverTableWidget::wheelEvent(QWheelEvent *event)
{
    QTableWidget::wheelEvent(event);


    QModelIndex index = indexAt(event->pos());
    int oldHoverRow = mHoverRow;
    int oldHoverColumn = mHoverColumn;
    mHoverRow = index.row();
    mHoverColumn = index.column();

    if (selectionBehavior() == SelectRows && oldHoverRow != mHoverRow) {
        for (int i = 0; i < model()->columnCount(); ++i){
            update(model()->index(mHoverRow, i));
            update(model()->index(oldHoverRow, i));
        }
    }
    if (selectionBehavior() == SelectColumns && oldHoverColumn != mHoverColumn) {
        for (int i = 0; i < model()->rowCount(); ++i) {
            update(model()->index(i, mHoverColumn));
            update(model()->index(i, oldHoverColumn));       // �����в�������ˢ�£����������update�����Ǳ����
        }
    }
}

void myHoverTableWidget::leaveEvent(QEvent *event)
{
    QTableWidget::leaveEvent(event);

    mHoverRow = -1;
    mHoverColumn = -1;
}
