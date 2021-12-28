#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QTableWidget>


class myHoverTableWidget : public QTableWidget
{
    Q_OBJECT
public:
    myHoverTableWidget(QWidget *parent = nullptr);

    QModelIndex hoverIndex() const { return model()->index(mHoverRow, mHoverColumn); }

    // QWidget interface
protected:
    virtual void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    virtual void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE;
    virtual void leaveEvent(QEvent *event) Q_DECL_OVERRIDE;

private:
    int mHoverRow, mHoverColumn;
};

#endif // TABLEVIEW_H
